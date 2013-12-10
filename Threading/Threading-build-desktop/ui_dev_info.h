/********************************************************************************
** Form generated from reading UI file 'dev_info.ui'
**
** Created: Mon 9. Dec 16:13:49 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEV_INFO_H
#define UI_DEV_INFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_dev_info
{
public:
    QGroupBox *groupBox_4;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QSpinBox *spinBox_2;
    QLabel *label_7;

    void setupUi(QDialog *dev_info)
    {
        if (dev_info->objectName().isEmpty())
            dev_info->setObjectName(QString::fromUtf8("dev_info"));
        dev_info->resize(379, 159);
        groupBox_4 = new QGroupBox(dev_info);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setEnabled(true);
        groupBox_4->setGeometry(QRect(10, 0, 361, 151));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 120, 91, 21));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 51, 16));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 51, 16));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 60, 51, 16));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(180, 120, 91, 21));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 20, 251, 20));
        lineEdit_2->setMaxLength(20);
        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 40, 251, 20));
        lineEdit_3->setMaxLength(40);
        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(90, 60, 251, 20));
        lineEdit_4->setMaxLength(5);
        spinBox_2 = new QSpinBox(groupBox_4);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(90, 90, 46, 22));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(15);
        spinBox_2->setValue(1);
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 90, 51, 20));

        retranslateUi(dev_info);

        QMetaObject::connectSlotsByName(dev_info);
    } // setupUi

    void retranslateUi(QDialog *dev_info)
    {
        dev_info->setWindowTitle(QApplication::translate("dev_info", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276\320\261 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("dev_info", "\320\236\320\261\321\211\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276\320\261 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\265", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("dev_info", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dev_info", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dev_info", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dev_info", "\320\222\320\265\321\200\321\201\320\270\321\217", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("dev_info", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("dev_info", "\320\220\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dev_info: public Ui_dev_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEV_INFO_H
