#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    port=new AbstractSerial(this);
    port->setTotalReadConstantTimeout(0);

    timer=new QTimer();

    p_uso=new proto_uso(this,port);
     QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Название канала")));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Тип канала")));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Диапазон")));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Фильтр")));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Значение")));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Калибровка 0")));
    ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem(tr("Значение  0")));
    ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem(tr("Калибровка 1")));
    ui->tableWidget->setHorizontalHeaderItem(8, new QTableWidgetItem(tr("Значение  1")));
    ui->tableWidget->setHorizontalHeaderItem(9, new QTableWidgetItem(tr("Калибр.")));
    ui->tableWidget->setHorizontalHeaderItem(10, new QTableWidgetItem(tr("Установить")));

    ui->tableWidget->setHorizontalHeaderItem(11, new QTableWidgetItem(tr("Разрядность")));
  //  ui->tableWidget->setHorizontalHeaderItem(12, new QTableWidgetItem(tr("Отключить канал")));
   // timer->start(1000);

    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);


     connect(p_uso,SIGNAL(DEV_INFO_RESPONSED()),this,SLOT(on_dev_info_responsed()));
     connect(p_uso,SIGNAL(GET_ALL_DATA_RESPONSED()),this,SLOT(on_dev_get_data_responsed()));

     connect(ui->action_LOAD,SIGNAL(triggered()),this,SLOT(on_menu_load_settings_clicked()));
     connect(ui->action_SAVE,SIGNAL(triggered()),this,SLOT(on_menu_save_settings_clicked()));

     connect(timer,SIGNAL(timeout()),this,SLOT(Get_All_Data()));


     connect_dlg=new connect_dialog();
     connect(connect_dlg,SIGNAL(connect_device(quint8)),this,SLOT(on_connect_device(quint8)));


     for(quint8 i=0;i<20;i++)
     {
          chnl[i]=new CHANNEL();
     }

     strlist<<tr("0-2.56 В")<<tr("0-1.28 В")<<tr("0-640 мВ")<<tr("0-320 мВ")<<tr("0-160 мВ")<<tr("0-80 мВ")<<tr("0-40 мВ")<<tr("0-20 мВ");
     bitlist<<tr("24")<<tr("16");

     read_flag=false;


     d_info=new dev_info(this);//диалог информации об устройстве
     connect(d_info,SIGNAL(get_dev_info()),this,SLOT(on_dialog_get_dev_info()));
     connect(d_info,SIGNAL(set_dev_info()),this,SLOT(on_dialog_set_dev_info()));

     CalibrList.clear();

     connect(p_uso,SIGNAL(GET_CALIBRATE_RESPONSED(quint8,quint8,float,float)),this,SLOT(on_get_calibrate_responsed(quint8,quint8,float,float)));

     UnactiveInterface();
}

MainWindow::~MainWindow()
{
    port->close();
    delete port;
    delete ui;
}


void MainWindow::on_action_COM_triggered()
{
    com_dlg.show();

}

void MainWindow::MessageReadOK(bool mess)
{
    if(mess)
    {
       ui->statusBar->showMessage("Device Read OK");
       //Get_All_Data();
    }
    else
    {
       ui->statusBar->showMessage("Device Read Error");
    }
}

void MainWindow::MessageWriteOK(bool mess)
{
    if(mess)
    {
       ui->statusBar->showMessage("Device Write OK");
    }
    else
    {
       ui->statusBar->showMessage("Device Write Error");
    }
}

void MainWindow:: MessageNotConnected(void)
{
     ui->statusBar->showMessage("Device Not Connected");
}





void MainWindow::Display_Dev_Info(bool OK,quint16 ID, QString Description)//отобразить информацию об устройстве
{
    if(OK)
    {

    }
    else
    {
        ui->statusBar->showMessage("Info read ERROR");
    }
}


void MainWindow::Info_Is_Set(bool OK)
{
    if(OK)
    {
       ui->statusBar->showMessage("Info set is OK");
    }
    else
    {
        ui->statusBar->showMessage("Info set ERROR");
    }
}


//void MainWindow::on_pushButton_2_clicked()
//{
//    p_uso->GET_DEV_INFO_REQ(device_addr);
//}


void MainWindow::on_dev_info_responsed(void)
{
   QString str;
   quint8 i;
//   ui->lineEdit_2->setText(p_uso->DEV->device_name);
//   ui->lineEdit_3->setText(p_uso->DEV->notice);
//   ui->lineEdit_4->setText(str.append(p_uso->DEV->version));


    qDebug()<<str;
    //d_info.ui->lineEdit_2->setText(p_uso->DEV->device_name);

    d_info->set_dev_name_text(p_uso->DEV->device_name);
    d_info->set_dev_descr_text(p_uso->DEV->notice);
    d_info->set_dev_ver_text(str.append(p_uso->DEV->version));

    ui->label_5->setText(p_uso->DEV->device_name);
    str="";
    ui->label_6->setText(str.append(p_uso->DEV->version));
    ui->label_7->setText(p_uso->DEV->notice);
    ui->label_8->setText(str.setNum(device_addr));

    /*for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        ui->tableWidget->removeRow(i);
        qDebug("%i",i);
    }*/
   ui->tableWidget->setRowCount(0);
   adc_chn_num=0;

   for(i=1;i<=p_uso->DEV->channel_num;i++)
   {
       ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(tr("Канал ")+str.setNum(i)));
       ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem());


     //  ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 12,new QCheckBox());
    //   QCheckBox *chkbox=qobject_cast<QCheckBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 12));

       switch(/*p_uso->DEV->channel_type[i-1]>>4&0xF*/p_uso->DEV->channel_mas[i-1]->channel_type>>4&0xF)
       {
       case 0x0:
           {
               adc_chn_num++;
               CalibrList.append(new CalibrPoints);

               qDebug()<<"VECTOR="<<CalibrList.size();


               ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(tr("Аналоговый")));
               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 2,new QComboBox());
               QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 2));
               cmb->addItems(strlist);
               cmb->setCurrentIndex(p_uso->DEV->channel_mas[i-1]->state_byte1&0xF);

               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 3,new QSpinBox());
               QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 3));

               spin->setMaximum(255);
               spin->setMinimum(3);
               spin->setValue(p_uso->DEV->channel_mas[i-1]->state_byte2);

               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 5,new QPushButton(tr("Точка 0")));
               QPushButton *bttn=qobject_cast<QPushButton *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 5));
               bttn->setObjectName(str.setNum(ui->tableWidget->rowCount()-1));
               connect(bttn,SIGNAL(clicked()),this,SLOT(on_calibrate_0_button_clicked()));

               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 6,new QSpinBox());
               spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 6));
               spin->setMaximum(20000000);

               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 7,new QPushButton(tr("Точка 1")));
               bttn=qobject_cast<QPushButton *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 7));
                bttn->setObjectName(str.setNum(ui->tableWidget->rowCount()-1));
               connect(bttn,SIGNAL(clicked()),this,SLOT(on_calibrate_full_button_clicked()));

               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 8,new QSpinBox());
               spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 8));
               spin->setMaximum(20000000);

               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 9,new QCheckBox());
               QCheckBox *chkbox=qobject_cast<QCheckBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 9));

               //ui->tableWidget->item(ui->tableWidget->rowCount()-1, 9)->setTextAlignment(Qt::AlignCenter);

               chkbox->setObjectName(str.setNum(ui->tableWidget->rowCount()-1));
               connect(chkbox,SIGNAL(clicked()),this,SLOT(on_calibrate_flag_clicked()));
               //cmb->setCurrentIndex(p_uso->DEV->channel_mas[i-1]->state_byte1&0xF);

               ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 10,new QPushButton(tr("Установить")));
               bttn=qobject_cast<QPushButton *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 10));
               bttn->setObjectName(str.setNum(ui->tableWidget->rowCount()-1));
               connect(bttn,SIGNAL(clicked()),this,SLOT(on_calibrate_set_button_clicked()));

               //CalibrList.append(QPointF(0,0));
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 11,new QComboBox());
               cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1, 11));
               cmb->addItems(bitlist);

               if((p_uso->DEV->channel_mas[i-1]->channel_type&0xF)==0x0 || (p_uso->DEV->channel_mas[i-1]->channel_type&0xF)==0x1 )
               {
                    cmb->setCurrentIndex(1);//p_uso->DEV->channel_mas[i-1]->state_byte1&0xF);
               }
               if((p_uso->DEV->channel_mas[i-1]->channel_type&0xF)==0x2 || (p_uso->DEV->channel_mas[i-1]->channel_type&0xF)==0x3 )
               {
                    cmb->setCurrentIndex(0);//p_uso->DEV->channel_mas[i-1]->state_byte1&0xF);
                    qDebug()<<(p_uso->DEV->channel_mas[i-1]->channel_type&0xF);
               }


           }
           break;
       case 0x1:
           {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(tr("ДОЛ")));
           }
           break;
       case 0x2:
           {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(tr("Частотный")));
           }
           break;

       default:
           {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(tr("Неизвестный")));
           }
           break;
       }

      // tableWidget->setItem(0, 1, new QTableWidgetItem(query.value(1).toDateTime().toString()));
      // tableWidget->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
      // tableWidget->setItem(0, 3, new QTableWidgetItem(query.value(3).toString()));
       ui->tableWidget->setRowHeight(ui->tableWidget->rowCount()-1, 20);
   }


   ui->action_SAVE->setVisible(true);
   ui->action_LOAD->setVisible(true);
    return;
}


void MainWindow::on_dev_get_data_responsed(void)
{
    QString str;
    for(quint8 i=0;i<p_uso->DEV->channel_num;i++)
    {
        //ui->tableWidget->setItem(i, 4, new QTableWidgetItem(str.setNum(p_uso->DEV->channel_mas[i]->channel_data)));//тормозит
            ui->tableWidget->item(i,4)->setText(str.setNum(p_uso->DEV->channel_mas[i]->channel_data));

        if((p_uso->DEV->channel_mas[i]->channel_type>>4&0xF)==0x0)
        {
           QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 2));
           cmb->setCurrentIndex(p_uso->DEV->channel_mas[i]->state_byte1&0xF);

           QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, 3));
           spin->setValue((quint8)p_uso->DEV->channel_mas[i]->state_byte2);
        }
    }
    return;
}

void MainWindow::Get_All_Data(void)
{
    p_uso->CHANNEL_ALL_GET_DATA_REQ(device_addr);

    //timer->stop();
    return;
}



//void MainWindow::on_pushButton_5_clicked()
//{
//    QByteArray ver;
//    ver.append(ui->lineEdit_4->text());
//    p_uso->CHANNEL_SET_ADDRESS_DESC(device_addr,ui->spinBox_2->value(),ui->lineEdit_2->text(),ver,ui->lineEdit_3->text());
//}

void MainWindow::UnactiveInterface(void)
{
    //ui->groupBox_4->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->action_SAVE->setVisible(false);
    ui->action_LOAD->setVisible(false);
}

void MainWindow::ActivateInterface(void)
{
    //ui->groupBox_4->setEnabled(true);
    ui->groupBox_3->setEnabled(true);
}

void MainWindow::on_calibrate_0_button_clicked()//кнопки калибровки в таблице
{
    QPushButton* btn=qobject_cast<QPushButton *>(sender());
    QString name=btn->objectName();


    QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(/*ui->tableWidget->rowCount()-1*/name.toInt(), 6));

    qDebug() << "CNOCK min"<<name<<" "<<spin->value();

    qDebug() <<CalibrList.size();
    CalibrList[name.toInt()]->first_point_x=ui->tableWidget->item(name.toInt(),4)->text().toLong();
    CalibrList[name.toInt()]->first_point_y=spin->value();

    qDebug() << "CNOCK min "<<CalibrList[name.toInt()]->first_point_x<<" ;"<<CalibrList[name.toInt()]->first_point_y;
}

void MainWindow::on_calibrate_full_button_clicked()//кнопки калибровки в таблице
{
    QPushButton* btn=qobject_cast<QPushButton *>(sender());
    QString name=btn->objectName();
    QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(/*ui->tableWidget->rowCount()-1*/name.toInt(), 8));
    qDebug() << "CNOCK max"<<name<<" "<<spin->value();
  //  p_uso->CHANNEL_SET_CALIBRATE(device_addr,name.toInt(),1,spin->value());

    //CalibrList[name.toInt()]=QPointF((float),(float));
    CalibrList[name.toInt()]->second_point_x=ui->tableWidget->item(name.toInt(),4)->text().toLong();
    CalibrList[name.toInt()]->second_point_y=spin->value();

    qDebug() << "CNOCK max "<<CalibrList[name.toInt()]->second_point_x<<" ;"<<CalibrList[name.toInt()]->second_point_y;
}

void MainWindow::on_calibrate_flag_clicked()//установить снять флаг калибровки по каналу
{
    QCheckBox* chkbox=qobject_cast<QCheckBox *>(sender());
    QString name=chkbox->objectName();
   // p_uso->CHANNEL_SET_CALIBRATE(device_addr,name.toInt(),2,chkbox->checkState());

    if(chkbox->checkState())
    {
         p_uso->CHANNEL_SET_CALIBRATE(device_addr,name.toInt(),2,0,0);
    }
    else
    {
         p_uso->CHANNEL_SET_CALIBRATE(device_addr,name.toInt(),1,0,0);
    }

    qDebug() << "CNOCK FLAG"<<name;
}


void MainWindow::on_menu_load_settings_clicked()
{
    QString integer;
    QString s=QFileDialog::getOpenFileName(0,tr("Загрузить настройки"),QString(),tr("Файл настроек (*.uso)") );


    if(s.length()<4)
        return;
    QSettings *settings = new QSettings(/*"settings.conf"*/s,QSettings::IniFormat);
   // settings->clear();

//    ui->lineEdit_2->setText(settings->value("device/name","").toString());  //устанавливаем значение
//    ui->lineEdit_4->setText(settings->value("device/version","").toString());  //устанавливаем значение
//    ui->lineEdit_3->setText(settings->value("device/description","").toString());  //устанавливаем значение
//    ui->spinBox_2->setValue(settings->value("device/address","").toInt());  //устанавливаем значение

     d_info->set_dev_name_text(settings->value("device/name","").toString());
     d_info->set_dev_ver_text(settings->value("device/version","").toString());
     d_info->set_dev_descr_text(settings->value("device/description","").toString());
     d_info->set_dev_addr(settings->value("device/address","").toInt());

   /* settings->setValue("device/version",ui->lineEdit_4->text());  //устанавливаем значение
    settings->setValue("device/description",ui->lineEdit_3->text());  //устанавливаем значение
    settings->setValue("device/address",ui->spinBox_2->value());  //устанавливаем значение*/

    for(quint8 i=0;i<ui->tableWidget->rowCount();i++)
    {
        if(ui->tableWidget->item(i,1)->text()==tr("Аналоговый")/*i<8*/)
        {
            QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 2));

            cmb->setCurrentIndex(settings->value("channel_"+integer.setNum(i)+"/diapason",0).toInt());

            QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, 3));

            spin->setValue(settings->value("channel_"+integer.setNum(i)+"/filter",3).toInt());
        }
    }
    qDebug() << "SETTINGS LOADED"<< s;
    //settings.close();
}

void MainWindow::on_menu_save_settings_clicked()
{
    QString integer;
    QString s=QFileDialog::getSaveFileName(0,tr("Сохранить настройки"),QString(),tr("Файл настроек (*.uso)") );

    if(s.length()<4)
        return;

    QSettings *settings = new QSettings(/*"settings.conf"*/s,QSettings::IniFormat);
    settings->clear();

//    settings->setValue("device/name",ui->lineEdit_2->text());  //устанавливаем значение
//    settings->setValue("device/version",ui->lineEdit_4->text());  //устанавливаем значение
//    settings->setValue("device/description",ui->lineEdit_3->text());  //устанавливаем значение
//    settings->setValue("device/address",ui->spinBox_2->value());  //устанавливаем значение

    settings->setValue("device/name",d_info->get_dev_name_text());  //устанавливаем значение
    settings->setValue("device/version",d_info->get_dev_ver_text());  //устанавливаем значение
    settings->setValue("device/description",d_info->get_dev_descr_text());  //устанавливаем значение
    settings->setValue("device/address",d_info->get_dev_addr());  //устанавливаем значение


    for(quint8 i=0;i<ui->tableWidget->rowCount();i++)
    {
        if(ui->tableWidget->item(i,1)->text()==tr("Аналоговый")/*i<8*/)
        {
            QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 2));
            settings->setValue("channel_"+integer.setNum(i)+"/diapason",cmb->currentIndex());
            QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, 3));
            settings->setValue("channel_"+integer.setNum(i)+"/filter",spin->text());
        }
    }

    settings->sync(); //записываем настройки
    qDebug() << "SETTINGS SAVED"<<s;
}

void MainWindow::on_calibrate_set_button_clicked()
{
    qDebug() << "CALIBR SET";

    float K,C;

    QPushButton* btn=qobject_cast<QPushButton *>(sender());
    QString name=btn->objectName();
    QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(/*ui->tableWidget->rowCount()-1*/name.toInt(), 8));


    K=((float)CalibrList[name.toInt()]->second_point_y-(float)CalibrList[name.toInt()]->first_point_y)/((float)CalibrList[name.toInt()]->second_point_x-(float)CalibrList[name.toInt()]->first_point_x);
    C=(float)CalibrList[name.toInt()]->first_point_y-(float)CalibrList[name.toInt()]->first_point_x*K;

   qDebug() << "CNOCK SET"<<name<<" "<<K<<" "<<C;
    p_uso->CHANNEL_SET_CALIBRATE(device_addr,name.toInt(),0,K,C);
}



void MainWindow::on_action_Set_Settings_Default_triggered()
{
    p_uso->CHANNEL_SET_ALL_DEFAULT(device_addr);
}

void MainWindow::on_action_connect_triggered()
{
    if(!port->isOpen())
    {
        connect_dlg->show();
    }
    else
    {
        port->close();
        ui->action_connect->setText(tr("Подключить устройство"));
        UnactiveInterface();
    }
}

void MainWindow::on_connect_device(quint8 dev_addr)
{
    device_addr=dev_addr;
    if(!port->isOpen())
     {
     port->setDeviceName(com_dlg.ui->comboBox->currentText());


     if ( !port->open(AbstractSerial::ReadWrite | AbstractSerial::Unbuffered) ) {
         qDebug() << "Serial device by default: " << port->deviceName() << " open fail.";
         ui->statusBar->showMessage("Port Open Fail");
         return;
     }
     if (!port->setBaudRate(AbstractSerial::BaudRate57600/*com_dlg.ui->comboBox_2->currentText()*/)) {
         qDebug() << "Set baud rate  error.";
         return;
     };

     if (!port->setDataBits(AbstractSerial::DataBits8)) {
         qDebug() << "Set data bits " <<  AbstractSerial::DataBits8 << " error.";
         return;
     }
     if (!port->setParity(AbstractSerial::ParityNone)) {
         qDebug() << "Set parity " <<  AbstractSerial::ParityNone << " error.";
         return;
     }

    if(com_dlg.ui->radioButton->isChecked())
     {
         if (!port->setStopBits(AbstractSerial::StopBits1)) {
             qDebug() << "Set stop bits " <<  AbstractSerial::StopBits1 << " error.";
             return;
         }
     }
    else
    {
        if (!port->setStopBits(AbstractSerial::StopBits2)) {
            qDebug() << "Set stop bits " <<  AbstractSerial::StopBits2 << " error.";
            return;
        }
    }

     if (!port->setFlowControl(AbstractSerial::FlowControlOff)) {
         qDebug() << "Set flow " <<  AbstractSerial::FlowControlOff << " error.";
         return;
     }

     if (port->openMode() & AbstractSerial::Unbuffered)
         port->setTotalReadConstantTimeout(10);

      //port->setCharIntervalTimeout(int((8*1000000/com_dlg.ui->comboBox_2->currentText().toInt())));



      //timer->start(30);

      qDebug() << "Serial device : " << port->deviceName() << " opened!!!.";
      qDebug() << "Serial device baudrate : " << port->baudRate() ;
      qDebug() << "Serial device databits : " << port->dataBits() ;
      qDebug() << "Serial device stopbits : " << port->stopBits() ;
      qDebug() << "Serial device flowcontrol : " << port->flowControl() ;

      ActivateInterface();

      ui->action_connect->setText(tr("Отключить устройство"));
      p_uso->GET_DEV_INFO_REQ(device_addr);
  }

}

void MainWindow::on_action_set_chn_settings_triggered()
{
    for(quint8 i=0;i<adc_chn_num/*ui->tableWidget->rowCount()p_uso->DEV->channel_num*/;i++)
    {
        if(i<8)//настройки по аналоговым каналам
        {

            QComboBox *cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 11));
           if(cmb->currentIndex()==0)
           {
                chnl[i]->channel_type=0x3;//p_uso->CHN_ADC|0x3;
           }
           if(cmb->currentIndex()==1)
           {
               chnl[i]->channel_type=0x0;//p_uso->CHN_ADC&0xF0;
           }

           // chnl[i]->channel_type=p_uso->CHN_ADC;
           cmb=qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(i, 2));
            chnl[i]->state_byte1=0x40|cmb->currentIndex();

            QSpinBox *spin=qobject_cast<QSpinBox *>(ui->tableWidget->cellWidget(i, 3));
            //spin->setValue((quint8)p_uso->DEV->channel_mas[i]->state_byte2);
            chnl[i]->state_byte2=(quint8)spin->value();
        }
        else//настройки по частотным каналам
        {
           // chnl[i]->channel_type=p_uso->CHN_COUNT;
           // chnl[i]->state_byte1=0x40;//инициализация была
           // chnl[i]->state_byte2=0x0A;//инициализация была
        }

    }
    p_uso->CHANNEL_SET_PARAMETERS_REQ(device_addr,chnl);
    return;
}

void MainWindow::on_action_dev_polling_triggered()
{
    if(!read_flag)
    {
        timer->start(100);
        //Get_All_Data();//debug
        read_flag=true;
       // ui->pushButton_3->setText(tr("Остановить сбор данных"));
        ui->action_dev_polling->setText(tr("Остановить опрос устройства"));
    }
    else
    {
        timer->stop();
        read_flag=false;
       // ui->pushButton_3->setText(tr("Запустить сбор данных"));
        ui->action_dev_polling->setText(tr("Начать опрос устройства"));
    }
    return;
}

void MainWindow::on_action_set_dev_addr_triggered()
{
    d_info->show();
}


void MainWindow::on_dialog_set_dev_info(void)
{
    QByteArray ver;
    ver.append(d_info->get_dev_ver_text());
    p_uso->CHANNEL_SET_ADDRESS_DESC(device_addr,d_info->get_dev_addr(),d_info->get_dev_name_text(),ver,d_info->get_dev_descr_text());
}

void MainWindow::on_dialog_get_dev_info(void)
{
     p_uso->GET_DEV_INFO_REQ(device_addr);
}

void MainWindow::on_action_get_calibrate_triggered()
{
    p_uso->CHANNEL_GET_CALIBRATE_REQ(device_addr,0);
    chn_counter=1;
}

void MainWindow::on_get_calibrate_responsed(quint8 channel,quint8 calibrated, float K,float C)
{
    if(chn_counter<14)
    {
        p_uso->CHANNEL_GET_CALIBRATE_REQ(device_addr,chn_counter);
        chn_counter++;
    }
}
