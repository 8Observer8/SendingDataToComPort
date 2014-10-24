#ifndef SENDER_H
#define SENDER_H

#include <QSerialPort>
#include <QString>
#include "PortOpenError.h"
#include "PortSendDataError.h"

class Sender
{
public:
    Sender( const QString &portName = QString( "COM1" ),
            QSerialPort::BaudRate baudRate = QSerialPort::Baud9600,
            QSerialPort::DataBits dataBits = QSerialPort::Data8,
            QSerialPort::Parity parity = QSerialPort::NoParity,
            QSerialPort::StopBits stopBits = QSerialPort::OneStop,
            QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl );

    Sender( const Sender &sender );

    ~Sender();

    void setPortName( const QString &portName );

    QString getPortName() const;
    QSerialPort::BaudRate getBaudRate() const;
    QSerialPort::DataBits getDataBits() const;
    QSerialPort::Parity getParity() const;
    QSerialPort::StopBits getStopBits() const;
    QSerialPort::FlowControl getFlowControl() const;

    void open() throw( PortOpenError );

    void send( const QByteArray &data )
    throw( PortOpenError, PortSendDataError );

private:
    QSerialPort m_serialPort;
    QString m_portName;
    QSerialPort::BaudRate m_baudRate;
    QSerialPort::DataBits m_dataBits;
    QSerialPort::Parity m_parity;
    QSerialPort::StopBits m_stopBits;
    QSerialPort::FlowControl m_flowControl;
};

#endif // SENDER_H
