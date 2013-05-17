#ifndef CONNECT_DIALOG_H
#define CONNECT_DIALOG_H

#include <QDialog>

namespace Ui {
class connect_dialog;
}

class connect_dialog : public QDialog
{
    Q_OBJECT

signals:
    void connect_device(quint8 dev_addr);//сигнал на подключение устройства

public:
    explicit connect_dialog(QWidget *parent = 0);
    ~connect_dialog();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::connect_dialog *ui;


};

#endif // CONNECT_DIALOG_H
