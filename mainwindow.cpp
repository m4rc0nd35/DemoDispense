#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Demo Dispense"); // titulo
    setFixedSize(QSize(250,460));
    setFont(QFont("SansSerif", 9)); // fonte padrão da aplicação

    QPushButton *btReset = new QPushButton(this);
    btReset->setText("Reset");
    btReset->setGeometry(QRect(QPoint(50, 20), QSize(150, 50)));

    QPushButton *btPosiSensor = new QPushButton(this);
    btPosiSensor->setText("Posição Sensor");
    btPosiSensor->setGeometry(QRect(QPoint(50, 80), QSize(150, 50)));

    QPushButton *btPosiReady = new QPushButton(this);
    btPosiReady->setText("Posição leitura");
    btPosiReady->setGeometry(QRect(QPoint(50, 140), QSize(150, 50)));

    QPushButton *btPosiCapture = new QPushButton(this);
    btPosiCapture->setText("Capturar");
    btPosiCapture->setGeometry(QRect(QPoint(50, 200), QSize(150, 50)));

    QPushButton *btPosiPartial = new QPushButton(this);
    btPosiPartial->setText("Entraga parcial");
    btPosiPartial->setGeometry(QRect(QPoint(50, 260), QSize(150, 50)));

    QPushButton *btPosiTotal = new QPushButton(this);
    btPosiTotal->setText("Entraga total");
    btPosiTotal->setGeometry(QRect(QPoint(50, 320), QSize(150, 50)));

    QPushButton *btState = new QPushButton(this);
    btState->setText("Status da máquina");
    btState->setGeometry(QRect(QPoint(50, 380), QSize(150, 50)));
}

MainWindow::~MainWindow(){}

