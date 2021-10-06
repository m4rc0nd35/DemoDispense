#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

class MainWindow: public QMainWindow
{
public:
    explicit MainWindow(QWidget *parent=nullptr);
    ~MainWindow();

signals:

};

#endif // MAINWINDOW_H
