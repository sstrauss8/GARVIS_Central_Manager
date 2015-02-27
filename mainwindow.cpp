#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    led1(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode),
    led2(BlackLib::GPIO_22,BlackLib::output, BlackLib::SecureMode),
    m_CommandCreator(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*ui->comboBox->addItem("Bedroom 1");
    ui->comboBox->addItem("Bedroom 2");
    ui->comboBox->addItem("Bedroom 3");
    ui->comboBox->addItem("Bathroom");
    ui->comboBox->addItem("Kitchen");*/

    ledClicked = false;

    m_CommandCreator.start();
    p_IOControl = IOManager::Instance();
    p_IOControl->startUART();
}

MainWindow::~MainWindow()
{
    m_CommandCreator.exit();
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->roomEdit->setText(ui->comboBox->currentText());
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
        //Populate necessary comboboxes with new room
        ui->comboBox->addItem(ui->textBox_newRoom->text());
        ui->comboBox_selectRoom1->addItem(ui->textBox_newRoom->text());
        ui->comboBox_selectRoom2->addItem(ui->textBox_newRoom->text());
    }

    ui->textBox_newRoom->setText("");

}
