 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BlackLib/v2_0/BlackGPIO.h"
#include "BlackLib/v2_0/BlackCore.h"
#include "BlackLib/v2_0/BlackUART.h"
#include <QMainWindow>
#include "commandcreator.h"
#include "iomanager.h"

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
    void on_button_NewRoom_clicked();
    void on_startUART_Button_clicked();

    void on_button_deleteRoom_clicked();
    void populateRoomNames();
    void populateDevices(int currentIndex, int loadControllerIndex);

    void on_pushButton_addDevice_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    BlackLib::BlackGPIO   led1;
    BlackLib::BlackGPIO   led2;

    IOManager * p_IOControl;

    QString output;
    bool ledClicked;
    int counter;

};

#endif // MAINWINDOW_H
