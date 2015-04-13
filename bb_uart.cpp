#include "bb_uart.h"
#include <stdio.h>

using namespace std;

BB_UART::BB_UART(int type) :
    gloveUART(BlackLib::UART1,BlackLib::Baud38400,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8),
    uart(BlackLib::UART4,BlackLib::Baud38400,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8),
    readEnableNot(BlackLib::GPIO_7,BlackLib::output, BlackLib::FastMode),
    driveEnable(BlackLib::GPIO_27, BlackLib::output, BlackLib::FastMode),
    gpio1_15(BlackLib::GPIO_47,BlackLib::output, BlackLib::FastMode)
{
    uart.open( BlackLib::ReadWrite | BlackLib::NonBlock );
    gloveUART.open( BlackLib::ReadWrite | BlackLib::NonBlock);
    gloveUART.flush( BlackLib::bothDirection );
    uart.flush( BlackLib::bothDirection );
    uart.setReadBufferSize(1000);
    gloveUART.setReadBufferSize(340);

    memset(writeFIFO,0,sizeof(writeFIFO));
    currentFIFOIndex = 0;

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
            memset(readArr,0,sizeof(readArr));

            while(readArr[0] == 0)
            {
                uart.read(readArr, sizeof(readArr));
                msleep(5);
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
        readEnableNot.setValue(BlackLib::high);
        driveEnable.setValue(BlackLib::high);

        if(!uart.write(writeArr, sizeof(writeArr)))
            std::cout << "write failed!" << std::endl;
        
        msleep(5);

        readEnableNot.setValue(BlackLib::low);

        driveEnable.setValue(BlackLib::low);

        printf("SENDING THIS: ");
        for(int i = 0; i < 4; i++)
        {
            printf("%d ", writeArr[i]);
        }
        printf("\n");

        uart.flush( BlackLib::output );

        return true;
    }
    //If it is not the Central Manager's turn to send data, buffer message
    //to send once it is its turn
    else
    {
        if(currentFIFOIndex <= 96)
        {
            for(int j = 0; j < 4 ; j++)
            {
                writeFIFO[currentFIFOIndex + j] = writeArr[j];
            }

            currentFIFOIndex +=4;
        }
        else
            std::cout << "Fifo index is too high" << std::endl;
    }

    return false;
}

bool BB_UART::sendDataGlove()
{
    gloveUART.write("TEST", 4);
    std::cout << "Sending Data!" << std::endl;
    return true;
}

bool BB_UART::sendFIFOData()
{
    currentFIFOIndex = 0;

    char writeArray[4] = {0,0,0,0};
    int index = 0;

    std::cout << "Sending buffered messages" << std::endl;
    for(int i = 0; i <= currentFIFOIndex; i++)
    {
        if(i%4 == 0 && i != 0)
        {
            readEnableNot.setValue(BlackLib::high);
            driveEnable.setValue(BlackLib::high);

            if(!uart.write(writeArray, sizeof(writeArray)))
                std::cout << "write failed!" << std::endl;

            msleep(5);

            readEnableNot.setValue(BlackLib::low);

            driveEnable.setValue(BlackLib::low);

            printf("SENDING THIS: ");
            for(int i = 0; i < 4; i++)
            {
                printf("%d ", writeArray[i]);
            }
            printf("\n");

            uart.flush( BlackLib::output );
        }
        else
        {
            index = i%4;
            writeArray[index] = writeFIFO[i];
        }

    }
    return true;
}
