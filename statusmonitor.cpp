#include "statusmonitor.h"
#include <QTimer>
#include <iostream>

using namespace std;

StatusMonitor::StatusMonitor()
{
    p_IOControl = IOManager::Instance();
    timerId = startTimer(500); // 1/2 second
    currentState = 0;
}

StatusMonitor::~StatusMonitor()
{
    killTimer(timerId);
}

void StatusMonitor::run()
{
    int pollCounter = 0;
    while(1)
    {
        if(!p_IOControl->uartIn.discoveryModeOn)
        {
            pollCounter = 0;
            char pollData[4] = {0x00,0xFF,0x00,0x00};
            if(p_IOControl->allowStatusMonitor)
            {
                for(int j = 0; j < p_IOControl->numRooms; j++)
                {
                    p_IOControl->uartOut.disableSending = true;

                    int checksum = 0;
                    int currentSmartSwitch = p_IOControl->getCurrentSmartSwitchID(j);
                    if(currentSmartSwitch != 0)
                    {
                        pollData[0] = (1 << 5) + ((currentSmartSwitch & 0x07) << 2) + 0x03;

                        for(int i = 0; i < 3; i++)
                        {
                            checksum = checksum ^ ((pollData[i] & 0xF0) >> 4);
                            checksum = checksum ^ (pollData[i] & 0x0F);
                        }

                        pollData[3] = 0;
                        pollData[3] = checksum ^ ((pollData[3] & 0xF0) >> 4);

                        //std::cout << "Sending poll message" << std::endl;
                        p_IOControl->uartOut.sendData(pollData, true);

                        msleep(100);

                    }
                    else
                        ;
                }
                p_IOControl->uartOut.disableSending = false;
            }
        }

        p_IOControl->uartOut.sendFIFOData();
        msleep(100);
    }
}

void StatusMonitor::timerEvent(QTimerEvent *event)
{
    /*if(p_IOControl->numSmartSwitches == 0)
    {
        p_IOControl->uartOut.writeEnabled = true;
        return;
    }

    if(!p_IOControl->allowStatusMonitor)
        return;
    else
    {
        if(currentState == p_IOControl->numSmartSwitches)
        {
            p_IOControl->uartOut.sendFIFOData();
            p_IOControl->uartOut.writeEnabled = true;
        }
        else if((currentState > p_IOControl->numSmartSwitches) &&
                (currentState < (p_IOControl->numSmartSwitches + 3)))
        {
            //Remaining in CM write
        }
        else if(currentState >= (p_IOControl->numSmartSwitches + 3))
        {
            currentState = -1;
            p_IOControl->uartOut.writeEnabled = false;
        }
        else
        {
            for(int i = 0; p_IOControl->numSmartSwitches; i++)
            {
                if(currentState == i)
                {
                    char smartSwitchData[4];
                    char checksum = 0;

                    smartSwitchData[0] = (1 << 5) + (((p_IOControl->getCurrentSmartSwitchID(i)) & 0x07) << 2) + (0x3);
                    smartSwitchData[1] = 0xFF;
                    smartSwitchData[2] = 0XA5;

                    for(int i = 0; i < 3; i++)
                    {
                        checksum = checksum ^ ((smartSwitchData[i] & 0xF0) >> 4);
                        checksum = checksum ^ (smartSwitchData[i] & 0x0F);
                    }

                    smartSwitchData[3] = 0;
                    smartSwitchData[3] = checksum ^ ((smartSwitchData[3] & 0xF0) >> 4);

                    p_IOControl->uartOut.sendData(smartSwitchData, true);
                    break;
                }
            }
        }
        currentState++;
    }*/


}
