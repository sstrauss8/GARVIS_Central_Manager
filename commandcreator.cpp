#include "commandcreator.h"
#include <iostream>

using namespace std;

CommandCreator::CommandCreator()
{
    p_IOControl = IOManager::Instance();
}

void CommandCreator::run()
{
    while(1)
    {
        if(p_IOControl->uartIn.receivedMessage)
        {
            processData(p_IOControl->uartIn.data);
            p_IOControl->uartIn.receivedMessage = false;
        }
        msleep(1);
    }
}

bool CommandCreator::sendDeviceControlCommand(int devID, int commandID)
{
    return false;
}

bool CommandCreator::processData(char data[])
{
    //ID Code->Device Type 3 Bits, 0b000
    //Number of Device     3 Bits
    //Sensor Type          4 Bits
    //Raw Data            10 Bits
    //Spare                8 Bits
    //Checksum             4 Bits

    char checksum = 0;
    for(int i = 0; i < 4; i++)
    {
        checksum = checksum ^ ((data[i] & 0xF0) >> 4);
        checksum = checksum ^ (data[i] & 0x0F);
    }

    //Throw out messages with invalid checksums
    if(checksum != 0)
        return false;

    int deviceType = 0;
    deviceType = ((data[0] & 0xE0) >> 5);

    //Throw out message that isn't meant for Central Manager
    if(deviceType != 0)
        return false;

    //Data type = 0, Capacitive Touch
    //          = 1, Humidity
    //          = 2, Light
    //          = 3, PIR
    //          = 4, Temperature

    int dataType = 0;
    dataType = ((data[0] & 0x03) << 2) + (data[1] & 0xC0 >> 6);

    char deviceNum = ((data[0] & 0x1C) >> 2);

    short rawData = ((data[1] & 0x3F) << 4) + ((data[2] & 0xF0) >> 4);

    switch(dataType)
    {
        case 0:        //Capacitive Touch
            processCapTouchData(deviceNum, rawData);
            break;
        case 1:        //Humidity
            processHumidityData(deviceNum, rawData);
            break;
        case 2:        //Light
            processLightData(deviceNum, rawData);
            break;
        case 3:        //PIR
            processPIRData(deviceNum, rawData);
            break;
        case 4:        //Temperature
            processTemperatureData(deviceNum, rawData);
            break;
        default:
            return false;
            break;
    }

    return true;
}

bool CommandCreator::processCapTouchData(char smartSwitchID, short rawData)
{
    return true;
}

bool CommandCreator::processHumidityData(char smartSwitchID, short rawData)
{
    return true;
}

bool CommandCreator::processLightData(char smartSwitchID, short rawData)
{
    return true;
}

bool CommandCreator::processPIRData(char smartSwitchID, short rawData)
{
    return true;
}

bool CommandCreator::processTemperatureData(char smartSwitchID, short rawData)
{
    return true;
}
