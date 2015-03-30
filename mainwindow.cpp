#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QDateTime>
#include <iostream>
#include "setthresholds.h"
#include "helpdialog.h"
#include "tutorialwizard.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_CommandCreator(),
    m_GloveAPI()
{
    p_IOControl = IOManager::Instance();
    m_CommandCreator.start();
    m_GloveAPI.start();

    smartDecisionMode = false;
    fakeDeviceID = 0;

    QMessageBox msgBox;
    //ui->comboBox_deleteroomlist
    msgBox.setText("Previous Configuration");
    msgBox.setInformativeText("Would you like to load your previous configuration file?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch (ret)
    {
       case QMessageBox::Yes:
           // Yes was clicked
           p_IOControl->ReadConfigFile();
           break;
       case QMessageBox::No:
           // No was clicked
           p_IOControl->ClearConfigFile();
           break;
       case QMessageBox::Cancel:
           // Cancel was clicked
           break;
       default:
           // should never be reached
           break;
     }

    ui->setupUi(this);
    output = "";
    counter = 0;

    ui->dateEdit->setDate(QDate::currentDate());

    p_IOControl->startUART();

    populateRoomNames();
}

MainWindow::~MainWindow()
{
    m_CommandCreator.exit();
    m_GloveAPI.exit();
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->roomEdit->setText(ui->comboBox->currentText());

    changeLoadControllers();

    p_IOControl->setCurrentRoomManagerRoom(ui->comboBox->currentIndex());

    //QString::compare("", p_IOControl->getDeviceName(ui->comboBox->currentIndex(),0), Qt::CaseInsensitive) == 0)
    if(ui->comboBox_loadController->count() == 0)
    {
        ui->groupbox_dev1->setDisabled(true);
        ui->groupbox_dev1_2->setDisabled(true);
        ui->groupbox_dev1_3->setDisabled(true);
    }
    else
    {
        ui->groupbox_dev1->setDisabled(false);
        ui->groupbox_dev1_2->setDisabled(false);
        ui->groupbox_dev1_3->setDisabled(false);
    }

    populateDevices(ui->comboBox->currentIndex(), ui->comboBox_loadController->currentText().toInt(0,10));
}

void MainWindow::on_button_NewRoom_clicked()
{
    if(ui->textBox_newRoom->text().isEmpty())
    {
        return;
    }

    if(p_IOControl->addRoom(ui->textBox_newRoom->text()))
    {
        populateRoomNames();
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), "Please enter a valid room name");
    }

    ui->textBox_newRoom->setText("");

}

void MainWindow::on_button_deleteRoom_clicked()
{
     //TODO: Figure out why it sometimes segfaults when deleting last room
     QMessageBox msgBox;
     //ui->comboBox_deleteroomlist
     msgBox.setText("Delete Room");
     msgBox.setInformativeText("Are you sure you want to delete the selected room?");
     msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
     msgBox.setDefaultButton(QMessageBox::Cancel);
     int ret = msgBox.exec();

     int numberRooms = p_IOControl->getNumRooms();

     switch (ret)
     {
        case QMessageBox::Yes:
            // Yes was clicked
            if(p_IOControl->deleteRoom(ui->comboBox_deleteroomlist->currentIndex()))
                populateRoomNames();
            break;
        case QMessageBox::No:
            // No was clicked
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        default:
            // should never be reached
            break;
      }

}

void MainWindow::populateRoomNames()
{
    //Populate necessary comboboxes with new room

    ui->comboBox->clear();
    ui->comboBox_selectRoom1->clear();
    ui->comboBox_selectRoom2->clear();
    ui->comboBox_deleteroomlist->clear();

    int numberRooms = p_IOControl->getNumRooms();

    for(int i = 0; i < numberRooms; i++)
    {
        ui->comboBox->addItem(p_IOControl->getRoom(i));
        ui->comboBox_selectRoom1->addItem(p_IOControl->getRoom(i));
        ui->comboBox_selectRoom2->addItem(p_IOControl->getRoom(i));
        ui->comboBox_deleteroomlist->addItem(p_IOControl->getRoom(i));
    }
}

void MainWindow::populateDevices(int roomIndex, int loadControllerIndex)
{
    ui->device1Name->setText(p_IOControl->getDeviceName(roomIndex, 0, loadControllerIndex));
    ui->device1ID->setText(p_IOControl->getDevice(roomIndex, 0, loadControllerIndex));
    ui->dev1_slider->setValue(p_IOControl->getDevicePercent(roomIndex, 0, loadControllerIndex));

    ui->device2Name->setText(p_IOControl->getDeviceName(roomIndex, 1, loadControllerIndex));
    ui->device2ID->setText(p_IOControl->getDevice(roomIndex, 1, loadControllerIndex));
    ui->dev2_slider->setValue(p_IOControl->getDevicePercent(roomIndex, 1, loadControllerIndex));

    ui->device3Name->setText(p_IOControl->getDeviceName(roomIndex, 2, loadControllerIndex));
    ui->device3ID->setText(p_IOControl->getDevice(roomIndex, 2, loadControllerIndex));
    ui->dev3_slider->setValue(p_IOControl->getDevicePercent(roomIndex, 2, loadControllerIndex));

    QString temp = "";

    temp.sprintf("SS %d", p_IOControl->getCurrentSmartSwitchID(roomIndex));
    ui->smartSwitchID->setText(temp);

    temp.sprintf("%d RAW", p_IOControl->getCurrentHumidity(roomIndex));
    ui->smartSwitchHum->setText(temp);

    temp.sprintf("%d RAW", p_IOControl->getCurrentTemperature(roomIndex));
    ui->smartSwitchTemp->setText(temp);

    temp.sprintf("%d RAW", p_IOControl->getCurrentLighting(roomIndex));
    ui->smartSwitchLighting->setText(temp);


}

void MainWindow::on_pushButton_addDevice_clicked()
{
    bool loadController = true;
    QString temp = "";

    if(loadController)
    {
        fakeDeviceID++;
        p_IOControl->addLoadController(fakeDeviceID, ui->comboBox_selectRoom1->currentIndex());
        p_IOControl->updateConfigFile();
    }

    ui->tableWidget->setItem(ui->tableWidget->currentColumn(),ui->tableWidget->currentRow(),new QTableWidgetItem(""));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->clearContents();

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(5);

    ui->progressBar->setValue(0);
    sleep(1);

    ui->progressBar->setValue(1);
    sleep(1);

    ui->progressBar->setValue(2);
    sleep(1);

    ui->progressBar->setValue(3);
    sleep(1);

    ui->progressBar->setValue(4);
    sleep(1);

    ui->progressBar->setValue(5);
    sleep(1);

    ui->tableWidget->setItem(1,-1,new QTableWidgetItem("Load Controller 1"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("Load Controller 2"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("Smart Switch 1"));
}

//If the set threshold button is pressed, launch the threshold dialog
void MainWindow::triggerThresholdDialog(int smartControlID)
{
    if(p_IOControl->numRooms != 0)
    {
        if(smartDecisionMode)
        {
            SetThresholds setThresholddialog;
            setThresholddialog.setModal(true);
            setThresholddialog.exec();
        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), "Smart Decision Mode is disabled.");
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), "There is no room to set thresholds for.");
    }
    return;
}

void MainWindow::on_pushbutton_setThreshold3_2_clicked()
{
    triggerThresholdDialog(ui->comboBox->currentIndex());
}

//For room manager mode, if set1 button is clicked then add the device to the room
void MainWindow::on_pushbutton_set1_clicked()
{
    p_IOControl->addDevice(0, ui->comboBox->currentIndex(),
                           ui->comboBox_loadController->currentText().toInt(0,10),
                           ui->device1Name->text());

    bool setIncremental = false;

    if(ui->checkBox_dev1->isChecked())
        setIncremental = true;
    else
        setIncremental = false;

    p_IOControl->setIncremental(setIncremental, 0, ui->comboBox->currentIndex(),
                                ui->comboBox_loadController->currentText().toInt(0,10),
                                ui->device2Name->text());}

//For room manager mode, if set2 button is clicked then add the device to the room
void MainWindow::on_pushbutton_set2_clicked()
{
    p_IOControl->addDevice(1, ui->comboBox->currentIndex(),
                           ui->comboBox_loadController->currentText().toInt(0,10),
                           ui->device2Name->text());

    bool setIncremental = false;

    if(ui->checkBox_dev2->isChecked())
        setIncremental = true;
    else
        setIncremental = false;

    p_IOControl->setIncremental(setIncremental, 1, ui->comboBox->currentIndex(),
                                ui->comboBox_loadController->currentText().toInt(0,10),
                                ui->device2Name->text());
}

//For room manager mode, if set3 button is clicked then add the device to the room
void MainWindow::on_pushbutton_set3_clicked()
{
    p_IOControl->addDevice(2, ui->comboBox->currentIndex(),
                           ui->comboBox_loadController->currentText().toInt(0,10),
                           ui->device3Name->text());

    bool setIncremental = false;

    if(ui->checkBox_dev3->isChecked())
        setIncremental = true;
    else
        setIncremental = false;

    p_IOControl->setIncremental(setIncremental, 2, ui->comboBox->currentIndex(),
                                ui->comboBox_loadController->currentText().toInt(0,10),
                                ui->device2Name->text());}

void MainWindow::on_helpTutorial_button_clicked()
{
    //TutorialWizard wizard;

    //wizard.setVisible(true);
    /*HelpDialog helpDialog;d
    helpDialog.setModal(true);
    helpDialog.exec();
    return;*/
    /*QApplication app = QtGui;
    TutorialWizard wizard;
    wizard.show();*/


}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 1)
    {
        changeLoadControllers();
        populateDevices(ui->comboBox->currentIndex(), ui->comboBox_loadController->currentText().toInt(0,10));
    }

    if(index == 0)
    {
        QDate setDate = ui->dateEdit->date();
        ui->calendarWidget->setSelectedDate(setDate);
    }

}

void MainWindow::changeLoadControllers()
{
    ui->comboBox_loadController->clear();

    int myLoadControllers[5] = {0,0,0,0,0};
    QString tempString = "";

    p_IOControl->getLoadControllers(ui->comboBox->currentIndex(), myLoadControllers);

    for(int i = 0; i < 5; i++)
    {
        if(myLoadControllers[i] != 0)
        {
            tempString.sprintf("%d ", myLoadControllers[i]);
            ui->comboBox_loadController->addItem(tempString);
        }
    }
}

void MainWindow::on_comboBox_loadController_currentIndexChanged(int index)
{
    ui->groupbox_dev1->setDisabled(false);
    ui->groupbox_dev1_2->setDisabled(false);
    ui->groupbox_dev1_3->setDisabled(false);

    populateDevices(ui->comboBox->currentIndex(), ui->comboBox_loadController->currentText().toInt(0,10));
}

void MainWindow::on_pushButton_2_clicked()
{
    QString temp = "";
    ui->lineEdit_avgtemp->setText(temp.sprintf("%d RAW", p_IOControl->tempData));
    ui->lineEdit_avghum->setText(temp.sprintf("%d RAW", p_IOControl->humData));
    ui->lineEdit_avglight->setText(temp.sprintf("%d RAW", p_IOControl->lightData));

}

void MainWindow::on_checkBox_5_clicked()
{
    smartDecisionMode = !smartDecisionMode;
}

void MainWindow::on_dateTimeEdit_editingFinished()
{

}
