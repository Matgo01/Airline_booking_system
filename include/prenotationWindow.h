#ifndef PRENOTATIONWINDOW_H
#define PRENOTATIONWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

#include "prenotation.h"
#include "visualizePrenotation.h"
#include "user.h"

class PrenotationWindow : public QDialog {
    Q_OBJECT

public:
    explicit PrenotationWindow(QWidget *parent = nullptr);
    ~PrenotationWindow();

private slots:
    void makePrenotation();
    void returnToVisualizePrenotation();

private:
    QLineEdit *departureEdit;
    QLabel *departureLabel;
    QLineEdit *arrivalEdit;
    QLabel *arrivalLabel;
    QLineEdit *dateEdit;
    QLabel *dateLabel;
    QLineEdit *timeEdit;
    QLabel *timeLabel;
    QPushButton *prenotationButton;  
    QSqlDatabase database;
    QPushButton *returnButton;
    VisualizePrenotation *visualizePrenotation;
};

#endif // PRENOTATIONWINDOW_H
