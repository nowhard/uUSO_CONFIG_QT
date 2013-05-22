#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "com_thread.h"
#include <abstractserial.h>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include "serial_io.h"
#include "proto_uso.h"

#include "dialog_com.h"
#include "dev_info.h"
#include "connect_dialog.h"
#include "ui_dialog_com.h"

#include "delegate.h"
#include <QTextCodec>
#include <QStringList>
#include <QCheckBox>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QIODevice>
#include <QSettings>
#include <QVector>
#include <QPointF>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:


private:
    class CalibrPoints
    {
    public:
        unsigned long first_point_x;
        unsigned long first_point_y;
        unsigned long second_point_x;
        unsigned long second_point_y;
    };
    Ui::MainWindow *ui;

    //---------------------
    AbstractSerial *port;
   // Serial_IO *srl_io;

    proto_uso *p_uso;
    //---------------------
    //MB_Register reg_pack;
    //---------------------
    QTimer *timer;
  //  QTimer *timer2;
  //  QTimer *query_timer;
   // QFile settings;
    quint8 adc_chn_num;//количество аналоговых каналов

    //---------------------
    Dialog_com com_dlg;
    connect_dialog *connect_dlg;
    dev_info *d_info;



    bool read_flag;
    QStringList strlist, bitlist;
    CHANNEL *chnl[20];
    QVector<CalibrPoints*> CalibrList;

    quint8 device_addr;
    quint8 chn_counter;

private slots:

//    void on_pushButton_5_clicked();
//    void on_pushButton_2_clicked();
    void on_action_COM_triggered();


    void on_dev_info_responsed(void);
    void on_dev_get_data_responsed(void);
    void on_get_calibrate_responsed(quint8 channel,quint8 calibrated, float K,float C);

    void on_connect_device(quint8 dev_addr);

    void MessageReadOK(bool mess);
    void MessageWriteOK(bool mess);
    void MessageNotConnected(void);



    void Display_Dev_Info(bool OK,quint16 ID, QString Description);
    void Info_Is_Set(bool OK);
    void Get_All_Data(void);

    void UnactiveInterface(void);
    void ActivateInterface(void);

    void on_calibrate_0_button_clicked();
    void on_calibrate_full_button_clicked();
    void on_calibrate_flag_clicked();
    void on_calibrate_set_button_clicked();

    void on_menu_load_settings_clicked();
    void on_menu_save_settings_clicked();

    void on_action_Set_Settings_Default_triggered();
    void on_action_connect_triggered();
    void on_action_set_chn_settings_triggered();
    void on_action_dev_polling_triggered();
    void on_action_set_dev_addr_triggered();

    void on_dialog_set_dev_info(void);
    void on_dialog_get_dev_info(void);
    void on_action_get_calibrate_triggered();
};




#endif // MAINWINDOW_H
