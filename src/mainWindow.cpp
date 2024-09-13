#include "mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      stackedWidget(new QStackedWidget(this)),
      loginWindow(new Login(this)),
      registrationWindow(new Registration(this)),
      visualizePrenotation(new VisualizePrenotation(this)),
      registerButton(new QPushButton("Go to Registration", this)) {

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(stackedWidget);

    // Add windows to stackedWidget
    stackedWidget->addWidget(loginWindow);
    stackedWidget->addWidget(registrationWindow);
    stackedWidget->addWidget(visualizePrenotation);

    // Set up the register button
    registerButton->setFixedSize(200, 40);
    layout->addWidget(registerButton);

    // Connect the register button to show the registration window
    connect(registerButton, &QPushButton::clicked, this, &MainWindow::showRegistrationWindow);

    // Connect registration window signal to slot
    connect(registrationWindow, &Registration::registrationSuccessful, this, &MainWindow::handleRegistrationSuccessful);

    // Connect login window signal to slot
    connect(loginWindow, &Login::loginSuccessful, this, &MainWindow::handleLoginSuccessful);

    stackedWidget->setCurrentWidget(loginWindow);

    setWindowTitle("Main Window");
    setFixedSize(800, 600);
}

MainWindow::~MainWindow() {
    
}

void MainWindow::showRegistrationWindow() {
    stackedWidget->setCurrentWidget(registrationWindow);
}

void MainWindow::handleRegistrationSuccessful() {
    stackedWidget->setCurrentWidget(loginWindow);
}

void MainWindow::handleLoginSuccessful() {
    stackedWidget->setCurrentWidget(visualizePrenotation);
}
