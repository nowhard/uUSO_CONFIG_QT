#ifndef SERIAL_IO_H
#define SERIAL_IO_H

#include <QObject>
#include <QDebug>
#include <QByteArray>
#include <abstractserial.h>
#include "input_thread.h"
#include "output_thread.h"

class Serial_IO : public QObject
{
    Q_OBJECT
public:
    explicit Serial_IO(QObject *parent, AbstractSerial *port);

signals:
    void Sym_Timeout();//������� 1.5 �������

    void Send_Out(QByteArray data);

public slots:
    void Send(QByteArray data);//��������� ������� �� ����������
    void Start(void);//������ �����\��������
    void Stop(void);//��������� �����\��������
    void Response(void);//������� ����� �� ����������, ������ � �������
private:
    QByteArray data;//������, �������� � ����������
    AbstractSerial *io_port;// ���������������� ����
    //Output_Thread*  out_thread;
   // Input_Thread *in_thread;//������� ����� ������//


};

#endif // SERIAL_IO_H
