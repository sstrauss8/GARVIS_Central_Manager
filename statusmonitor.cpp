#include "statusmonitor.h"
#include <QTimer>
#include <iostream>

using namespace std;

StatusMonitor::StatusMonitor()
{
    p_IOControl = IOManager::Instance();
    timerId = startTimer(1000); //Second
    currentState = 0;
}

StatusMonitor::~StatusMonitor()
{
    killTimer(timerId);
}

void StatusMonitor::run()
{

}

void StatusMonitor::timerEvent(QTimerEvent *event)
{
    if(p_IOControl->numSmartSwitches == 0)
    {
        p_IOControl->uartOut.writeEnabled = true;
    }
    else
    {
        if(currentState == p_IOControl->numSmartSwitches)
        {
            cout << "Enabling write for Central Manager" << endl;
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
            cout<< "Disabling write for Central Manager" << endl;
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

                    smartSwitchData[0] = (1 << 5) + (((i+1) & 0x07) << 2) + (0x3);
                    smartSwitchData[1] = 0xFF;
                    smartSwitchData[2] = 0XA5;

                    for(int i = 0; i < 3; i++)
                    {
                        checksum = checksum ^ ((smartSwitchData[i] & 0xF0) >> 4);
                        checksum = checksum ^ (smartSwitchData[i] & 0x0F);
                    }

                    smartSwitchData[3] = 0;
                    smartSwitchData[3] = checksum ^ ((smartSwitchData[3] & 0xF0) >> 4);

                    cout << "Sending message to let Smart Switch " << i << " go." << endl;
                    p_IOControl->uartOut.sendData(smartSwitchData, true);
                    break;
                }
            }
        }
        currentState++;
    }
}
