#include "visualizePrenotation.h"

VisualizePrenotation::VisualizePrenotation(QWidget *parent)
    : QDialog(parent) 
{
    prenotationNumberEdit = new QLineEdit(this);
    prenotationNumberEdit->setPlaceholderText("Prenotation Number"); 

    prenotationNumberLabel = new QLabel("Prenotation Number", this);

    visualizeButton = new QPushButton("Visualize", this);
    switchToBookingButton = new QPushButton("Go to Prenotation", this);

    prenotationWindow = new PrenotationWindow(this); 

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(prenotationNumberLabel);
    layout->addWidget(prenotationNumberEdit);
    layout->addWidget(visualizeButton);
    layout->addWidget(switchToBookingButton);

    tableView = new QTableView(this);
    layout->addWidget(tableView);

    connect(switchToBookingButton, &QPushButton::clicked, this, &VisualizePrenotation::switchToBookingWindow);
    connect(visualizeButton, &QPushButton::clicked, this, &VisualizePrenotation::visualizePrenotation);

    setLayout(layout); 

    setWindowTitle("Visualize Prenotation");
    setFixedSize(800, 600);
}

void VisualizePrenotation::visualizePrenotation() {
    QString prenotationNumber = prenotationNumberEdit->text();

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("prenotation.db");

    if (!QFile::exists("prenotation.db")) {
        qDebug() << "Database file doesn't exist";
        QMessageBox::critical(this, "Visualize Prenotation", "Database file does not exist.");
        return;
    }

    if (!database.open()) {
        qDebug() << "Error opening database: " << database.lastError().text();
        QMessageBox::critical(this, "Visualize Prenotation", "Error opening database.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM prenotations WHERE prenotationNumber = :number AND user = :user");
    query.bindValue(":number", prenotationNumber);
    query.bindValue(":user", QString::fromStdString(currentUser.getUsername()));

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        QMessageBox::critical(this, "Visualize Prenotation", "Error executing query.");
        return;
    }

    QSqlTableModel *model = new QSqlTableModel(this, database);
    model->setTable("prenotations");
    model->setFilter(QString("prenotationNumber = '%1' AND user = '%2'")
                     .arg(prenotationNumber)
                     .arg(QString::fromStdString(currentUser.getUsername())));
    model->select();

    tableView->setModel(model);
    tableView->resizeColumnsToContents();

    QMessageBox::information(this, "Visualize Prenotation", "Data successfully retrieved.");
}

void VisualizePrenotation::switchToBookingWindow() {
    prenotationWindow->show(); 
}
