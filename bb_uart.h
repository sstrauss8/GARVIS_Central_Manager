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
        BlackLib::BlackGPIO gpio1_15;

        bool sendData(char writeArr[], bool statusControl);
        bool setDiscoveryMode(bool inDiscovery){
            discoveryModeOn = inDiscovery;
        }

        int myType;
        bool writeEnabled;
        bool receivedMessage;
        bool receivedGloveData;
        bool discoveryModeOn;
        char data[4];
        char startup;
        char gloveData[34];
        bool sendDataGlove();
        bool sendFIFOData();
        bool disableSending;


    protected:
        void run();

    private:
        BlackLib::BlackUART uart;
        BlackLib::BlackGPIO driveEnable;
        BlackLib::BlackGPIO readEnableNot;

        BlackLib::BlackUART gloveUART;

        char writeFIFO[200];
        int currentFIFOIndex;

};

#endif // BB_UART_H
