#include "serial_io.h"

Serial_IO::Serial_IO(QObject *parent, AbstractSerial *port) :
    QObject(parent)
{
    io_port=port;
   // out_thread=new Output_Thread(this,port);
    //connect(io_port,SIGNAL(readyRead()),this,SLOT(Response()));
  //  connect(this,SIGNAL(Send_Out(QByteArray)),out_thread,SLOT(Send(QByteArray)));

}

void Serial_IO::Start(void)//������ �����\��������
{

}

void Serial_IO::Stop(void)//��������� �����\��������
{
    if(io_port->isOpen())
        io_port->close();
}

void Serial_IO::Send(QByteArray data)//��������� ������� �� ����������
{
    //emit Send_Out(data);
    //io_port->write(data);

}

void Serial_IO::Response(void)//������� ����� �� ����������, ������ � �������
{
       // this->data = io_port->readAll();
       // qDebug() << "Readed: " << data.size() << " bytes";
       // qDebug() << "DATA: " << data.data();
}
