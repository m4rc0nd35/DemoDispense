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
    enum PrepareState {
        PrepareNormal = 48,
        Preparing,
        PrepareFail,
        CommandErro,
        Mantem
    };
    Q_ENUM(PrepareState)
    enum CaptureState {
        CaptureNormal = 48,
        CaptureErro
    };
    Q_ENUM(CaptureState)
    enum CardState {
        Normal = 48,
        LowCard
    };
    Q_ENUM(CardState)
//    enum QuartState {

//    };
//    Q_ENUM(QuartState)

    ~Dispense();
    Q_INVOKABLE bool connectSerial();
    Q_INVOKABLE void reset();
    Q_INVOKABLE QJsonObject check_status();
    Q_INVOKABLE void read_card_posi();
    Q_INVOKABLE void capture_card();
    Q_INVOKABLE void outside_position();
    Q_INVOKABLE void out_partial_position();
    Q_INVOKABLE void sensor_position();
    Q_INVOKABLE QByteArray command(QByteArray&);

signals:
    void successRead(QString tag);
    void errRead();
    void getTagChanged(QString tag);
    void dataChanged(QByteArray data);
    void successLoginChanged();

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
