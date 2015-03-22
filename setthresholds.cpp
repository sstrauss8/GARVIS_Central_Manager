#include "setthresholds.h"
#include "ui_setthresholds.h"
#include <QMessageBox>

SetThresholds::SetThresholds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetThresholds)
{
    ui->setupUi(this);
    memset(correctValues, 0, sizeof(correctValues));
    minTempGreaterThanMax = false;
    minHumGreaterThanMax = false;
    minLightGreaterThanMax = false;

    p_IOControl = IOManager::Instance();

    ui->setThresholdRoomEdit->setText(p_IOControl->currentRoomManagerRoom->roomName);
    ui->lineEdit_2->setText(QString::number(p_IOControl->currentRoomManagerRoom->minTemp));
    ui->lineEdit_3->setText(QString::number(p_IOControl->currentRoomManagerRoom->maxTemp));
    ui->lineEdit_4->setText(QString::number(p_IOControl->currentRoomManagerRoom->minHum));
    ui->lineEdit_5->setText(QString::number(p_IOControl->currentRoomManagerRoom->maxHum));
    ui->lineEdit_6->setText(QString::number(p_IOControl->currentRoomManagerRoom->minLight));
    ui->lineEdit_7->setText(QString::number(p_IOControl->currentRoomManagerRoom->maxLight));

    palette = ui->lineEdit_2->palette();
    palette2 = ui->lineEdit_3->palette();
    palette3 = ui->lineEdit_4->palette();
    palette4 = ui->lineEdit_5->palette();
    palette5 = ui->lineEdit_6->palette();
    palette6 = ui->lineEdit_7->palette();

    validator = new QIntValidator(0, 9999, this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_6->setValidator(validator);
    ui->lineEdit_7->setValidator(validator);
}

SetThresholds::~SetThresholds()
{
    delete ui;
}

void SetThresholds::on_lineEdit_2_textEdited(const QString &arg1)
{
    int currentMinTemp = ui->lineEdit_2->text().toInt(0,10);
    int currentMaxTemp = ui->lineEdit_3->text().toInt(0,10);

    if(currentMinTemp > currentMaxTemp && ui->lineEdit_3->text() != "")
    {
        palette.setColor(QPalette::Base, QColor(255,0,0)); //Red
        palette2.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[0] = 1;
        correctValues[1] = 1;
        ui->lineEdit_2->setPalette(palette);
        ui->lineEdit_3->setPalette(palette2);
        CheckForValidity();
        return;
    }
    else
    {
        palette.setColor(QPalette::Base, QColor(0,255,0)); //Green
        palette2.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[0] = 0;
        correctValues[1] = 0;
    }

    if(currentMinTemp < 32 || currentMinTemp > 120)
    {
        palette.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[0] = 1;
    }
    else
    {
        palette.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[0] = 0;
    }

    if(currentMaxTemp < 32 || currentMaxTemp > 120)
    {
        palette2.setColor(QPalette::Base, QColor(255,0,0)); //Green
        correctValues[1] = 1;
    }
    else
    {
        palette2.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[1] = 0;
    }

    if(ui->lineEdit_2->text() == "")
    {
        palette.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[0] = 0;
    }

    if(ui->lineEdit_3->text() == "")
    {
        palette2.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[1] = 0;
    }

    ui->lineEdit_2->setPalette(palette);
    ui->lineEdit_3->setPalette(palette2);
    CheckForValidity();
}

void SetThresholds::on_lineEdit_3_textEdited(const QString &arg1)
{
    int currentMinTemp = ui->lineEdit_2->text().toInt(0,10);
    int currentMaxTemp = ui->lineEdit_3->text().toInt(0,10);

    if(currentMinTemp > currentMaxTemp && ui->lineEdit_3->text() != "")
    {
        palette.setColor(QPalette::Base, QColor(255,0,0)); //Red
        palette2.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[0] = 1;
        correctValues[1] = 1;
        ui->lineEdit_2->setPalette(palette);
        ui->lineEdit_3->setPalette(palette2);
        CheckForValidity();
        return;
    }
    else
    {
        palette.setColor(QPalette::Base, QColor(0,255,0)); //Green
        palette2.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[0] = 0;
        correctValues[1] = 0;
    }

    if(currentMinTemp < 32 || currentMinTemp > 120)
    {
        palette.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[0] = 1;
    }
    else
    {
        palette.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[0] = 0;
    }

    if(currentMaxTemp < 32 || currentMaxTemp > 120)
    {
        palette2.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[1] = 1;
    }
    else
    {
        palette2.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[1] = 0;
    }

    if(ui->lineEdit_2->text() == "")
    {
        palette.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[0] = 0;
    }

    if(ui->lineEdit_3->text() == "")
    {
        palette2.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[1] = 0;
    }

    ui->lineEdit_2->setPalette(palette);
    ui->lineEdit_3->setPalette(palette2);
    CheckForValidity();
}

void SetThresholds::on_lineEdit_4_textEdited(const QString &arg1)
{
    int currentMinHum = ui->lineEdit_4->text().toInt(0,10);
    int currentMaxHum = ui->lineEdit_5->text().toInt(0,10);

    if(currentMinHum > currentMaxHum && ui->lineEdit_5->text() != "")
    {
        palette3.setColor(QPalette::Base, QColor(255,0,0)); //Red
        palette4.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[2] = 1;
        correctValues[3] = 1;
        ui->lineEdit_4->setPalette(palette3);
        ui->lineEdit_5->setPalette(palette4);
        CheckForValidity();
        return;
    }
    else
    {
        palette3.setColor(QPalette::Base, QColor(0,255,0)); //Green
        palette4.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[2] = 0;
        correctValues[3] = 0;
    }

    if(currentMinHum < 0 || currentMinHum > 100)
    {
        palette3.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[2] = 1;
    }
    else
    {
        palette3.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[2] = 0;
    }

    if(currentMaxHum < 0 || currentMaxHum > 100)
    {
        palette4.setColor(QPalette::Base, QColor(255,0,0)); //Green
        correctValues[3] = 1;
    }
    else
    {
        palette4.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[3] = 0;
    }

    if(ui->lineEdit_4->text() == "")
    {
        palette3.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[2] = 0;
    }

    if(ui->lineEdit_5->text() == "")
    {
        palette4.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[3] = 0;
    }

    ui->lineEdit_4->setPalette(palette3);
    ui->lineEdit_5->setPalette(palette4);
    CheckForValidity();
}

void SetThresholds::on_lineEdit_5_textEdited(const QString &arg1)
{
    int currentMinHum = ui->lineEdit_4->text().toInt(0,10);
    int currentMaxHum = ui->lineEdit_5->text().toInt(0,10);

    if(currentMinHum > currentMaxHum && ui->lineEdit_5->text() != "")
    {
        palette3.setColor(QPalette::Base, QColor(255,0,0)); //Red
        palette4.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[2] = 1;
        correctValues[3] = 1;
        ui->lineEdit_4->setPalette(palette3);
        ui->lineEdit_5->setPalette(palette4);
        CheckForValidity();
        return;
    }
    else
    {
        palette3.setColor(QPalette::Base, QColor(0,255,0)); //Green
        palette4.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[2] = 0;
        correctValues[3] = 0;
    }

    if(currentMinHum < 0 || currentMinHum > 100)
    {
        palette3.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[2] = 1;
    }
    else
    {
        palette3.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[2] = 0;
    }

    if(currentMaxHum < 0 || currentMaxHum > 100)
    {
        palette4.setColor(QPalette::Base, QColor(255,0,0)); //Green
        correctValues[3] = 1;
    }
    else
    {
        palette4.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[3] = 0;
    }

    if(ui->lineEdit_4->text() == "")
    {
        palette3.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[2] = 0;
    }

    if(ui->lineEdit_5->text() == "")
    {
        palette4.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[3] = 0;
    }

    ui->lineEdit_4->setPalette(palette3);
    ui->lineEdit_5->setPalette(palette4);
    CheckForValidity();
}

void SetThresholds::on_lineEdit_6_textEdited(const QString &arg1)
{
    int currentMinLight = ui->lineEdit_6->text().toInt(0,10);
    int currentMaxLight = ui->lineEdit_7->text().toInt(0,10);

    if(currentMinLight > currentMaxLight && ui->lineEdit_7->text() != "")
    {
        palette5.setColor(QPalette::Base, QColor(255,0,0)); //Red
        palette6.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[4] = 1;
        correctValues[5] = 1;
        ui->lineEdit_6->setPalette(palette5);
        ui->lineEdit_7->setPalette(palette6);
        CheckForValidity();
        return;
    }
    else
    {
        palette5.setColor(QPalette::Base, QColor(0,255,0)); //Green
        palette6.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[4] = 0;
        correctValues[5] = 0;
    }

    if(currentMinLight < 0 || currentMinLight > 100)
    {
        palette5.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[4] = 1;
    }
    else
    {
        palette5.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[4] = 0;
    }

    if(currentMaxLight < 0 || currentMaxLight > 100)
    {
        palette6.setColor(QPalette::Base, QColor(255,0,0)); //Green
        correctValues[5] = 1;
    }
    else
    {
        palette6.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[5] = 0;
    }

    if(ui->lineEdit_6->text() == "")
    {
        palette5.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[4] = 0;
    }

    if(ui->lineEdit_7->text() == "")
    {
        palette6.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[5] = 0;
    }

    ui->lineEdit_6->setPalette(palette5);
    ui->lineEdit_7->setPalette(palette6);
    CheckForValidity();
}

void SetThresholds::on_lineEdit_7_textEdited(const QString &arg1)
{
    int currentMinLight = ui->lineEdit_6->text().toInt(0,10);
    int currentMaxLight = ui->lineEdit_7->text().toInt(0,10);

    if(currentMinLight > currentMaxLight && ui->lineEdit_7->text() != "")
    {
        palette5.setColor(QPalette::Base, QColor(255,0,0)); //Red
        palette6.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[4] = 1;
        correctValues[5] = 1;
        ui->lineEdit_6->setPalette(palette5);
        ui->lineEdit_7->setPalette(palette6);
        CheckForValidity();
        return;
    }
    else
    {
        palette5.setColor(QPalette::Base, QColor(0,255,0)); //Green
        palette6.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[4] = 0;
        correctValues[5] = 0;
    }

    if(currentMinLight < 0 || currentMinLight > 100)
    {
        palette5.setColor(QPalette::Base, QColor(255,0,0)); //Red
        correctValues[4] = 1;
    }
    else
    {
        palette5.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[4] = 0;
    }

    if(currentMaxLight < 0 || currentMaxLight > 100)
    {
        palette6.setColor(QPalette::Base, QColor(255,0,0)); //Green
        correctValues[5] = 1;
    }
    else
    {
        palette6.setColor(QPalette::Base, QColor(0,255,0)); //Green
        correctValues[5] = 0;
    }

    if(ui->lineEdit_6->text() == "")
    {
        palette5.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[4] = 0;
    }

    if(ui->lineEdit_7->text() == "")
    {
        palette6.setColor(QPalette::Base, QColor(255,255,255)); //White
        correctValues[5] = 0;
    }

    ui->lineEdit_6->setPalette(palette5);
    ui->lineEdit_7->setPalette(palette6);
    CheckForValidity();
}

void SetThresholds::CheckForValidity()
{
    for(int i = 0; i < 6; i++)
    {
        if(correctValues[i])
        {
            ui->Apply->setEnabled(false);
            return;
        }
    }

    ui->Apply->setEnabled(true);
}

void SetThresholds::on_buttonBox_accepted()
{
    QMessageBox msgBox;
    msgBox.setText("Only applied changes will be saved");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
}

void SetThresholds::on_Apply_clicked()
{
    p_IOControl->setThresholds(ui->lineEdit_2->text().toInt(0,10),
                               ui->lineEdit_3->text().toInt(0,10),
                               ui->lineEdit_4->text().toInt(0,10),
                               ui->lineEdit_5->text().toInt(0,10),
                               ui->lineEdit_6->text().toInt(0,10),
                               ui->lineEdit_7->text().toInt(0,10));
}
