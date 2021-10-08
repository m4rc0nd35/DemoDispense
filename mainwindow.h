#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <dispense.h>

class MainWindow: public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent=nullptr);
    ~MainWindow();

public slots:
    void test();

};

#endif // MAINWINDOW_H
