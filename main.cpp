#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();

//    QPushButton *lpTestBtn = w.window()->findChild<QPushButton*>("&Reset");
//    QObject::connect(lpTestBtn, SIGNAL(clicked()), &w, SLOT(test()));

    return a.exec();
}
