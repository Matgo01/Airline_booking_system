#include "registration.h"
#include <QMessageBox>

Registration::Registration(QWidget *parent) : QDialog(parent) {
    nameLabel = new QLabel("Name", this);
    nameEdit = new QLineEdit(this);

    surnameLabel = new QLabel("Surname", this);
    surnameEdit = new QLineEdit(this);

    emailLabel = new QLabel("Email", this);
    emailEdit = new QLineEdit(this);

    passwordLabel = new QLabel("Password", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    usernameLabel = new QLabel("Username", this);
    usernameEdit = new QLineEdit(this);

    ageLabel = new QLabel("Age", this);
    ageEdit = new QLineEdit(this);

    registerButton = new QPushButton("Register", this);
    connect(registerButton, &QPushButton::clicked, this, &Registration::registerUser);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);
    layout->addWidget(surnameLabel);
    layout->addWidget(surnameEdit);
    layout->addWidget(emailLabel);
    layout->addWidget(emailEdit);
    layout->addWidget(ageLabel);
    layout->addWidget(ageEdit);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    setLayout(layout);
    setWindowTitle("Register");
    setFixedSize(250, 150);
}

bool Registration::registerUser() {
    QString name = nameEdit->text();
    QString surname = surnameEdit->text();
    QString email = emailEdit->text();
    QString password = passwordEdit->text();
    QString username = usernameEdit->text();
    int age = ageEdit->text().toInt();

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("user_database.db");

    if (!QFile::exists("user_database.db")) {
        qDebug() << "Database file doesn't exist";
        QMessageBox::critical(this, "Registration", "Database file does not exist.");
        return false;
    }

    if (!database.open()) {
        qDebug() << "Error opening database: " << database.lastError().text();
        QMessageBox::critical(this, "Registration", "Error opening database.");
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (name, surname, email, password, username, age) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(surname);
    query.addBindValue(email);
    query.addBindValue(password);
    query.addBindValue(username);
    query.addBindValue(age);

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        QMessageBox::critical(this, "Registration", "Error executing query.");
        database.close();
        return false;
    }

    database.close();
    QMessageBox::information(this, "Registration", "Registration successful.");
    return true;
}
