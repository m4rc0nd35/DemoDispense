#ifndef DISPENSE_H
#define DISPENSE_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMutex>
#include <QWaitCondition>
#include <QJsonObject>

class Dispense: public QObject
{
    Q_OBJECT
public:
    ~Dispense();
    bool connectSerial();
    QByteArray command(QByteArray&);
    QJsonObject check_status();

signals:
    void successRead(QString tag);
    void errRead();
    void getTagChanged(QString tag);
    void dataChanged(QByteArray data);
    void successLoginChanged();

public slots:
    void reset();
    void read_card_posi();
    void capture_card();
    void outside_position();
    void out_partial_position();
    void sensor_position();

private:
    char sum(QByteArray);
    void send(QByteArray);
    QSerialPort *_serial;
    QString m_flag;
    bool m_connected;

    int m_waitTimeout = 0;
    QMutex m_mutex;
    QWaitCondition m_cond;
    bool m_quit = false;
    QList<QByteArray> _buffer;
};

#endif // DISPENSE_H
