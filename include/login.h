#ifndef LOGIN_H
#define LOGIN_H

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

#include "user.h"

class Login : public QDialog
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void LoginButton();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QPushButton *loginButton;
    QSqlDatabase database;
};

#endif // LOGIN_H
