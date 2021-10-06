#include <QApplication>
#include <dispense.h>
#include <QThread>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Dispense demo;
    demo.connectSerial();

//    demo.reset();
//    demo.sensor_position();
//    qDebug() << "sensor_position" << demo.check_status() << endl;
//    QThread::sleep(1);
//    demo.read_card_posi();
//    qDebug() << "read_card_posi" << demo.check_status() << endl;
//    QThread::sleep(3);
//    demo.capture_card();
//    qDebug() << "capture_card" << demo.check_status() << endl;
//    QThread::sleep(3);
//    demo.out_partial_position();
//    qDebug() << "out_partial_position" << demo.check_status() << endl;
//    QThread::sleep(3);
//    demo.outside_position();
//    qDebug() << "outside_position" << demo.check_status() << endl;
//    QThread::sleep(2);

    w.show();
    return a.exec();
}
