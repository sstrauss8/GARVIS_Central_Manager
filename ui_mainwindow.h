/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_home;
    QCalendarWidget *calendarWidget;
    QPushButton *startUART_Button;
    QTextEdit *UART_text;
    QWidget *tab_roommgr;
    QLabel *label_room;
    QComboBox *comboBox;
    QLineEdit *roomEdit;
    QGroupBox *groupbox_dev1;
    QLabel *dev1_name;
    QLabel *dev1_id;
    QSlider *dev1_slider;
    QLabel *off_label;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QGroupBox *groupbox_dev1_2;
    QLabel *dev1_name_2;
    QLabel *dev1_id_2;
    QSlider *dev1_slider_2;
    QLabel *off_label_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *dev1_name_3;
    QLabel *dev1_id_3;
    QGroupBox *groupbox_dev1_3;
    QSlider *dev1_slider_3;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *off_label_3;
    QLabel *dev1_name_4;
    QLabel *dev1_id_4;
    QFrame *line;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLineEdit *lineEdit_10;
    QWidget *tab_setupconfig;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_selectRoom1;
    QPushButton *pushButton_4;
    QProgressBar *progressBar;
    QTableWidget *tableWidget;
    QPushButton *pushButton_5;
    QLabel *label_12;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QComboBox *comboBox_selectRoom2;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_7;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox_5;
    QGroupBox *groupBox_5;
    QLineEdit *textBox_newRoom;
    QPushButton *button_NewRoom;
    QGroupBox *groupBox_6;
    QDateTimeEdit *dateTimeEdit;
    QWidget *tab_help;
    QGroupBox *groupBox_7;
    QPushButton *helpTutorial_button;
    QLineEdit *lineEdit_12;
    QLabel *dev1_id_5;
    QLabel *dev1_id_6;
    QLabel *dev1_id_7;
    QGroupBox *groupBox_8;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_6;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow{\n"
"background: rgb(63, 13, 14);\n"
"}\n"
"\n"
"#tabWidget{s\n"
"background: rgb(63, 13, 14);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 80, 781, 331));
        tabWidget->setStyleSheet(QString::fromUtf8("#tabWidget{\n"
"background: rgb(164, 137, 0)\n"
"}"));
        tab_home = new QWidget();
        tab_home->setObjectName(QString::fromUtf8("tab_home"));
        calendarWidget = new QCalendarWidget(tab_home);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(280, 110, 451, 172));
        calendarWidget->setGridVisible(true);
        calendarWidget->setDateEditEnabled(false);
        calendarWidget->setDateEditAcceptDelay(1500);
        startUART_Button = new QPushButton(tab_home);
        startUART_Button->setObjectName(QString::fromUtf8("startUART_Button"));
        startUART_Button->setGeometry(QRect(80, 50, 99, 27));
        UART_text = new QTextEdit(tab_home);
        UART_text->setObjectName(QString::fromUtf8("UART_text"));
        UART_text->setGeometry(QRect(20, 100, 221, 161));
        tabWidget->addTab(tab_home, QString());
        tab_roommgr = new QWidget();
        tab_roommgr->setObjectName(QString::fromUtf8("tab_roommgr"));
        label_room = new QLabel(tab_roommgr);
        label_room->setObjectName(QString::fromUtf8("label_room"));
        label_room->setGeometry(QRect(20, 50, 91, 17));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(159, 158, 158, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label_room->setPalette(palette);
        comboBox = new QComboBox(tab_roommgr);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 50, 191, 27));
        roomEdit = new QLineEdit(tab_roommgr);
        roomEdit->setObjectName(QString::fromUtf8("roomEdit"));
        roomEdit->setGeometry(QRect(242, 10, 151, 31));
        QFont font;
        font.setPointSize(16);
        roomEdit->setFont(font);
        groupbox_dev1 = new QGroupBox(tab_roommgr);
        groupbox_dev1->setObjectName(QString::fromUtf8("groupbox_dev1"));
        groupbox_dev1->setGeometry(QRect(20, 90, 171, 181));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        groupbox_dev1->setPalette(palette1);
        dev1_name = new QLabel(groupbox_dev1);
        dev1_name->setObjectName(QString::fromUtf8("dev1_name"));
        dev1_name->setGeometry(QRect(10, 40, 41, 17));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        dev1_name->setPalette(palette2);
        dev1_id = new QLabel(groupbox_dev1);
        dev1_id->setObjectName(QString::fromUtf8("dev1_id"));
        dev1_id->setGeometry(QRect(10, 70, 41, 17));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        dev1_id->setPalette(palette3);
        dev1_slider = new QSlider(groupbox_dev1);
        dev1_slider->setObjectName(QString::fromUtf8("dev1_slider"));
        dev1_slider->setGeometry(QRect(10, 90, 141, 29));
        dev1_slider->setOrientation(Qt::Horizontal);
        off_label = new QLabel(groupbox_dev1);
        off_label->setObjectName(QString::fromUtf8("off_label"));
        off_label->setGeometry(QRect(10, 120, 151, 20));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        off_label->setPalette(palette4);
        pushButton = new QPushButton(groupbox_dev1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 150, 111, 27));
        lineEdit = new QLineEdit(groupbox_dev1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(60, 30, 101, 27));
        lineEdit_2 = new QLineEdit(groupbox_dev1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 60, 101, 27));
        groupbox_dev1_2 = new QGroupBox(tab_roommgr);
        groupbox_dev1_2->setObjectName(QString::fromUtf8("groupbox_dev1_2"));
        groupbox_dev1_2->setGeometry(QRect(200, 90, 171, 181));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        groupbox_dev1_2->setPalette(palette5);
        dev1_name_2 = new QLabel(groupbox_dev1_2);
        dev1_name_2->setObjectName(QString::fromUtf8("dev1_name_2"));
        dev1_name_2->setGeometry(QRect(10, 40, 41, 17));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        dev1_name_2->setPalette(palette6);
        dev1_id_2 = new QLabel(groupbox_dev1_2);
        dev1_id_2->setObjectName(QString::fromUtf8("dev1_id_2"));
        dev1_id_2->setGeometry(QRect(10, 70, 41, 17));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        dev1_id_2->setPalette(palette7);
        dev1_slider_2 = new QSlider(groupbox_dev1_2);
        dev1_slider_2->setObjectName(QString::fromUtf8("dev1_slider_2"));
        dev1_slider_2->setGeometry(QRect(10, 90, 141, 29));
        dev1_slider_2->setOrientation(Qt::Horizontal);
        off_label_2 = new QLabel(groupbox_dev1_2);
        off_label_2->setObjectName(QString::fromUtf8("off_label_2"));
        off_label_2->setGeometry(QRect(10, 120, 151, 20));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        off_label_2->setPalette(palette8);
        pushButton_2 = new QPushButton(groupbox_dev1_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 150, 111, 27));
        lineEdit_3 = new QLineEdit(groupbox_dev1_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 30, 101, 27));
        lineEdit_4 = new QLineEdit(groupbox_dev1_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(60, 60, 101, 27));
        dev1_name_3 = new QLabel(groupbox_dev1_2);
        dev1_name_3->setObjectName(QString::fromUtf8("dev1_name_3"));
        dev1_name_3->setGeometry(QRect(190, 40, 41, 17));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        dev1_name_3->setPalette(palette9);
        dev1_id_3 = new QLabel(groupbox_dev1_2);
        dev1_id_3->setObjectName(QString::fromUtf8("dev1_id_3"));
        dev1_id_3->setGeometry(QRect(190, 60, 41, 17));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        dev1_id_3->setPalette(palette10);
        groupbox_dev1_3 = new QGroupBox(tab_roommgr);
        groupbox_dev1_3->setObjectName(QString::fromUtf8("groupbox_dev1_3"));
        groupbox_dev1_3->setGeometry(QRect(380, 90, 171, 181));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupbox_dev1_3->setPalette(palette11);
        dev1_slider_3 = new QSlider(groupbox_dev1_3);
        dev1_slider_3->setObjectName(QString::fromUtf8("dev1_slider_3"));
        dev1_slider_3->setGeometry(QRect(10, 90, 141, 29));
        dev1_slider_3->setOrientation(Qt::Horizontal);
        pushButton_3 = new QPushButton(groupbox_dev1_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 150, 111, 27));
        lineEdit_5 = new QLineEdit(groupbox_dev1_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(60, 30, 101, 27));
        lineEdit_6 = new QLineEdit(groupbox_dev1_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(60, 60, 101, 27));
        off_label_3 = new QLabel(groupbox_dev1_3);
        off_label_3->setObjectName(QString::fromUtf8("off_label_3"));
        off_label_3->setGeometry(QRect(10, 120, 151, 20));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        off_label_3->setPalette(palette12);
        dev1_name_4 = new QLabel(groupbox_dev1_3);
        dev1_name_4->setObjectName(QString::fromUtf8("dev1_name_4"));
        dev1_name_4->setGeometry(QRect(10, 40, 41, 17));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        dev1_name_4->setPalette(palette13);
        dev1_id_4 = new QLabel(groupbox_dev1_3);
        dev1_id_4->setObjectName(QString::fromUtf8("dev1_id_4"));
        dev1_id_4->setGeometry(QRect(10, 70, 41, 17));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        dev1_id_4->setPalette(palette14);
        line = new QFrame(tab_roommgr);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(550, 0, 20, 311));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(tab_roommgr);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(570, 90, 201, 181));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        groupBox->setPalette(palette15);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 21, 17));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_2->setPalette(palette16);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 91, 17));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_3->setPalette(palette17);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 67, 17));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_4->setPalette(palette18);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 130, 67, 17));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_5->setPalette(palette19);
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(100, 30, 71, 27));
        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(100, 60, 71, 27));
        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(100, 90, 71, 27));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(180, 120, 21, 22));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(180, 90, 21, 22));
        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(180, 60, 21, 22));
        checkBox_4 = new QCheckBox(groupBox);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(180, 30, 21, 22));
        lineEdit_10 = new QLineEdit(tab_roommgr);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(670, 210, 71, 27));
        tabWidget->addTab(tab_roommgr, QString());
        tab_setupconfig = new QWidget();
        tab_setupconfig->setObjectName(QString::fromUtf8("tab_setupconfig"));
        groupBox_2 = new QGroupBox(tab_setupconfig);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 261, 261));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        groupBox_2->setPalette(palette20);
        comboBox_selectRoom1 = new QComboBox(groupBox_2);
        comboBox_selectRoom1->setObjectName(QString::fromUtf8("comboBox_selectRoom1"));
        comboBox_selectRoom1->setGeometry(QRect(100, 30, 151, 27));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 70, 99, 31));
        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(130, 70, 118, 31));
        progressBar->setValue(24);
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 110, 231, 111));
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 230, 151, 27));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 30, 91, 17));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_12->setPalette(palette21);
        groupBox_3 = new QGroupBox(tab_setupconfig);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(290, 20, 261, 261));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        groupBox_3->setPalette(palette22);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 91, 17));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_7->setPalette(palette23);
        comboBox_selectRoom2 = new QComboBox(groupBox_3);
        comboBox_selectRoom2->setObjectName(QString::fromUtf8("comboBox_selectRoom2"));
        comboBox_selectRoom2->setGeometry(QRect(100, 30, 151, 27));
        tableWidget_2 = new QTableWidget(groupBox_3);
        if (tableWidget_2->columnCount() < 1)
            tableWidget_2->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_2->setItem(0, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setItem(2, 0, __qtablewidgetitem11);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(30, 110, 231, 111));
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(200);
        pushButton_7 = new QPushButton(groupBox_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(60, 230, 151, 27));
        groupBox_4 = new QGroupBox(tab_setupconfig);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(600, 10, 171, 51));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        groupBox_4->setPalette(palette24);
        checkBox_5 = new QCheckBox(groupBox_4);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(30, 20, 98, 22));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette25.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette25.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        checkBox_5->setPalette(palette25);
        checkBox_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"selection-color: rgb(255, 255, 255);"));
        groupBox_5 = new QGroupBox(tab_setupconfig);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(560, 90, 191, 101));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette26.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette26.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette26.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        groupBox_5->setPalette(palette26);
        textBox_newRoom = new QLineEdit(groupBox_5);
        textBox_newRoom->setObjectName(QString::fromUtf8("textBox_newRoom"));
        textBox_newRoom->setGeometry(QRect(10, 30, 161, 27));
        button_NewRoom = new QPushButton(groupBox_5);
        button_NewRoom->setObjectName(QString::fromUtf8("button_NewRoom"));
        button_NewRoom->setGeometry(QRect(40, 60, 99, 27));
        groupBox_6 = new QGroupBox(tab_setupconfig);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(560, 210, 211, 71));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox_6->setPalette(palette27);
        dateTimeEdit = new QDateTimeEdit(groupBox_6);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(10, 30, 194, 27));
        tabWidget->addTab(tab_setupconfig, QString());
        tab_help = new QWidget();
        tab_help->setObjectName(QString::fromUtf8("tab_help"));
        groupBox_7 = new QGroupBox(tab_help);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 30, 251, 241));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette28.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette28.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette28.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette28.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        groupBox_7->setPalette(palette28);
        helpTutorial_button = new QPushButton(groupBox_7);
        helpTutorial_button->setObjectName(QString::fromUtf8("helpTutorial_button"));
        helpTutorial_button->setGeometry(QRect(60, 200, 141, 27));
        lineEdit_12 = new QLineEdit(groupBox_7);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(100, 150, 113, 27));
        dev1_id_5 = new QLabel(groupBox_7);
        dev1_id_5->setObjectName(QString::fromUtf8("dev1_id_5"));
        dev1_id_5->setGeometry(QRect(10, 50, 221, 17));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette29.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette29.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette29.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette29.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        dev1_id_5->setPalette(palette29);
        dev1_id_6 = new QLabel(groupBox_7);
        dev1_id_6->setObjectName(QString::fromUtf8("dev1_id_6"));
        dev1_id_6->setGeometry(QRect(20, 80, 231, 17));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette30.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette30.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        dev1_id_6->setPalette(palette30);
        dev1_id_7 = new QLabel(groupBox_7);
        dev1_id_7->setObjectName(QString::fromUtf8("dev1_id_7"));
        dev1_id_7->setGeometry(QRect(20, 110, 231, 17));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette31.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette31.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette31.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        dev1_id_7->setPalette(palette31);
        groupBox_8 = new QGroupBox(tab_help);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(270, 30, 501, 241));
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette32.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette32.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette32.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette32.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        groupBox_8->setPalette(palette32);
        tabWidget->addTab(tab_help, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 10, 191, 51));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Ubuntu Condensed\";"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(660, 410, 141, 20));
        QPalette palette33;
        palette33.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette33.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette33.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_11->setPalette(palette33);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, -330, 771, 851));
        label_6->setPixmap(QPixmap(QString::fromUtf8("jarvishead3.jpg")));
        MainWindow->setCentralWidget(centralWidget);
        label_6->raise();
        label->raise();
        label_11->raise();
        tabWidget->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        startUART_Button->setText(QApplication::translate("MainWindow", "Start UART", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_home), QApplication::translate("MainWindow", "Home", 0, QApplication::UnicodeUTF8));
        label_room->setText(QApplication::translate("MainWindow", "Select Room", 0, QApplication::UnicodeUTF8));
        roomEdit->setText(QApplication::translate("MainWindow", "Current Room", 0, QApplication::UnicodeUTF8));
        groupbox_dev1->setTitle(QApplication::translate("MainWindow", "Device 1", 0, QApplication::UnicodeUTF8));
        dev1_name->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        dev1_id->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        off_label->setText(QApplication::translate("MainWindow", "Off                           On", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Set Thresholds", 0, QApplication::UnicodeUTF8));
        groupbox_dev1_2->setTitle(QApplication::translate("MainWindow", "Device 2", 0, QApplication::UnicodeUTF8));
        dev1_name_2->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        dev1_id_2->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        off_label_2->setText(QApplication::translate("MainWindow", "Off                           On", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Set Thresholds", 0, QApplication::UnicodeUTF8));
        dev1_name_3->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        dev1_id_3->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        groupbox_dev1_3->setTitle(QApplication::translate("MainWindow", "Device 3", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Set Thresholds", 0, QApplication::UnicodeUTF8));
        off_label_3->setText(QApplication::translate("MainWindow", "Off                           On", 0, QApplication::UnicodeUTF8));
        dev1_name_4->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        dev1_id_4->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Smart Switch", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Temperature", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Humidity", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Occupied", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        checkBox_3->setText(QString());
        checkBox_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_roommgr), QApplication::translate("MainWindow", "Room Manager", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Add New Device", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Detect", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Devices", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButton_5->setText(QApplication::translate("MainWindow", "Add Selected Device", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Select Room", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Delete Device", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Select Room", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Devices", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        tableWidget_2->setSortingEnabled(__sortingEnabled1);

        pushButton_7->setText(QApplication::translate("MainWindow", "Add Selected Device", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Smart Decision Mode", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("MainWindow", "Enabled", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Add New Room", 0, QApplication::UnicodeUTF8));
        textBox_newRoom->setPlaceholderText(QApplication::translate("MainWindow", "<Enter Room Name>", 0, QApplication::UnicodeUTF8));
        button_NewRoom->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Date and Time", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_setupconfig), QApplication::translate("MainWindow", "Setup and Configuration", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "How to Use", 0, QApplication::UnicodeUTF8));
        helpTutorial_button->setText(QApplication::translate("MainWindow", "Launch Tutorial", 0, QApplication::UnicodeUTF8));
        dev1_id_5->setText(QApplication::translate("MainWindow", "For a detailed outline of how to", 0, QApplication::UnicodeUTF8));
        dev1_id_6->setText(QApplication::translate("MainWindow", "use the GARVIS Central Manager", 0, QApplication::UnicodeUTF8));
        dev1_id_7->setText(QApplication::translate("MainWindow", "please use the following tutorial", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Tips and Tricks", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_help), QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu Condensed'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:36pt; color:#000000;\">GARVIS</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">2015 G.A.R.V.I.S. Team 23</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
