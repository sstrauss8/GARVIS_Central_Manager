#include "commandcreator.h"
#include <iostream>

using namespace std;

CommandCreator::CommandCreator()
{
    newDataAvailFlag = false;
}

void CommandCreator::run()
{
    while(1)
    {
        if(newDataAvailFlag)
        {
            newDataAvailFlag = false;
            processData();
        }
        msleep(1);
    }
}

void setNewDataAvail(bool flag)
{
    newDataAvailFlag = flag;
}

bool CommandCreator::sendDeviceControlCommand(int devID, int commandID)
{
    return false;
}

bool CommandCreator::processData(int dataType)
{
    switch(dataType)
    {
        case 0:        //Capacitive Touch
            processCapTouchData();
            break;
        case 1:        //Humidity
            processHumidityData();
            break;
        case 2:        //Light
            processLightData();
            break;
        case 3:        //PIR
            processPIRData();
            break;
        case 4:        //Temperature
            processTemperatureData();
            break;
        default:
            return false;
            break;
    }

    return true;
}

bool CommandCreator::processCapTouchData()
{
    return true;
}

bool CommandCreator::processHumidityData()
{
    return true;
}

bool CommandCreator::processLightData()
{
    return true;
}

bool CommandCreator::processPIRData()
{
    return true;
}

bool CommandCreator::processTemperatureData()
{
    return true;
}
