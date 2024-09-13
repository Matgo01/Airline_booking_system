#ifndef REGISTRATION_H
#define REGISTRATION_H

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

class Registration : public QDialog {
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    bool registerUser();

private:
    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;
    QLineEdit *emailEdit;
    QLineEdit *passwordEdit;
    QLineEdit *usernameEdit;
    QLineEdit *ageEdit;
    QPushButton *registerButton;
    QLabel *nameLabel;
    QLabel *surnameLabel;
    QLabel *emailLabel;
    QLabel *passwordLabel;
    QLabel *usernameLabel;
    QLabel *ageLabel;
    QSqlDatabase db;
};

#endif // REGISTRATION_H
