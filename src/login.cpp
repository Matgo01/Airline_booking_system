#include "login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) : QDialog(parent) {
    usernameLabel = new QLabel("Username", this);
    usernameEdit = new QLineEdit(this);

    passwordLabel = new QLabel("Password", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);
    connect(loginButton, &QPushButton::clicked, this, &Login::login);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    setLayout(layout);
    setWindowTitle("Login");
    setFixedSize(250, 150);
}

// login
void Login::login() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Create or open the SQLite database
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("user_database.db");

    if (!QFile::exists("user_database.db")) {
        qDebug() << "Database file doesn't exist";
        QMessageBox::critical(this, "Login", "Database file does not exist.");
        return;
    } else {
        qDebug() << "Database file exists";
    }

    if (!database.open()) {
        qDebug() << "Error opening database: " << database.lastError().text();
        QMessageBox::critical(this, "Login", "Error opening database.");
        return;
    } else {
        qDebug() << "Database opened successfully";
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Query execution error: " << query.lastError().text();
        QMessageBox::critical(this, "Login", "Error executing query.");
        return;
    }

    if (query.next()) {
        qDebug() << "Login successful";
        
        QString name = query.value("name").toString();
        QString surname = query.value("surname").toString();
        int age = query.value("age").toInt();
        QString email = query.value("email").toString();

        User user(name, surname, age, username, password, email);

        currentUser = user;

        database.close();
        
        accept();  // Close dialog with success
    } else {
        QMessageBox::information(this, "Login", "Invalid username or password");
    }
}
