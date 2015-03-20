#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    led1(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode),
    led2(BlackLib::GPIO_22,BlackLib::output, BlackLib::SecureMode),
    m_CommandCreator(),
    ui(new Ui::MainWindow)
{
    p_IOControl = IOManager::Instance();

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
    ledClicked = false;

    m_CommandCreator.start();
    p_IOControl->startUART();

    populateRoomNames();
}

MainWindow::~MainWindow()
{
    m_CommandCreator.exit();
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->roomEdit->setText(ui->comboBox->currentText());

    if(QString::compare("", p_IOControl->getDeviceName(ui->comboBox->currentIndex(),0), Qt::CaseInsensitive) == 0)
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

    populateDevices(ui->comboBox->currentIndex(), ui->comboBox_2->currentIndex());
}

/*void MainWindow::on_helpTutorial_button_clicked()
{
    if(!ledClicked)
    {
        ui->lineEdit_10->setText("ON");
        ledClicked = true;
    }
    else
    {
        ledClicked = false;
        ui->lineEdit_10->setText("OFF");
    }
    led2.toggleValue();
    led1.toggleValue();
}*/

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

void MainWindow::on_startUART_Button_clicked()
{
    ui->UART_text->setText(p_IOControl->uartIn.output);
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


    ui->device1Name->setText(p_IOControl->getDeviceName(roomIndex, 0));
    ui->device1ID->setText(p_IOControl->getDevice(roomIndex, 0));

    ui->device2Name->setText(p_IOControl->getDeviceName(roomIndex, 1));
    ui->device2ID->setText(p_IOControl->getDevice(roomIndex, 1));

    ui->device3Name->setText(p_IOControl->getDeviceName(roomIndex, 2));
    ui->device3ID->setText(p_IOControl->getDevice(roomIndex, 2));
}

void MainWindow::on_pushButton_addDevice_clicked()
{
    int fakeDeviceID = 11;
    p_IOControl->addDevice(fakeDeviceID, ui->comboBox_selectRoom1->currentIndex());
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
