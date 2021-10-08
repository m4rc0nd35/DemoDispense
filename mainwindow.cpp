#include "mainwindow.h"

MainWindow::MainWindow(QObject *parent)
    : QObject(parent)
{
    Dispense *demo = new Dispense();
    demo->connectSerial();

    QMainWindow *w = new QMainWindow();

    w->setWindowTitle("Demo Dispense"); // titulo
    w->setFixedSize(QSize(250, 460));
    w->setFont(QFont("SansSerif", 9)); // fonte padrão da aplicação

    QPushButton *btReset = new QPushButton("&Reset", w);
    btReset->setGeometry(QRect(QPoint(50, 20), QSize(150, 50)));
    connect(btReset, SIGNAL(clicked()), demo, SLOT(reset()));

    QPushButton *btPosiSensor = new QPushButton("Posição Sensor", w);
    btPosiSensor->setGeometry(QRect(QPoint(50, 80), QSize(150, 50)));
    connect(btPosiSensor, SIGNAL(clicked()), demo, SLOT(sensor_position()));

    QPushButton *btPosiReady = new QPushButton("Posição leitura", w);
    btPosiReady->setGeometry(QRect(QPoint(50, 140), QSize(150, 50)));
    connect(btPosiReady, SIGNAL(clicked()), demo, SLOT(read_card_posi()));

    QPushButton *btPosiCapture = new QPushButton("Capturar", w);
    btPosiCapture->setGeometry(QRect(QPoint(50, 200), QSize(150, 50)));
    connect(btPosiCapture, SIGNAL(clicked()), demo, SLOT(capture_card()));

    QPushButton *btPosiPartial = new QPushButton("Entraga parcial", w);
    btPosiPartial->setGeometry(QRect(QPoint(50, 260), QSize(150, 50)));
    connect(btPosiPartial, SIGNAL(clicked()), demo, SLOT(out_partial_position()));

    QPushButton *btPosiTotal = new QPushButton("Entraga total", w);
    btPosiTotal->setGeometry(QRect(QPoint(50, 320), QSize(150, 50)));
    connect(btPosiTotal, SIGNAL(clicked()), demo, SLOT(outside_position()));

    QPushButton *btState = new QPushButton("Status da máquina", w);
    btState->setGeometry(QRect(QPoint(50, 380), QSize(150, 50)));
    connect(btState, SIGNAL(clicked()), demo, SLOT(reset()));

    w->show();
}

void MainWindow::test(){
    qDebug() << "test" << endl;
}

MainWindow::~MainWindow(){}

