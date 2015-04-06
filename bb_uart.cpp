#include "bb_uart.h"
#include <stdio.h>

using namespace std;

BB_UART::BB_UART(int type) :
    gloveUART(BlackLib::UART1,BlackLib::Baud38400,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8),
    uart(BlackLib::UART4,BlackLib::Baud38400,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8),
    readEnableNot(BlackLib::GPIO_7,BlackLib::bothDirection),
    driveEnable(BlackLib::GPIO_3, BlackLib::bothDirection)
{
    uart.open( BlackLib::ReadWrite | BlackLib::NonBlock );
    gloveUART.open( BlackLib::ReadWrite | BlackLib::NonBlock);
    gloveUART.flush( BlackLib::bothDirection );
    uart.flush( BlackLib::bothDirection );
    uart.setReadBufferSize(1000);
    gloveUART.setReadBufferSize(340);

    writeEnabled = false;
    myType = type;
    receivedMessage = false;
    receivedGloveData = false;
    output = "";
    startup = 0;
}

void BB_UART::run()
{

    if(myType == 1)
    {
        /*while(1)
        {
            char writeArr[10] = {'A','B','C','D','E','F','G','H','I','J'};

            uart.write(writeArr, sizeof(writeArr));

            msleep(1);

        }*/
    }

    if(myType == 2)
    {
        while(1)
        {
            std::cout << "Trying to read smart switch data" << std::endl;
            memset(readArr,0,sizeof(readArr));

            while(readArr[0] == 0)
            {
                uart.read(readArr, sizeof(readArr));
                msleep(10);
            }

            if(discoveryModeOn)
            {
                cout << "Received startup data " << (int) readArr[0] << endl;
                startup = readArr[0];
                receivedMessage = true;
            }
            else
            {
                cout << "Received smart switch data" << endl;

                QString tempString = "";
                tempString.sprintf("%s", readArr);
                output.append(tempString);

                receivedMessage = true;
                data[0] = readArr[0];
                data[1] = readArr[1];
                data[2] = readArr[2];
                data[3] = readArr[3];

                for(int i = 0; i < 4; i++)
                {
                    printf("%d ", data[i]);
                }
                printf("\n");
            }

            usleep(2);
        }
    }

    int flushCounter = 0;
    if(myType == 3)
    {
        char tempData[34];
        memset(tempData, 0x0, 34);

        std::cout << "Trying to read glove data" << std::endl;
        while(1)
        {
            memset(tempData,0,sizeof(tempData));

            while(tempData[0] == 0)
            {
                gloveUART.read(tempData, 34);
                usleep(9900);
            }

            if(++flushCounter > 10)
            {
                gloveUART.flush(BlackLib::bothDirection);
                flushCounter = 0;
            }

            receivedGloveData = true;
            //cout << "Received glove data" << endl;

            for(int i = 0; i < 34; i++)
            {
                gloveData[i] = tempData[i];
                //printf("%c ", gloveData[i]);
            }
        }

    }

    return;
}

bool BB_UART::sendData(char writeArr[], bool statusControl)
{
    //Either it is the Central Manager's turn to send data as needed
    //or the CM is sending the control message for another device
    //to have a turn to write;
    if(writeEnabled || statusControl)
    {
        //readEnableNot.setValue(BlackLib::high);
        //driveEnable.setValue(BlackLib::high);

        uart.write(writeArr, sizeof(writeArr));

        //readEnableNot.setValue(BlackLib::low);
        //driveEnable.setValue(BlackLib::low);

        printf("SENDING THIS: ");
        for(int i = 0; i < 4; i++)
        {
            printf("%d ", writeArr[i]);
        }
        printf("\n");

        uart.flush( BlackLib::output );

        return true;
    }

    return false;
}

bool BB_UART::sendDataGlove()
{

            //gloveUART.write("TEST", 4);
            return true;


}
