#include "proto_uso.h"

proto_uso::proto_uso(QObject *parent,AbstractSerial *port) :
    QObject(parent)
{
    this->port=port;

    in_thread=new Input_Thread(this,port);
    out_thread=new Output_Thread(this,port);

    in_thread->start();
    out_thread->start();

    connect(in_thread,SIGNAL(isRead(QByteArray)),this,SLOT(ResponseHandling(QByteArray)));
    connect(this,SIGNAL(WriteToOut_Thread(QByteArray)),out_thread,SLOT(Send(QByteArray)));


    timer=new QTimer(this);
    DEV=new DEVICE();
    connect(timer,SIGNAL(timeout()),this,SIGNAL(DEVICE_NOT_CONNECTED()));
}

proto_uso::~proto_uso()//деструктор
{
    //in_thread->quit();

    in_thread->exit();
    delete in_thread;

    //out_thread->quit();
    out_thread->exit();
    delete out_thread;
    delete timer;
}

void proto_uso::GET_DEV_INFO_REQ(qint8 dev_addr)//запрос на получение информации об устройстве
{
  //  QString debug;

    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(GET_DEV_INFO_REQ_);
    request.append(0x1);
    CRC=CRC8(request,request.length());
    request.append(CRC);

    emit this->WriteToOut_Thread(request);

    return;
}

void proto_uso::GET_DEV_INFO_RESP(QByteArray response)//обработчик полученной информации об устройстве
{
    quint8 len;

   if(response.length()<=5)
    {
       qDebug("NOT ACCEPTED!!!");
       return;//вылетаем
    }

    len=response[5];//получим длину оставшейся части
    DEV->state_byte=response[6];//получим байт статуса узла
    DEV->device_name.clear();//очищаем перед занесением нового имени
    DEV->device_name.append(response.mid(7,20));
    DEV->version=response.mid(27,5);//?
    DEV->channel_num=response[32];

    DEV->Init_Channels(DEV->channel_num);

    DEV->notice.clear();
    DEV->notice.append(response.mid(33+DEV->channel_num*2,response.length()-34-DEV->channel_num*2));

    for(quint8 i=0;i<DEV->channel_num;i++)
    {
        DEV->channel_type[i]=response[33+i*2];
        DEV->channel_mas[i]->channel_type=response[33+i*2];

    }
    emit DEV_INFO_RESPONSED();
    qDebug("ACCEPTED!!! %i",DEV->channel_num );
    return;
}

void proto_uso::CHANNEL_SET_PARAMETERS_REQ(qint8 dev_addr, class CHANNEL *chnl[])//установить параметры каналов
{
    //qDebug()<<"SETTINGS SET "<<chnl[8]->state_byte1;
    QByteArray request, set_request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_SET_PARAMETERS_REQ_);

    for(quint8 i=0;i< this->DEV->channel_num;i++)
    {
        if(i<8)
        {
            set_request.append(i);
            set_request.append(chnl[i]->channel_type);
            set_request.append(chnl[i]->state_byte1);
            set_request.append(chnl[i]->state_byte2);
        }
        else
        {
           // set_request.append(i);
           // set_request.append(chnl[i]->channel_type);
          //  set_request.append(chnl[i]->state_byte1);
        }
    }
    request.append(set_request.length()+1);//оставшаяся длина кадра +crc
    request.append(set_request);
    CRC=CRC8(request,request.length());
    request.append(CRC);

    emit this->WriteToOut_Thread(request);


    return;
}

void proto_uso::CHANNEL_ALL_GET_DATA_REQ(qint8 dev_addr)//выдать информацию по всем каналам
{
    QByteArray request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_ALL_GET_DATA_REQ_);
    request.append(0x1);
    CRC=CRC8(request,request.length());
    request.append(CRC);

     emit this->WriteToOut_Thread(request);
     qDebug("DATA REQUESTED!!!");
    return;
}

void proto_uso::CHANNEL_ALL_GET_DATA_RESP(QByteArray response)//ответ на запрос выдачи информации по всем каналам
{
    quint8 len;
    quint8 index=7, counter=0;

   if(response.length()<=5)
    {
       qDebug("NOT ACCEPTED!!!");
       return;//вылетаем
    }
    qDebug("CHANNELS %i", this->DEV->channel_num);
   while( counter< this->DEV->channel_num)
   {
        switch(/*this->DEV->channel_mas[counter]->channel_type>>4&0xF*/response[index+1]>>4&0xF)
        {
            case CHN_ADC:
            {
                switch(/*this->DEV->channel_mas[counter]->channel_type&0xF*/response[index+1]&0xF)
                {
                case 0x0:
                    {
                        this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00);
                       // this->DEV->channel_mas[counter]->channel_type=response[index];
                        this->DEV->channel_mas[counter]->state_byte1=response[index+4];
                        this->DEV->channel_mas[counter]->state_byte2=response[index+5];
                        index+=6;
                         qDebug("ADC_0x0");
                    }
                    break;

                case 0x1:
                    {
                        this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00);
                       // this->DEV->channel_mas[counter]->channel_type=response[index];
                        this->DEV->channel_mas[counter]->state_byte1=response[index+4];
                        this->DEV->channel_mas[counter]->state_byte2=response[index+5];
                        index+=6;
                         qDebug("ADC_0x1");
                    }
                    break;

                case 0x2:
                    {
                        this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00)|((quint32)response[index+4]<<16&0xFF0000);
                       // this->DEV->channel_mas[counter]->channel_type=response[index];
                        this->DEV->channel_mas[counter]->state_byte1=response[index+5];
                        this->DEV->channel_mas[counter]->state_byte2=response[index+6];
                        index+=7;
                         qDebug("ADC_0x2");
                    }
                    break;

                case 0x3:
                    {
                        this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00)|((quint32)response[index+4]<<16&0xFF0000);
                       // this->DEV->channel_mas[counter]->channel_type=response[index];
                        this->DEV->channel_mas[counter]->state_byte1=response[index+5];
                        this->DEV->channel_mas[counter]->state_byte2=response[index+6];
                        index+=7;
                         qDebug("ADC_0x3");
                    }
                    break;
                }
            }
            break;

            case CHN_DOL:
            {
                this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|(((quint32)response[index+3]<<8)&0xFF00)|(((quint32)response[index+4]<<16)&0xFF0000)|(((quint32)response[index+5]<<24)&0xFF000000);
                //this->DEV->channel_mas[counter]->channel_type=response[index];
                this->DEV->channel_mas[counter]->state_byte1=response[index+6];

                index+=7;
                 qDebug("DOL");
            }
            break;

            case CHN_COUNT:
            {
                this->DEV->channel_mas[counter]->channel_data=((quint32)response[index+2]&0xFF)|((quint32)response[index+3]<<8&0xFF00);
                //this->DEV->channel_mas[counter]->channel_type=response[index];
                this->DEV->channel_mas[counter]->state_byte1=response[index+4];

                index+=5;
                 qDebug("COUNT");
            }
            break;

            default :
            {
                    qDebug("UNREC DATA!!!");
            }
            break;
        }
        counter++;
    }
    qDebug("DATA ACCEPTED!!!");
    emit GET_ALL_DATA_RESPONSED();
    return;
}

void   proto_uso::CHANNEL_SET_ADDRESS_DESC(quint8 dev_addr,quint8 new_addr,QString dev_name,QByteArray version, QString description)//установить адрес, имя, описание, и т.д.
{
    QByteArray request,set_request;
    quint8 CRC;
    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_SET_ADDRESS_DESC_);

    set_request.append(new_addr);

    dev_name.resize(20);
    set_request.append(dev_name.toAscii());

    version.resize(5);
    set_request.append(version);

    set_request.append(description.toAscii());
    if(description.length()>40)
        description.resize(40);

    request.append(set_request.length()+1);//оставшаяся длина кадра +crc
    request.append(set_request);
    CRC=CRC8(request,request.length());
    request.append(CRC);

     emit this->WriteToOut_Thread(request);
     qDebug("DATA REQUESTED!!!");
    return;
}

void proto_uso::REQUEST_ERROR(QByteArray response)//общий обработчик ошибок, возникших при передаче данных, работе и т.д.
{
    qDebug("ERROR !!!");
    return;
}

void proto_uso::ResponseHandling(QByteArray response)
{
    quint8 CRC,trueCRC;
    timer->stop();
    //------проверка црц
    trueCRC=CRC8(response,response.length()-1);
    CRC=response[response.length()-1];
qDebug("RESPONSED!!!");
    if(trueCRC!=CRC)
    {
        qDebug("CRC ERR");
        return;//прерываем, если произоша ошибка передачи данных
    }
    qDebug("CRC OK");
    //------------------

    switch((quint8)response[4])
    {
        case GET_DEV_INFO_RESP_:
        {
            GET_DEV_INFO_RESP(response);
        }
        break;

        case CHANNEL_ALL_GET_DATA_RESP_:
        {
            CHANNEL_ALL_GET_DATA_RESP(response);
        }
        break;

        case CHANNEL_GET_CALIBRATE_RESP_:
        {

            CHANNEL_GET_CALIBRATE_RESP(response);
        }
        break;

        case REQUEST_ERROR_:
        {
            REQUEST_ERROR(response);
        }
        break;
    }

    return;
}

quint8 proto_uso::CRC8(QByteArray data,quint8 len)//CRC8 для протокола
{
    quint8   CRC = 0;
    quint8   data_pntr=0;
        while(len)
        {
            CRC = CRC ^ (data[data_pntr]);//Spool[i];
            data_pntr++;
            CRC = ((CRC & 0x01) ? (unsigned char)0x80: (unsigned char)0x00) | (unsigned char)(CRC >> 1);

        if (CRC & (unsigned char)0x80) CRC = CRC ^ (unsigned char)0x3C;
                len--;
        }
    return CRC;
}

void DEVICE::Init_Channels(quint8 num_chn)//создаем память для каналов
{
    for(quint8 i=0;i<num_chn;i++)
        channel_mas.append(new CHANNEL());

    return;
}

void proto_uso::CHANNEL_SET_CALIBRATE(quint8 dev_addr,quint8 channel, char point,unsigned long num)//запрос на калибровку минимума-максимума
{
    QByteArray request,set_request;
    quint8 CRC;
    //unsigned char mmax;

    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_SET_CALIBRATE_);

    set_request.append(channel);
   // mmax=min_max;
    set_request.append(point);

    if(point<2)
    {
        for(quint8 i=0;i<4;i++)
        {
            set_request.append((char)(num&0xFF));
            num=num>>8;
        }
    }
    else
    {
        set_request.append((char)(num&0xFF));
    }


    request.append(set_request.length()+1);
    request.append(set_request);

    CRC=CRC8(request,request.length());
    request.append(CRC);

    qDebug()<<request.toHex();

     emit this->WriteToOut_Thread(request);
     qDebug("DATA REQUESTED!!!");
    return;
}

void proto_uso::CHANNEL_SET_CALIBRATE(quint8 dev_addr,quint8 channel, char mode,float K, float C)//запрос на калибровку минимума-максимума
{
    QByteArray request,set_request;
    quint8 CRC;
    //unsigned char mmax;

    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_SET_CALIBRATE_);

    set_request.append(channel);
   // mmax=min_max;
    set_request.append(mode);

    if(mode==0)
    {
         set_request.append(reinterpret_cast<const char*>(&K), sizeof(K));
         set_request.append(reinterpret_cast<const char*>(&C), sizeof(C));
    }
   // else
    //{
      //  set_request.append(mode);
   // }


    request.append(set_request.length()+1);
    request.append(set_request);

    CRC=CRC8(request,request.length());
    request.append(CRC);

    qDebug()<<request.toHex();

     emit this->WriteToOut_Thread(request);
     qDebug("DATA REQUESTED!!!");
    return;
}

void proto_uso::CHANNEL_SET_ALL_DEFAULT(quint8 dev_addr)//сбросить настройки и калибровки по умолчанию
{
    QByteArray request,set_request;
    quint8 CRC;
    //unsigned char mmax;

    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_SET_ALL_DEFAULT_);
    request.append((char)0x1);
    CRC=CRC8(request,request.length());
    request.append(CRC);

    qDebug()<<request.toHex();

     emit this->WriteToOut_Thread(request);
     qDebug("DATA REQUESTED!!!");
    return;
}

void proto_uso::CHANNEL_GET_CALIBRATE_REQ(quint8 dev_addr,quint8 channel)//запрос на получение калибровки канала
{
    QByteArray request,set_request;
    quint8 CRC;

    request.append((char)0x0);
    request.append((char)0xD7);
    request.append((char)0x29);//заголовок кадра
    request.append(dev_addr);
    request.append(CHANNEL_GET_CALIBRATE_REQ_);
    request.append((char)0x2);
    request.append(channel);
    CRC=CRC8(request,request.length());
    request.append(CRC);

    qDebug()<<request.toHex();

     emit this->WriteToOut_Thread(request);
     qDebug("DATA REQUESTED!!!");
    return;
}

void proto_uso::CHANNEL_GET_CALIBRATE_RESP(QByteArray response)//ответ от устройства с калибровкой канала
{
    quint8 channel=0,calibrated=0;
    float K,C;

    union
    {
        float  fl_val;
        quint8 ch_val[4];
    }fl_char;

    channel=response[6];
    calibrated=response[7];

    fl_char.ch_val[3]=response[11];
    fl_char.ch_val[2]=response[10];
    fl_char.ch_val[1]=response[9];
    fl_char.ch_val[0]=response[8];

    K=fl_char.fl_val;

    fl_char.ch_val[3]=response[15];
    fl_char.ch_val[2]=response[14];
    fl_char.ch_val[1]=response[13];
    fl_char.ch_val[0]=response[12];

    C=fl_char.fl_val;

    emit GET_CALIBRATE_RESPONSED(channel,calibrated,K,C);
    qDebug()<<"CALIBRATED="<<calibrated<<"; K="<<K<<"; C="<<C;
    return;
}
