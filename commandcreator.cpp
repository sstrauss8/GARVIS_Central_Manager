#include "commandcreator.h"
#include <iostream>

using namespace std;

CommandCreator::CommandCreator()
{
    p_IOControl = IOManager::Instance();
}

void CommandCreator::run()
{
    int pollCounter = 0;

    while(1)
    {
        if(p_IOControl->uartIn.receivedMessage)
        {
            processData(p_IOControl->uartIn.data);
            p_IOControl->uartIn.receivedMessage = false;
        }
        msleep(1);

        if(++pollCounter > 60000)
        {
            pollCounter = 0;
            char pollData[4] = {0x23,0xFF,0x00,0x01};
            std::cout << "Sending poll message" << std::endl;
            p_IOControl->uartOut.sendData(pollData);
        }
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

    std::cout << "In Process Data" << std::endl;
    char checksum = 0;
    for(int i = 0; i < 4; i++)
    {
        checksum = checksum ^ ((data[i] & 0xF0) >> 4);
        checksum = checksum ^ (data[i] & 0x0F);
    }

    //Throw out messages with invalid checksums
    if(checksum != 0)
    {
        std::cout << "INVALID CHECKSUM" << std::endl;
        return false;
    }

    int deviceType = 0;
    deviceType = ((data[0] & 0xE0) >> 5);

    //Throw out message that isn't from a smart switch for the central manager
    if(deviceType != 1)
        return false;

    //Data type = 0, Temperature
    //          = 1, Humidity
    //          = 2, Light
    //          = 3, PIR
    //          = 4, Capacitive Touch

    int dataType = 0;
    dataType = ((data[0] & 0x03) << 2) + ((data[1] & 0xC0) >> 6);

    char smartSwitchNum = ((data[0] & 0x1C) >> 2);

    short rawData = ((data[1] & 0x3F) << 4) + ((data[2] & 0xF0) >> 4);

    std::cout << "Data Type " << dataType << std::endl;

    switch(dataType)
    {
        case 0:        //Temperature
            processTemperatureData(smartSwitchNum, rawData);
            break;
        case 1:        //Humidity
            processHumidityData(smartSwitchNum, rawData);
            break;
        case 2:        //Light
            processLightData(smartSwitchNum, rawData);
            break;
        case 3:        //PIR
            processPIRData(smartSwitchNum, rawData);
            break;
        case 4:        //Capacitive Touch
            processCapTouchData(smartSwitchNum, rawData);
            break;
        default:
            return false;
            break;
    }

    return true;
}

bool CommandCreator::processCapTouchData(char smartSwitchID, short rawData)
{
    int deviceSelected;
    char event, percentOn = 0;

    deviceSelected = (rawData & 0xE000) >> 13;
    event = (rawData & 0x1C00) >> 10;

    if(event == 0)
    {
        percentOn = 10;
    }
    p_IOControl->sendLoadControlData(smartSwitchID, deviceSelected, percentOn);
    return true;
}

bool CommandCreator::processHumidityData(char smartSwitchID, short rawData)
{
    p_IOControl->updateHumidityDisplay(smartSwitchID, rawData);
    return true;
}

bool CommandCreator::processLightData(char smartSwitchID, short rawData)
{
    p_IOControl->updateLightDisplay(smartSwitchID, rawData);
    return true;
}

bool CommandCreator::processPIRData(char smartSwitchID, short rawData)
{
    return true;
}

bool CommandCreator::processTemperatureData(char smartSwitchID, short rawData)
{
    p_IOControl->updateTemperatureDisplay(smartSwitchID, rawData);
    return true;
}
