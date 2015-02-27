#include "bb_uart.h"

BB_UART::BB_UART():
    uart(BlackLib::UART1,BlackLib::Baud9600,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8)
{
    output = "Test!";
}

void BB_UART::run()
{
    bool isOpened = uart.open( BlackLib::ReadWrite | BlackLib::NonBlock );
    while(1)
    {
        char readArr[100];
        memset(readArr,0,sizeof(readArr));

        if(uart.read(readArr, sizeof(readArr)))
        {
            QString tempString = "";
            tempString.sprintf("%s\n", readArr);
            output.append(tempString);
        }

        usleep(SLEEP_TIME_SECOND);
    }
    return;
}
