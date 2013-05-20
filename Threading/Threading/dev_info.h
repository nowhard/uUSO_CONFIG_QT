#ifndef DEV_INFO_H
#define DEV_INFO_H

#include <QDialog>
#include <QString>

namespace Ui {
class dev_info;
}

class dev_info : public QDialog
{
    Q_OBJECT
    
public:
    explicit dev_info(QWidget *parent = 0);
    ~dev_info();

    void    set_dev_name_text(QString name);
    QString get_dev_name_text(void);

    void    set_dev_descr_text(QString name);
    QString get_dev_descr_text(void);

    void    set_dev_ver_text(QString name);
    QString get_dev_ver_text(void);

    quint8  get_dev_addr(void);
    void    set_dev_addr(quint8 addr);
    
private:
    Ui::dev_info *ui;

signals:
    void get_dev_info(void);
    void set_dev_info(void);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
};

#endif // DEV_INFO_H
