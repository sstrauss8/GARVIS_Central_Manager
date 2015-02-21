 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BlackLib/v2_0/BlackGPIO.h"
#include "BlackLib/v2_0/BlackCore.h"
#include "BlackLib/v2_0/BlackUART.h"
#include <QMainWindow>
#include "bb_uart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_helpTutorial_button_clicked();

    void on_startUART_Button_clicked();

private:
    Ui::MainWindow *ui;

    BlackLib::BlackGPIO   led1;
    BlackLib::BlackGPIO   led2;

    BB_UART uart;
    QString output;
    bool ledClicked;

};

#endif // MAINWINDOW_H
