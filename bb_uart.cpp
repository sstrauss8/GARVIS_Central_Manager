#include "bb_uart.h"
#include <stdio.h>

using namespace std;

BB_UART::BB_UART(int type) :
    gloveUART(BlackLib::UART4,BlackLib::Baud38400,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8),
    uart(BlackLib::UART1,BlackLib::Baud38400,BlackLib::ParityNo,BlackLib::StopOne,BlackLib::Char8),
    rts(BlackLib::GPIO_33,BlackLib::bothDirection),
    cts(BlackLib::GPIO_35, BlackLib::bothDirection)
{
    uart.open( BlackLib::ReadWrite | BlackLib::NonBlock );
    gloveUART.open( BlackLib::ReadWrite | BlackLib::NonBlock);
    uart.flush( BlackLib::bothDirection );
    uart.setReadBufferSize(100);
    myType = type;
    receivedMessage = false;
    receivedGloveData = false;
    output = "";
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

            //int count = 0;

            //while(!cts.isHigh())
            //{
            //    msleep(1);
            //}

            //rts.setValue(BlackLib::high);

            while(readArr[0] == 0)
            {
                uart.read(readArr, sizeof(readArr));
                msleep(10);
            }

            cout << "Received smart switch data" << endl;

            //bool flag = true;
            //while(cts.isHigh() && flag)
            //{
            //    if(count++ > 500)
            //    {
            //        flag == false;
            //    }
            //    msleep(1);
            //}

            //rts.setValue(BlackLib::low);

            //if(flag)
            //{
                QString tempString = "";
                tempString.sprintf("%s", readArr);
                output.append(tempString);

                receivedMessage = true;
                data[0] = readArr[0];
                data[1] = readArr[1];
                data[2] = readArr[2];
                data[3] = readArr[3];
            //}

                for(int i = 0; i < 4; i++)
                {
                    printf("%d ", data[i]);
                }
                printf("\n");

            usleep(10);
        }
    }

    if(myType == 3)
    {
        std::cout << "Trying to read glove data" << std::endl;
        while(1)
        {
            memset(gloveData,0,sizeof(gloveData));

            while(gloveData[0] == 0)
            {
                gloveUART.read(gloveData, 5);
                usleep(10);
            }
            receivedGloveData = true;
            cout << "Received glove data" << endl;

            /*for(int i = 0; i < 36; i++)
            {
                printf("%c ", gloveData[i]);
            }
            printf("\n");
            for(int i = 0; i < 36; i++)
            {
                printf("%d ", gloveData[i]);
            }
            printf("\n");
            //cout << "START " << gloveData[0] << gloveData[1] << endl;
            cout << "Received glove data" << endl;*/
        }

    }

    return;
}

bool BB_UART::sendData(char writeArr[])
{
    /*rts.setValue(BlackLib::high);

    for(int i  = 0; i < 3; i++)
    {
        int count = 0;
        bool flag = true;
        while(!cts.isHigh() && flag)
        {
            if(count++ > 500)
            {
                flag = false;
            }
            msleep(1);
        }

        if(flag)
        {*/
            uart.write(writeArr, sizeof(writeArr));
            uart.flush( BlackLib::output );

            //rts.setValue(BlackLib::low);
            //return true;
        //}
    //}
    return true;

}

bool BB_UART::sendDataGlove()
{

            gloveUART.write("TEST", 4);
            return true;


}
