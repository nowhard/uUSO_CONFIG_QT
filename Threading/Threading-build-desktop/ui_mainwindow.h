/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 17. May 15:24:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_COM;
    QAction *action;
    QAction *action_SAVE;
    QAction *action_LOAD;
    QAction *action_Set_Settings_Default;
    QAction *action_connect;
    QAction *action_set_chn_settings;
    QAction *action_dev_polling;
    QWidget *centralWidget;
    QGroupBox *groupBox_3;
    QTableWidget *tableWidget;
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
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(950, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(950, 620));
        MainWindow->setMaximumSize(QSize(950, 620));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferDefault);
        MainWindow->setFont(font);
        action_COM = new QAction(MainWindow);
        action_COM->setObjectName(QString::fromUtf8("action_COM"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_SAVE = new QAction(MainWindow);
        action_SAVE->setObjectName(QString::fromUtf8("action_SAVE"));
        action_LOAD = new QAction(MainWindow);
        action_LOAD->setObjectName(QString::fromUtf8("action_LOAD"));
        action_Set_Settings_Default = new QAction(MainWindow);
        action_Set_Settings_Default->setObjectName(QString::fromUtf8("action_Set_Settings_Default"));
        action_connect = new QAction(MainWindow);
        action_connect->setObjectName(QString::fromUtf8("action_connect"));
        action_set_chn_settings = new QAction(MainWindow);
        action_set_chn_settings->setObjectName(QString::fromUtf8("action_set_chn_settings"));
        action_dev_polling = new QAction(MainWindow);
        action_dev_polling->setObjectName(QString::fromUtf8("action_dev_polling"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 170, 931, 401));
        tableWidget = new QTableWidget(groupBox_3);
        if (tableWidget->columnCount() < 12)
            tableWidget->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 911, 371));
        tableWidget->setMouseTracking(false);
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Raised);
        tableWidget->setTabKeyNavigation(true);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget->setDragEnabled(false);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(12);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setEnabled(true);
        groupBox_4->setGeometry(QRect(10, 10, 561, 151));
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
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_connect);
        menu->addAction(action_COM);
        menu_2->addAction(action_Set_Settings_Default);
        menu_2->addAction(action_SAVE);
        menu_2->addAction(action_LOAD);
        menu_2->addAction(action_set_chn_settings);
        menu_3->addAction(action_dev_polling);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "uUSO.\320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
        action_COM->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 COM \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        action_SAVE->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        action_LOAD->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        action_Set_Settings_Default->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272", 0, QApplication::UnicodeUTF8));
        action_connect->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        action_set_chn_settings->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\272\320\260\320\275\320\260\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
        action_dev_polling->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\276\320\277\321\200\320\276\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\272\320\260\320\275\320\260\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\211\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276\320\261 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\265", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\201\320\270\321\217", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\321\200\320\276\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
