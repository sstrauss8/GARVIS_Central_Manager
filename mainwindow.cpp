#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QDateTime>
#include <QProcess>
#include <iostream>
#include "setthresholds.h"
#include "helpdialog.h"
#include "tutorialwizard.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gpio1_2(BlackLib::GPIO_34,BlackLib::output, BlackLib::FastMode),
    gpio1_6(BlackLib::GPIO_38,BlackLib::output, BlackLib::FastMode),
    gpio1_13(BlackLib::GPIO_45,BlackLib::output, BlackLib::FastMode),
    gpio1_15(BlackLib::GPIO_47,BlackLib::output, BlackLib::FastMode),
    m_CommandCreator(),
    m_GloveAPI()
{
    p_IOControl = IOManager::Instance();
    m_CommandCreator.start();
    m_StatusMonitor.start();
    m_GloveAPI.start();

    smartDecisionMode = false;
    timerId = startTimer(125); // 1/8 second
    timerCounter = 0;
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
    m_StatusMonitor.exit();
    m_GloveAPI.exit();
    killTimer(timerId);
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(timerCounter++ < 40)
        return;

    if(ui->tabWidget->currentIndex() == 0)
    {
        QString temp = "";
        ui->lineEdit_avgtemp->setText(temp.sprintf("%d%cF", p_IOControl->tempData, 176));
        ui->lineEdit_avghum->setText(temp.sprintf("%d%", p_IOControl->humData));
        ui->lineEdit_avglight->setText(temp.sprintf("%dlx", p_IOControl->lightData));
    }

    if(ui->tabWidget->currentIndex() == 1)
    {
        populateDevices(ui->comboBox->currentIndex(), ui->comboBox_loadController->currentText().toInt(0,10));
    }
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

    if(p_IOControl->getCurrentSmartSwitchID(roomIndex) == -1)
    {
        ui->smartSwitchID->setDisabled(true);
        ui->smartSwitchHum->setDisabled(true);
        ui->smartSwitchTemp->setDisabled(true);
        ui->smartSwitchLighting->setDisabled(true);
    }
    else
    {
        ui->smartSwitchID->setDisabled(false);
        ui->smartSwitchHum->setDisabled(false);
        ui->smartSwitchTemp->setDisabled(false);
        ui->smartSwitchLighting->setDisabled(false);
        temp.sprintf("SS %d", p_IOControl->getCurrentSmartSwitchID(roomIndex));
        ui->smartSwitchID->setText(temp);

        temp.sprintf("%d%", p_IOControl->getCurrentHumidity(roomIndex));
        ui->smartSwitchHum->setText(temp);

        temp.sprintf("%d%cF", p_IOControl->getCurrentTemperature(roomIndex), 176);
        ui->smartSwitchTemp->setText(temp);

        temp.sprintf("%dlx", p_IOControl->getCurrentLighting(roomIndex));
        ui->smartSwitchLighting->setText(temp);
    }
}

void MainWindow::on_pushButton_addDevice_clicked()
{
    bool loadController = true;
    QString temp = "";

    int currentItem = ui->tableWidget->currentRow();

    if(p_IOControl->devType[currentItem] == 0x03)//ventController
    {
        p_IOControl->addLoadController(p_IOControl->devNum[currentItem],
                                       ui->comboBox_selectRoom1->currentIndex());
        p_IOControl->updateConfigFile();
    }

    if(p_IOControl->devType[currentItem] == 0x01)//smartSwitch
    {
        p_IOControl->addSmartSwitch(p_IOControl->devNum[currentItem],
                                    ui->comboBox_selectRoom1->currentIndex());
    }

    ui->tableWidget->setItem(ui->tableWidget->currentColumn(),ui->tableWidget->currentRow(),new QTableWidgetItem(""));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->clearContents();

    p_IOControl->sendDeviceDetect();

    usleep(100);

    int currentPercent = 0;
    bool add = true;
    ui->progressBar->setValue(currentPercent);

    while(p_IOControl->uartIn.discoveryModeOn)
    {
        usleep(100000);

        ui->progressBar->setValue(currentPercent);

        if(add)
        {
            if(currentPercent < 60)
                currentPercent += 10;
            else
                add = false;
        }

        if(!add)
        {
            if(currentPercent > 0)
                currentPercent -= 10;
            else
                add = true;
        }

    }

    ui->progressBar->setValue(60);

    QString tempVal = "";
    for(int i = 0; i < p_IOControl->numStartUpDevices; i++)
    {
        if(p_IOControl->devType[i] == 0x01)//Smart Switch
        {
            tempVal.sprintf("Smart Switch ID %d", p_IOControl->devNum[i]);
        }
        if(p_IOControl->devType[i] == 0x02)//Load Controller
        {
            tempVal.sprintf("Load Controller ID %d", p_IOControl->devNum[i]);
        }
        if(p_IOControl->devType[i] == 0x03)//Vent Controller
        {
            tempVal.sprintf("Vent Controller ID %d", p_IOControl->devNum[i]);
        }
        ui->tableWidget->setItem(1,i-1, new QTableWidgetItem(tempVal));
    }
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
    if(index == 0)
    {
        QString temp = "";
        ui->lineEdit_avgtemp->setText(temp.sprintf("%d%cF", p_IOControl->tempData, 176));
        ui->lineEdit_avghum->setText(temp.sprintf("%d%", p_IOControl->humData));
        ui->lineEdit_avglight->setText(temp.sprintf("%dlx", p_IOControl->lightData));
    }
    if(index == 1)
    {
        ui->roomEdit->setText(ui->comboBox->currentText());

        changeLoadControllers();

        p_IOControl->setCurrentRoomManagerRoom(ui->comboBox->currentIndex());

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

//Send Device Startup Box
void MainWindow::on_pushButton_addDevice_2_clicked()
{
    if(!p_IOControl->uartIn.discoveryModeOn && p_IOControl->uartOut.discoveryModeOn)
    {
        p_IOControl->allowStatusMonitor =true;
        p_IOControl->sendDevStartup();
        p_IOControl->uartOut.discoveryModeOn = false;
    }

    ui->progressBar->setValue(0);
}

//Populate Delete Device Table
void MainWindow::on_comboBox_selectRoom2_currentIndexChanged(int index)
{

    ui->tableWidget_2->clearContents();
    QString tempVal = "";
    int count = -1;

    if(!(p_IOControl->getCurrentSmartSwitchID(index) <= 0))
    {
        tempVal.sprintf("Smart Switch ID %d", p_IOControl->getCurrentSmartSwitchID(index));
        ui->tableWidget_2->setItem(1,count, new QTableWidgetItem(tempVal));
        count++;
    }

    int loadControllers[5] = {-1,-1,-1,-1,-1};
    p_IOControl->getLoadControllers(index, loadControllers);

    for(int i = 0; i < 5; i++)
    {
        if(!(loadControllers[i] <= 0))
        {
            tempVal.sprintf("Load Controller ID %d", loadControllers[i]);
            ui->tableWidget_2->setItem(1,count, new QTableWidgetItem(tempVal));
            count++;
        }
    }

}

void MainWindow::on_pushButton_clicked()
{
    m_florence.start("florence");

}

void MainWindow::on_checkBox_smartDM_clicked()
{
    QPalette palette = ui->smartDecMode->palette();

    smartDecisionMode = !smartDecisionMode;
    if(smartDecisionMode)
    {
        palette.setColor(QPalette::Base, QColor(0,255,0)); //Green
        ui->smartDecMode->setText("Enabled");
    }
    else
    {
        palette.setColor(QPalette::Base, QColor(255,0,0)); //Red
        ui->smartDecMode->setText("Disabled");
    }

    ui->smartDecMode->setPalette(palette);
}


void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked)
    {
        if(gpio1_2.setValue(BlackLib::high))
            std::cout << "Successfully wrote high to gpio1_2" << std::endl;
        else
            std::cout << "Failed to write high to gpio1_2" << std::endl;
    }

    else
    {
        if(gpio1_2.setValue(BlackLib::low))
            std::cout << "Successfully wrote low to gpio1_2" << std::endl;
        else
            std::cout << "Failed to low high to gpio1_2" << std::endl;
    }
}

void MainWindow::on_checkBox_2_clicked(bool checked)
{
    if(checked)
    {
        if(gpio1_13.setValue(BlackLib::high))
            std::cout << "Successfully wrote high to gpio1_13" << std::endl;
        else
            std::cout << "Failed to write high to gpio1_13" << std::endl;
    }

    else
    {
        if(gpio1_13.setValue(BlackLib::low))
            std::cout << "Successfully wrote low to gpio1_13" << std::endl;
        else
            std::cout << "Failed to low high to gpio1_13" << std::endl;
    }
}

void MainWindow::on_checkBox_3_clicked(bool checked)
{
    if(checked)
    {
        if(gpio1_15.setValue(BlackLib::high))
            std::cout << "Successfully wrote high to gpio1_15" << std::endl;
        else
            std::cout << "Failed to write high to gpio1_15" << std::endl;
    }

    else
    {
        if(gpio1_15.setValue(BlackLib::low))
            std::cout << "Successfully wrote low to gpio1_15" << std::endl;
        else
            std::cout << "Failed to low high to gpio1_15" << std::endl;
    }
}

void MainWindow::on_checkBox_4_clicked(bool checked)
{
    if(checked)
    {
        if(gpio1_6.setValue(BlackLib::high))
            std::cout << "Successfully wrote high to gpio1_6" << std::endl;
        else
            std::cout << "Failed to write high to gpio1_6" << std::endl;
    }

    else
    {
        if(gpio1_6.setValue(BlackLib::low))
            std::cout << "Successfully wrote low to gpio1_6" << std::endl;
        else
            std::cout << "Failed to low high to gpio1_6" << std::endl;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    showNormal();
}
