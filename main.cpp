#include "mainwindow.h"

#include <QApplication>
#include <dispense.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Dispense demo;
    demo.connectSerial();
    demo.reset();
    demo.sensor_position();
    QThread::sleep(1);
    demo.read_card_posi();
    QThread::sleep(3);
    demo.capture_card();
    QThread::sleep(3);
    demo.out_partial_position();
    QThread::sleep(3);
    demo.outside_position();
    QThread::sleep(2);

    qDebug() << demo.check_status() << endl;
    w.show();
    return a.exec();
}
