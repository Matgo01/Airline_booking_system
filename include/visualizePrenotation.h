#ifndef VISUALIZEPRENOTATION_H
#define VISUALIZEPRENOTATION_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFile>
#include <QDebug>

#include "user.h"
#include "prenotationWindow.h"

class VisualizePrenotation : public QDialog {
    Q_OBJECT

public:
    explicit VisualizePrenotation(QWidget *parent = nullptr);
    ~VisualizePrenotation();

private slots:
    void visualizePrenotation();
    void switchToBookingWindow();

private:
    QLineEdit *prenotationNumberEdit;
    QLabel *prenotationNumberLabel;
    QPushButton *visualizeButton;
    QSqlDatabase database;
    QPushButton *switchToBookingButton;
    PrenotationWindow *prenotationWindow; // Fixed typo here
};

#endif
