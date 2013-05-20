#include "dev_info.h"
#include "ui_dev_info.h"

dev_info::dev_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dev_info)
{
    ui->setupUi(this);
}

dev_info::~dev_info()
{
    delete ui;
}

void    dev_info::set_dev_name_text(QString name)
{
    ui->lineEdit_2->setText(name);
}

QString dev_info::get_dev_name_text(void)
{
    return ui->lineEdit_2->text();
}

void    dev_info::set_dev_descr_text(QString name)
{
    ui->lineEdit_3->setText(name);
}

QString dev_info::get_dev_descr_text(void)
{
    return ui->lineEdit_3->text();
}

void    dev_info::set_dev_ver_text(QString name)
{
    ui->lineEdit_4->setText(name);
}

QString dev_info::get_dev_ver_text(void)
{
    return ui->lineEdit_4->text();
}

void dev_info::on_pushButton_2_clicked()
{
    emit get_dev_info();
}

void dev_info::on_pushButton_5_clicked()
{
    emit set_dev_info();
}

quint8  dev_info::get_dev_addr(void)
{
    return (quint8)ui->spinBox_2->value();
}

void    dev_info::set_dev_addr(quint8 addr)
{
    ui->spinBox_2->setValue(addr);
}
