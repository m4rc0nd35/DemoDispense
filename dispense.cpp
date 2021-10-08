#include "dispense.h"

bool Dispense::connectSerial(){
    _serial = new QSerialPort();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        if(_serial->open(QIODevice::ReadWrite))
            qDebug() << _serial->errorString() << endl;

        if(info.vendorIdentifier() == 0x067b && info.productIdentifier() == 0x2303)
        {
            _serial->setPortName(info.portName());
            _serial->setBaudRate(QSerialPort::Baud9600);
            _serial->setDataBits(QSerialPort::Data8);
            _serial->setParity(QSerialPort::NoParity);
            _serial->setStopBits(QSerialPort::OneStop);
            _serial->setFlowControl(QSerialPort::NoFlowControl);

            if(_serial->open(QIODevice::ReadWrite))
                m_connected = true;
            else
                qDebug() << "[CRITICAL] DISCONNECTED" << endl;
        }
    }
}

void Dispense::reset()
{
    qDebug() << "reset" << endl;
    if(m_connected)
    {
        QByteArray cmd;
        char bytesCmd[6] = { 0x02, 0x30, 0x30, 0x52, 0x53, 0x03 };
        cmd.append(bytesCmd, 6);
        cmd.append(sum(cmd));
        command(cmd);
        cmd.clear();

        const char bytesConfirm[3] = { 0x05, 0x30, 0x30 };
        cmd.append(bytesConfirm, 3);
        command(cmd);
    }else
        throw "port not conected";
}

QJsonObject Dispense::check_status()
{
    // 0 Normal
    // 1 preparando,      2 falha na preparação,  4 comando erro,   8 manter
    // 1 erro na captura, 2 erro na entrega,      4 capturando,     8 entregando
    // 1 pouco cartão,    2 cartão atolado,       3 não declarado,  4 não capturado, 8 sobreposto
    // 1 posi S1,         2 posi S2,              3 posi S1 & S2 (leitura),   4 posi S3 (pronto),  6 S2 & S3, 8 sem cartão
    QJsonObject json;
    if(m_connected)
    {
        QByteArray cmd;
        char bytesCmd[6] = { 0x02, 0x30, 0x30, 0x41, 0x50, 0x03 };
        cmd.append(bytesCmd, 6);
        cmd.append(sum(cmd));
        command(cmd);
        cmd.clear();

        const char bytesConfirm[3] = { 0x05, 0x30, 0x30 };
        cmd.append(bytesConfirm, 3);

        QString stateResult = command(cmd);
        QRegularExpression rx("(SF)[0-9]{4}");
        QRegularExpressionMatchIterator rxIterator = rx.globalMatch(stateResult);
        QString stateData;
        while (rxIterator.hasNext()) {
            QRegularExpressionMatch match = rxIterator.next();
            QString word = match.captured(0);
            stateData.append(word);
        }

        json.insert("preparing",QString(stateData.at(2)));
        json.insert("capture",QString(stateData.at(3)));
        json.insert("card",QString(stateData.at(4)));
        json.insert("position",QString(stateData.at(5)));

    }else
        throw "port not conected";

    return json;
}

void Dispense::read_card_posi()
{
    if(m_connected)
    {
        QByteArray cmd;
        const char bytesCmd[7] = { 0x02, 0x30, 0x30, 0x46, 0x43, 0x37, 0x03 };
        cmd.append(bytesCmd, 7);
        cmd.append(sum(cmd));
        command(cmd);
        cmd.clear();

        const char bytesConfirm[3] = { 0x05, 0x30, 0x30 };
        cmd.append(bytesConfirm, 3);
        command(cmd);
    }else
        throw "port not conected";
}

void Dispense::capture_card()
{
    if(m_connected)
    {
        QByteArray cmd;
        const char bytesCmd[6] = { 0x02, 0x30, 0x30, 0x43, 0x50, 0x03 };
        cmd.append(bytesCmd, 6);
        cmd.append(sum(cmd));
        command(cmd);
        cmd.clear();

        const char bytesConfirm[3] = { 0x05, 0x30, 0x30 };
        cmd.append(bytesConfirm, 3);
        command(cmd);
    }else
        throw "port not conected";
}

void Dispense::outside_position()
{
    if(m_connected)
    {
        QByteArray cmd;
        const char bytesCmd[7] = { 0x02, 0x30, 0x30, 0x46, 0x43, 0x30, 0x03 };
        cmd.append(bytesCmd, 7);
        cmd.append(sum(cmd));
        command(cmd);
        cmd.clear();

        const char bytesConfirm[3] = { 0x05, 0x30, 0x30 };
        cmd.append(bytesConfirm, 3);
        command(cmd);
    }else
        throw "port not conected";
}

void Dispense::out_partial_position()
{
    if(m_connected)
    {
        QByteArray cmd;
        const char bytesCmd[7] = { 0x02, 0x30, 0x30, 0x46, 0x43, 0x34, 0x03 };
        cmd.append(bytesCmd, 7);
        cmd.append(sum(cmd));
        command(cmd);
        cmd.clear();

        const char bytesConfirm[3] = { 0x05, 0x30, 0x30 };
        cmd.append(bytesConfirm, 3);
        command(cmd);
    }else
        throw "port not conected";
}

void Dispense::sensor_position()
{
    if(m_connected)
    {
        QByteArray cmd;
        const char bytesCmd[7] = { 0x02, 0x30, 0x30, 0x46, 0x43, 0x36, 0x03 };
        cmd.append(bytesCmd, 7);
        cmd.append(sum(cmd));
        command(cmd);
        cmd.clear();

        const char bytesConfirm[3] = { 0x05, 0x30, 0x30 };
        cmd.append(bytesConfirm, 3);
        command(cmd);
    }else
        throw "port not conected";
}

QByteArray Dispense::command(QByteArray &buffer)
{
    if(_serial->isOpen()){
        _serial->write(buffer);
        _serial->flush();
        while (_serial->waitForReadyRead(500));
        return _serial->readAll();
    }else
        throw "Serial is closed!";
}

char Dispense::sum(QByteArray buffer)
{
    int checkSum = 0;
    for(int i=0; (buffer.length() +1) > i; i++)
        checkSum = checkSum ^ buffer[i];

    return char(checkSum & 0xFF);
}

Dispense::~Dispense(){
    if (_serial->isOpen())
        _serial->close();
}
