#include "commandcreator.h"
#include <iostream>

using namespace std;

CommandCreator::CommandCreator()
{
    p_IOControl = IOManager::Instance();
    currStartupDevice = 0;
    timeout = 0;
}

void CommandCreator::run()
{
    int pollCounter = 0;

    while(1)
    {
        //Deal with startup if we are in startup and waiting for device
        //responses
        if(p_IOControl->uartIn.discoveryModeOn)
        {
            if(++timeout > 15000)
            {
                cout << "Exiting discoverymode" << endl;
                p_IOControl->uartIn.discoveryModeOn = false;
            }

            if(p_IOControl->uartIn.receivedMessage)
            {
                processStartup(p_IOControl->uartIn.startup);
                p_IOControl->uartIn.receivedMessage = false;
                timeout = 0;
                cout << "Received Message in CommandCreator" << endl;
            }
            msleep(1);
        }

        //Deal with regular smart switch input
        else
        {
            if(p_IOControl->uartIn.receivedMessage)
            {
                processData(p_IOControl->uartIn.data);
                p_IOControl->uartIn.receivedMessage = false;
            }
            msleep(1);

            if(++pollCounter > 10000)
            {
                pollCounter = 0;
                char pollData[4] = {0x00,0xFF,0x00,0x00};
                if(p_IOControl->allowStatusMonitor)
                {
                    for(int j = 0; j < p_IOControl->numRooms; j++)
                    {
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

                            std::cout << "Sending poll message" << std::endl;
                            p_IOControl->uartOut.sendData(pollData, false);
                        }
                        else
                            ;
                    }
                }
            }
        }
    }
}

bool CommandCreator::sendDeviceControlCommand(int devID, int commandID)
{
    return false;
}

bool CommandCreator::processStartup(char data)
{
    char deviceType = (data & 0xE0) >> 5;
    char deviceNum = (data & 0x07);

    currStartupDevice++;

    p_IOControl->addPossibleDevice(deviceType, deviceNum);
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
    int event = 0;

    deviceSelected = (rawData & 0x3800) >> 7;
    event = (rawData & 0x0070) >> 4;

    std::cout << "Raw data = " << rawData << std::endl;
    std::cout << "Event = " << event << std::endl;
    p_IOControl->sendLoadControlData(smartSwitchID, deviceSelected, (char)event);
    return true;
}

bool CommandCreator::processHumidityData(char smartSwitchID, short rawData)
{
    double numMilliVoltsPerBit = 3.226;
    short humConverted =  (int)(((numMilliVoltsPerBit * rawData) - 750) / 30);
    p_IOControl->updateHumidityDisplay(smartSwitchID, humConverted);
    return true;
}

bool CommandCreator::processLightData(char smartSwitchID, short rawData)
{
    double numMilliVoltsPerBit = 3.226;
    short lightConverted = numMilliVoltsPerBit * rawData * 2;
    p_IOControl->updateLightDisplay(smartSwitchID, lightConverted);
    return true;
}

bool CommandCreator::processPIRData(char smartSwitchID, short rawData)
{
    return true;
}

bool CommandCreator::processTemperatureData(char smartSwitchID, short rawData)
{
    //Each 10 mV is one degree Celcius, starting from -50
    double numMilliVoltsPerBit = 3.226;
    short tempCelcius =  (int)(((numMilliVoltsPerBit * rawData) / 10) - 50);
    short tempFarenheit = int (tempCelcius * 9.0 / 5 + 32);

    p_IOControl->updateTemperatureDisplay(smartSwitchID, tempFarenheit);
    return true;
}
