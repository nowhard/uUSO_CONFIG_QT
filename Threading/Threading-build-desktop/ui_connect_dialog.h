/********************************************************************************
** Form generated from reading UI file 'connect_dialog.ui'
**
** Created: Mon 20. May 13:16:42 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_DIALOG_H
#define UI_CONNECT_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_connect_dialog
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QDialog *connect_dialog)
    {
        if (connect_dialog->objectName().isEmpty())
            connect_dialog->setObjectName(QString::fromUtf8("connect_dialog"));
        connect_dialog->resize(316, 156);
        groupBox = new QGroupBox(connect_dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 301, 141));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 110, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 110, 75, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 161, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(233, 60, 61, 22));

        retranslateUi(connect_dialog);

        QMetaObject::connectSlotsByName(connect_dialog);
    } // setupUi

    void retranslateUi(QDialog *connect_dialog)
    {
        connect_dialog->setWindowTitle(QApplication::translate("connect_dialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("connect_dialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("connect_dialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("connect_dialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("connect_dialog", "\320\220\320\264\321\200\320\265\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("connect_dialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("connect_dialog", "15", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class connect_dialog: public Ui_connect_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_DIALOG_H
