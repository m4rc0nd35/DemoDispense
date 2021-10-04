#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Demo Dispense"); // titulo
    setFixedSize(QSize(480,320));
    setFont(QFont("SansSerif", 25)); // fonte padrão da aplicação

    QGridLayout *grid = new QGridLayout(this);
    grid->setMargin(30);

    QLabel *lbUser = new QLabel(this);
    lbUser->setText("CPF:");
    grid->addWidget(lbUser);

    QLineEdit *username = new QLineEdit(this);
    username->setMaxLength(10);
    grid->addWidget(username);

    QLabel *lbPwd = new QLabel(this);
    lbPwd->setText("Senha:");
    grid->addWidget(lbPwd);

    QLineEdit *password = new QLineEdit(this);
    password->setMaxLength(10);
    grid->addWidget(password);

    QPushButton *btAuth = new QPushButton(this);
    btAuth->setText("Autenticar");
    grid->addWidget(btAuth);
}

MainWindow::~MainWindow()
{
}

