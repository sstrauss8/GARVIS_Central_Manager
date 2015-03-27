#ifndef BB_UART_H
#define BB_UART_H
#include <QThread>
#include "BlackLib/v2_0/BlackGPIO.h"
#include "BlackLib/v2_0/BlackCore.h"
#include "BlackLib/v2_0/BlackUART.h"
#include "constants.h"
#include <iostream>

class BB_UART: public QThread
{
    public:
        QString output;
        char readArr[100];
        BB_UART(int type);
        BB_UART();

        bool sendData(char writeArr[]);
        int myType;
        bool receivedMessage;
        bool receivedGloveData;
        char data[4];
        char gloveData[100];
        bool sendDataGlove();

    protected:
        void run();

    private:
        BlackLib::BlackUART uart;
        BlackLib::BlackGPIO rts;
        BlackLib::BlackGPIO cts;

        BlackLib::BlackUART gloveUART;

};

#endif // BB_UART_H
