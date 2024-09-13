#include "prenotationWindow.h"
#include <QMessageBox>
#include <sstream>
#include <iomanip>

PrenotationWindow::PrenotationWindow(QWidget *parent)
    : QDialog(parent) {

    departureEdit = new QLineEdit(this);
    departureLabel = new QLabel("Departure", this);

    arrivalEdit = new QLineEdit(this);
    arrivalLabel = new QLabel("Arrival", this);

    dateEdit = new QLineEdit(this);
    dateLabel = new QLabel("Date", this);

    timeEdit = new QLineEdit(this);
    timeLabel = new QLabel("Time", this);
    
    prenotationButton = new QPushButton("Prenotation", this);
    connect(prenotationButton, &QPushButton::clicked, this, &PrenotationWindow::makePrenotation);

    returnButton = new QPushButton("Back", this);
    connect(returnButton, &QPushButton::clicked, this, &PrenotationWindow::returnToVisualizePrenotation);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(departureLabel);
    layout->addWidget(departureEdit);
    layout->addWidget(arrivalLabel);
    layout->addWidget(arrivalEdit);
    layout->addWidget(dateLabel);
    layout->addWidget(dateEdit);
    layout->addWidget(timeLabel);
    layout->addWidget(timeEdit);
    layout->addWidget(prenotationButton);
    layout->addWidget(returnButton); 

    setLayout(layout); 

    setWindowTitle("Prenotation Window");
    setFixedSize(800, 600);
}

bool PrenotationWindow::makePrenotation() {
    QString departure = departureEdit->text();
    QString arrival = arrivalEdit->text();
    QString date = dateEdit->text();
    QString time = timeEdit->text();

    auto toStdString = [](const QString& qstr) {
        return qstr.toStdString();
    };

    std::string departureStr = toStdString(departure);
    std::string arrivalStr = toStdString(arrival);
    std::string dateStr = toStdString(date);
    std::string timeStr = toStdString(time);

    // Create or open the SQLite database
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("prenotation.db");

    if (!QFile::exists("prenotation.db")) {
        qDebug() << "Database file doesn't exist";
        QMessageBox::critical(this, "Prenotation", "Database file does not exist.");
        return false;
    } else {
        qDebug() << "Database file exists";
    }

    if (!database.open()) {
        qDebug() << "Error opening database: " << database.lastError().text();
        QMessageBox::critical(this, "Prenotation", "Error opening database.");
        return false;
    } else {
        qDebug() << "Database opened successfully";
    }

    std::istringstream timeStream(timeStr);
    std::chrono::hours departureTime;
    timeStream >> departureTime;

    std::chrono::hours arrivalTime = departureTime + std::chrono::hours(2);

    std::istringstream dateStream(dateStr);
    std::chrono::year_month_day departureDate;
    dateStream >> std::chrono::parse("%F", departureDate);

    // Create Prenotation object
    Prenotation prenotation(
        departureStr,
        arrivalStr,
        departureDate,
        departureDate,  
        departureTime,
        arrivalTime,  
        currentUser
    );

    QSqlQuery query;
    int prenotationNumber = prenotation.getPrenotationNumber();
    int flightNumber = prenotation.getNumberFlight();
    query.prepare("INSERT INTO prenotation (departure, arrival, date, time, arrival_time, prenotationNumber, flightNumber, user) VALUES (:departure, :arrival, :date, :time, :arrival_time, :prenotationNumber, :flightNumber, :user)");
    query.bindValue(":departure", departure);
    query.bindValue(":arrival", arrival);
    query.bindValue(":date", date);
    query.bindValue(":time", time);
    query.bindValue(":arrival_time", arrivalTime.count()); 
    query.bindValue(":prenotationNumber", prenotationNumber);
    query.bindValue(":flightNumber", flightNumber);
    query.bindValue(":user", currentUser);

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        QMessageBox::critical(this, "Prenotation", "Error executing query.");
        database.close();
        return false;
    }

    database.close();
    QMessageBox::information(this, "Prenotation", "Prenotation successfully made");
    return true;
}

void PrenotationWindow::returnToVisualizePrenotation() {
    visualizePrenotation->show();
}
