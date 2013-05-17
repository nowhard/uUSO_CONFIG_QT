#include "connect_dialog.h"
#include "ui_connect_dialog.h"

connect_dialog::connect_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connect_dialog)
{
    ui->setupUi(this);
}

connect_dialog::~connect_dialog()
{
    delete ui;
}

void connect_dialog::on_pushButton_clicked()
{
    emit connect_device((quint8)(ui->comboBox->currentIndex()+1));
    this->hide();
}

void connect_dialog::on_pushButton_2_clicked()
{
    this->hide();
}
