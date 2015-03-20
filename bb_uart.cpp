#include "bb_uart.h"
#include <iostream>

BB_UART::BB_UART(int type)
{
    myType = type;
    output = "";
}

void BB_UART::run()
{
    if(myType == 1)
    {
        BlackLib::BlackUART uart(BlackLib::UART4,BlackLib::Baud9600,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8);
        uart.open( BlackLib::ReadWrite | BlackLib::NonBlock );
        uart.flush( BlackLib::bothDirection );
        /*while(1)
        {
            char writeArr[10] = {'A','B','C','D','E','F','G','H','I','J'};

            uart.write(writeArr, sizeof(writeArr));

            msleep(1);

        }*/
    }

    if(myType == 2)
    {
        BlackLib::BlackUART uart(BlackLib::UART4,BlackLib::Baud9600,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8);
        uart.open( BlackLib::ReadWrite | BlackLib::NonBlock );
        uart.flush( BlackLib::bothDirection );
        while(1)
        {
            char readArr[10];
            memset(readArr,0,sizeof(readArr));

            uart.read(readArr, sizeof(readArr));
            QString tempString = "";
            tempString.sprintf("%s", readArr);
            output = tempString;

            msleep(1);
        }
    }

    return;
}

bool BB_UART::sendData(char writeArr[])
{
    uart.write(writeArr, sizeof(writeArr));
    return true;
}
