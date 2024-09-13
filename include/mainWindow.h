#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "login.h"
#include "registration.h"
#include "visualizeprenotation.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showRegistrationWindow();
    void handleRegistrationSuccessful();
    void handleLoginSuccessful();

private:
    QStackedWidget *stackedWidget;
    Login *loginWindow;
    Registration *registrationWindow; 
    VisualizePrenotation *visualizePrenotation; 
    QPushButton *registerButton;
};

#endif // MAINWINDOW_H
