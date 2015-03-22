/********************************************************************************
** Form generated from reading UI file 'setthresholds.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTHRESHOLDS_H
#define UI_SETTHRESHOLDS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetThresholds
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *setThresholdRoomEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *Apply;

    void setupUi(QDialog *SetThresholds)
    {
        if (SetThresholds->objectName().isEmpty())
            SetThresholds->setObjectName(QString::fromUtf8("SetThresholds"));
        SetThresholds->resize(373, 333);
        SetThresholds->setStyleSheet(QString::fromUtf8("#SetThresholds{\n"
"background: rgb(63, 13, 14);\n"
"}"));
        buttonBox = new QDialogButtonBox(SetThresholds);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(140, 300, 221, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SetThresholds);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 271, 17));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(SetThresholds);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 271, 17));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        setThresholdRoomEdit = new QLineEdit(SetThresholds);
        setThresholdRoomEdit->setObjectName(QString::fromUtf8("setThresholdRoomEdit"));
        setThresholdRoomEdit->setEnabled(true);
        setThresholdRoomEdit->setGeometry(QRect(100, 80, 181, 51));
        QFont font;
        font.setPointSize(16);
        setThresholdRoomEdit->setFont(font);
        setThresholdRoomEdit->setReadOnly(true);
        label_3 = new QLabel(SetThresholds);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 160, 101, 17));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(SetThresholds);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 190, 101, 17));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(SetThresholds);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 220, 101, 17));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(SetThresholds);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 160, 51, 27));
        label_6 = new QLabel(SetThresholds);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 140, 51, 17));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(SetThresholds);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 140, 51, 17));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(SetThresholds);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(190, 160, 51, 17));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(SetThresholds);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 160, 51, 17));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_3 = new QLineEdit(SetThresholds);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(260, 160, 51, 27));
        lineEdit_4 = new QLineEdit(SetThresholds);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 190, 51, 27));
        lineEdit_5 = new QLineEdit(SetThresholds);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(260, 190, 51, 27));
        lineEdit_6 = new QLineEdit(SetThresholds);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(140, 220, 51, 27));
        lineEdit_7 = new QLineEdit(SetThresholds);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(260, 220, 51, 27));
        label_10 = new QLabel(SetThresholds);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(200, 190, 21, 17));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(SetThresholds);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(320, 190, 21, 17));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_12 = new QLabel(SetThresholds);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(200, 220, 51, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_13 = new QLabel(SetThresholds);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(320, 220, 51, 20));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Apply = new QPushButton(SetThresholds);
        Apply->setObjectName(QString::fromUtf8("Apply"));
        Apply->setGeometry(QRect(10, 300, 99, 27));

        retranslateUi(SetThresholds);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetThresholds, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetThresholds, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetThresholds);
    } // setupUi

    void retranslateUi(QDialog *SetThresholds)
    {
        SetThresholds->setWindowTitle(QApplication::translate("SetThresholds", "Set Threshold", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SetThresholds", "Set the minimum and maximum values", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SetThresholds", "for the following room.", 0, QApplication::UnicodeUTF8));
        setThresholdRoomEdit->setText(QApplication::translate("SetThresholds", "Bedroom 1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("SetThresholds", "<html><head/><body><p>Allowable range from 32 to 120  \302\260F</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("SetThresholds", "Temperature", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SetThresholds", "Humidity", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SetThresholds", "Lighting", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SetThresholds", "Min", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SetThresholds", "Max", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("SetThresholds", " \302\260F", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SetThresholds", " \302\260F", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SetThresholds", "%", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SetThresholds", "%", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SetThresholds", "lumens", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SetThresholds", "lumens", 0, QApplication::UnicodeUTF8));
        Apply->setText(QApplication::translate("SetThresholds", "Apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetThresholds: public Ui_SetThresholds {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTHRESHOLDS_H
