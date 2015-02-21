#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    led1(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode),
    led2(BlackLib::GPIO_22,BlackLib::output, BlackLib::SecureMode),
    uart(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Bedroom 1");
    ui->comboBox->addItem("Bedroom 2");
    ui->comboBox->addItem("Bedroom 3");
    ui->comboBox->addItem("Bathroom");
    ui->comboBox->addItem("Kitchen");

    ledClicked = false;
}

MainWindow::~MainWindow()
{
    uart.exit();
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->roomEdit->setText(ui->comboBox->currentText());
}

void MainWindow::on_helpTutorial_button_clicked()
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
    uart.start();
}

void MainWindow::on_startUART_Button_clicked()
{

    ui->UART_text->setText(uart.output);
    /*bool isOpened = uart.open( BlackLib::ReadWrite | BlackLib::NonBlock );


    char readArr[22];
    memset(readArr,0,sizeof(readArr));

    uart.read(readArr, sizeof(readArr));

    QString tempString = "";

    tempString.sprintf("%s\n", readArr);

    output.append(tempString);

    ui->lineEdit->setText(output);*/

}
