#include <stddef.h>
#include "iomanager.h"
#include <iostream>
#include <stdio.h>


// Global static pointer used to ensure a single instance of the class.
IOManager* IOManager::m_pInstance = NULL;

IOManager::IOManager():
    uartGlove(3),
    uartIn(2),
    uartOut(1)
{
    humData = 0;
    tempData = 0;
    lightData = 0;
    numRooms = 0;
    gpio1On = false;
    initialize();
    allowStatusMonitor = false;
}

IOManager::~IOManager()
{
    uartGlove.exit();
    uartIn.exit();
    uartOut.exit();
}

bool IOManager::initialize()
{
    numSmartSwitches = 0;
    roomList = new room;
    roomList->next = 0;
    roomList->roomName = "";
    roomList->devices = new device;
    roomList->devices->currState = 0;
    roomList->devices->deviceID = -1;
    roomList->devices->deviceName = "";
    roomList->devices->next = 0;
    roomList->devices->incremental = 0;
    roomList->ventControlConnected = false;
    roomList->ventControlStatus = false;
    roomList->ventControlID = -1;
    roomList->minTemp = 32;
    roomList->maxTemp = 120;
    roomList->minHum = 0;
    roomList->maxHum = 100;
    roomList->minLight = 0;
    roomList->maxLight = 100;
    roomList->smartSwitchID = -1;
    roomList->numDevices = 0;
    roomList->smartSwitchTemperature = 0;
    roomList->smartSwitchHumidity = 0;
    roomList->smartSwitchLighting = 0;
    roomList->smartSwitchPIR = 0;
    roomList->loadControllers[0] = 0;
    roomList->loadControllers[1] = 0;
    roomList->loadControllers[2] = 0;
    roomList->loadControllers[3] = 0;
    roomList->loadControllers[4] = 0;
    roomList->numLoadControllers = 0;

    memset(devNum, 0, sizeof(devNum));
    memset(devType, 0, sizeof(devNum));
    numStartUpDevices = 0;


    currentRoomManagerRoom = NULL;

    return true;
}

bool IOManager::addRoom(QString name)
{
    bool flag = true;
    room *list = roomList;
    while(flag)
    {
        //Check if user is trying to enter name that already exists
        if(QString::compare(list->roomName, name, Qt::CaseInsensitive) == 0)
            return false;

        if(list->next == 0)
            flag = false;
        else
            list = list->next;

    }

    if(numRooms == 0)
    {
        roomList->roomName = name;
    }
    else
    {
        list->next = new room;
        list = list->next;
        list->next = 0;
        list->roomName = name;
        list->devices = new device;
        list->devices->currState = 0;
        list->devices->deviceID = -1;
        list->devices->deviceName = "";
        list->devices->next = 0;
        list->devices->incremental = 0;
        list->ventControlConnected = false;
        list->ventControlStatus = false;
        list->ventControlID = -1;
        list->minTemp = 32;
        list->maxTemp = 120;
        list->minHum = 0;
        list->maxHum = 100;
        list->minLight = 0;
        list->maxLight = 100;
        list->smartSwitchID = -1;
        list->numDevices = 0;
        list->smartSwitchTemperature = 0;
        list->smartSwitchHumidity = 0;
        list->smartSwitchLighting = 0;
        list->smartSwitchPIR = 0;
        list->loadControllers[0] = 0;
        list->loadControllers[1] = 0;
        list->loadControllers[2] = 0;
        list->loadControllers[3] = 0;
        list->loadControllers[4] = 0;
        list->numLoadControllers = 0;
    }

    numRooms++;

    updateConfigFile();

    return true;
}

bool IOManager::addRoom(QString name, int minTemp, int maxTemp, int minHum, int maxHum,
                        int minLight, int maxLight, int smartSwitchID, int smartSwitchTemp,
                        int smartSwitchHum, int smartSwitchLight, int loadControllers[])
{
    bool flag = true;
    room *list = roomList;
    while(flag)
    {
        //Check if user is trying to enter name that already exists
        if(QString::compare(list->roomName, name, Qt::CaseInsensitive) == 0)
            return false;

        if(list->next == 0)
            flag = false;
        else
            list = list->next;

    }

    if(numRooms == 0)
    {
        roomList->roomName = name;
        roomList->minTemp = minTemp;
        roomList->maxTemp = maxTemp;
        roomList->minHum = minHum;
        roomList->maxHum = maxHum;
        roomList->minLight = minLight;
        roomList->maxLight = maxLight;
        roomList->smartSwitchID = -1;
        roomList->numDevices = 0;
        roomList->smartSwitchTemperature = smartSwitchTemp;
        roomList->smartSwitchHumidity = smartSwitchHum;
        roomList->smartSwitchLighting = smartSwitchLight;
        roomList->smartSwitchPIR = 0;
        roomList->loadControllers[0] = loadControllers[0];
        roomList->loadControllers[1] = loadControllers[1];
        roomList->loadControllers[2] = loadControllers[2];
        roomList->loadControllers[3] = loadControllers[3];
        roomList->loadControllers[4] = loadControllers[4];
        roomList->numLoadControllers = 0;
    }
    else
    {
        list->next = new room;
        list = list->next;
        list->next = 0;
        list->roomName = name;
        list->devices = new device;
        list->devices->currState = 0;
        list->devices->deviceID = -1;
        list->devices->deviceName = "";
        list->devices->next = 0;
        list->devices->incremental = 0;
        list->ventControlConnected = false;
        list->ventControlStatus = false;
        list->ventControlID = -1;
        list->minTemp = minTemp;
        list->maxTemp = maxTemp;
        list->minHum = minHum;
        list->maxHum = maxHum;
        list->minLight = minLight;
        list->maxLight = maxLight;
        list->smartSwitchID = -1;
        list->numDevices = 0;
        list->smartSwitchTemperature = smartSwitchTemp;
        list->smartSwitchHumidity = smartSwitchHum;
        list->smartSwitchLighting = smartSwitchLight;
        list->smartSwitchPIR = 0;
        list->loadControllers[0] = loadControllers[0];
        list->loadControllers[1] = loadControllers[1];
        list->loadControllers[2] = loadControllers[2];
        list->loadControllers[3] = loadControllers[3];
        list->loadControllers[4] = loadControllers[4];
        list->numLoadControllers = 0;
    }

    numRooms++;

    updateConfigFile();

    return true;
}

bool IOManager::deleteRoom(int index)
{
    room *pPre = NULL, *pDel = NULL;

    room *list = roomList;

    if(numRooms == 0)
        return false;

    if(index == 0)
    {
        pDel = roomList;
        numRooms--;

        if(numRooms !=0)
            roomList = pDel->next;
        else
        {
            roomList->next = NULL;
            roomList->devices = NULL;
            roomList->roomName = "";
        }

        delete pDel;

        updateConfigFile();
        return true;
    }

    pPre = roomList;
    pDel = roomList->next;

    for(int i = 1; i < index; i++)
    {
        pPre = pDel;
        pDel = pDel->next;
    }
    pPre->next = pDel->next;

    numRooms--;
    delete pDel;

    updateConfigFile();
    return true;
}

IOManager* IOManager::Instance()
{
       if (!m_pInstance)   // Only allow one instance of class to be generated.
          m_pInstance = new IOManager;

       return m_pInstance;
}

bool IOManager::ReadConfigFile()
{
    FILE * ifp;
    int rooms;
    char c[100];
    int arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12;
    int arg13, arg14, arg15;
    int lc[5] = {0,0,0,0,0};

    ifp = fopen("config.conf", "r");

    fscanf(ifp, "%d\n", &rooms);

    for(int i = 0; i < rooms; i++)
    {
        fscanf(ifp,"\n%[^\n]",c);
        //fscanf(ifp,"%s",c);
        QString currRoomName(c);

        fscanf(ifp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &arg1, &arg2, &arg3,
               &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12, &arg13,
               &arg14, &arg15);

        lc[0] = arg11;
        lc[1] = arg12;
        lc[2] = arg13;
        lc[3] = arg14;
        lc[4] = arg15;


        addRoom(currRoomName, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
                arg10, lc);
    }

    fclose(ifp);

    return true;
}

bool IOManager::ClearConfigFile()
{
    return updateConfigFile();
}

QString IOManager::getRoom(int index)
{
    room *list = roomList;

    if(index >= numRooms)
        return "";

    for(int i = 0; i < index; i++)
    {
        list = list->next;
    }

    return list->roomName;
}

QString IOManager::getDevice(int currRoomIndex, int deviceIndex, int lc)
{
    room *list = roomList;
    device *devList;
    int maxDevices = 18; //Assume max number of lcs in a room is 6
    int count = 0;

    if(currRoomIndex >= numRooms)
        return "";

    for(int i = 0; i < currRoomIndex; i++)
    {
        list = list->next;
    }

    devList = list->devices;

    if(devList == NULL)
        return "";

    for(int i = 0; i < maxDevices; i++)
    {
        if(devList->loadControllerID == lc)
        {
            if(count == deviceIndex)
            {
                return QString::number(devList->deviceID);
            }
            count++;
        }
        if(devList->next != NULL)
        {
            devList = devList->next;
        }
        else
        {
            return "";
        }
    }

    return "";
}

int IOManager::getDevicePercent(int currRoomIndex, int deviceIndex, int lc)
{
    room *list = roomList;
    device *devList;
    int maxDevices = 18; //Assume max number of lcs in a room is 6
    int count = 0;

    if(currRoomIndex >= numRooms)
        return 0;

    for(int i = 0; i < currRoomIndex; i++)
    {
        list = list->next;
    }

    devList = list->devices;

    if(devList == NULL)
        return 0;

    for(int i = 0; i < maxDevices; i++)
    {
        if(devList->loadControllerID == lc)
        {
            if(count == deviceIndex)
            {
                return devList->currState;
            }
            count++;
        }
        if(devList->next != NULL)
        {
            devList = devList->next;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

QString IOManager::getDeviceName(int currRoomIndex, int deviceIndex, int lc)
{
    room *list = roomList;
    device *devList;
    int maxDevices = 18; //Assume max number of lcs in a room is 6
    int count = 0;

    if(currRoomIndex >= numRooms)
        return "";

    for(int i = 0; i < currRoomIndex; i++)
    {
        list = list->next;
    }

    devList = list->devices;

    if(devList == NULL)
        return "";

    for(int i = 0; i < maxDevices; i++)
    {
        if(devList->loadControllerID == lc)
        {
            if(count == deviceIndex)
            {
                return devList->deviceName;
            }
            count++;
        }
        if(devList->next != NULL)
        {
            devList = devList->next;
        }
        else
        {
            return "";
        }
    }

    return "";
}


int IOManager::getNumRooms()
{
    return numRooms;
}

void IOManager::setRoomClear()
{
    numRooms = 0;
    roomList->roomName = "";
    roomList->devices = NULL;
    roomList->loadControllers[0] = 0;
    roomList->loadControllers[1] = 0;
    roomList->loadControllers[2] = 0;
    roomList->loadControllers[3] = 0;
    roomList->loadControllers[4] = 0;
}

bool IOManager::addDevice(int devID, int index, int loadControllerID, QString devName, bool vc)
{
    room *list = roomList;

    int numDevs = 0;

    if(numRooms < index)
        return false;

    for(int i = 0; i < index; i++)
    {
        list = list->next;
    }

    bool flag = true;

    numDevs = list->numDevices;
    device *devList = list->devices;

    if(numDevs == 0)
    {

        list->devices = new device;
        devList = list->devices;
        devList->currState = 0;
        devList->deviceID = 0;
        devList->next = 0;
        devList->deviceName = devName;
        devList->incremental = vc;
        devList->loadControllerID = loadControllerID;
        list->numDevices++;
        return true;
    }

    while(flag)
    {
        if(devList->next == NULL)
            flag = false;
        else
            devList = devList->next;

    }

    devList->next = new device;
    devList = devList->next;
    devList->next = 0;
    devList->deviceID = list->numDevices;
    devList->deviceName = devName;
    devList->currState = 0;
    devList->incremental = vc;
    devList->loadControllerID = loadControllerID;
    list->numDevices++;

    updateConfigFile();

    return true;
}


bool IOManager::setIncremental(bool setIncr, int devID, int index, int loadControllerID, QString devName)
{
    room *list = roomList;

    int numDevs = 0;

    if(numRooms < index)
        return false;

    for(int i = 0; i < index; i++)
    {
        list = list->next;
    }

    bool flag = true;

    numDevs = list->numDevices;
    device *devList = list->devices;

    if(numDevs == 0)
    {
        return false;
    }

    while(flag)
    {
        if(devList->next == NULL || devList->deviceID == devID)
            flag = false;
        else
            devList = devList->next;

    }

    devList->incremental = setIncr;

    return true;
}

bool IOManager::removeDevice(int devID, int index)
{
    return true;
}

bool IOManager::addLoadController(int loadControllerID, int roomNum)
{
    room *list = roomList;

    if(numRooms < roomNum)
        return false;

    for(int i = 0; i < roomNum; i++)
    {
        list = list->next;
    }

    for(int i = 0; i < 5; i++)
    {
        if(list->loadControllers[i] == 0)
        {
            list->loadControllers[i] = loadControllerID;
            list->numLoadControllers++;
            return true;
        }
    }
    return false;

}

bool IOManager::addVentController(int ventControllerID, int roomNum)
{
    room *list = roomList;

    if(numRooms < roomNum)
        return false;

    for(int i = 0; i < roomNum; i++)
    {
        list = list->next;
    }

    list->ventControlConnected = true;
    list->ventControlStatus = false;
    list->ventControlID = ventControllerID;

    return true;

}

int IOManager::getVentControllerID(int roomNum)
{
    room *list = roomList;

    if(numRooms < roomNum)
        return false;

    for(int i = 0; i < roomNum; i++)
    {
        list = list->next;
    }

    return list->ventControlID;
}

bool IOManager::getVentControllerStatus(int roomNum)
{
    room *list = roomList;

    if(numRooms < roomNum)
        return false;

    for(int i = 0; i < roomNum; i++)
    {
        list = list->next;
    }

    return list->ventControlStatus;
}

void IOManager:: setVentControllerStatus(int roomNum, bool status)
{
    room *list = roomList;

    if(numRooms < roomNum)
        return;

    for(int i = 0; i < roomNum; i++)
    {
        list = list->next;
    }

    if(list->ventControlStatus != status)
    {
        //std::cout << "Before send vent control data!" << std::endl;
        sendVentControlData(list->ventControlID, status, roomNum);
    }

    list->ventControlStatus = status;
}

bool IOManager::getLoadControllers(int roomID, int lc[])
{
    room *list = roomList;

    if(numRooms < roomID)
        return false;

    for(int i = 0; i < roomID; i++)
    {
        list = list->next;
    }

    for(int i = 0; i < 5; i++)
    {
        if(list->loadControllers[i] == 0)
        {
            return true;
        }
        lc[i] = list->loadControllers[i];
    }
    return false;

}

bool IOManager::updateConfigFile()
{
    FILE * ofp = fopen("config.conf", "w");

    room * list = roomList;

    if(!ofp)
        return false;

    fprintf(ofp, "%d\n", numRooms);

    for(int i = 0; i < numRooms; i++)
    {
        unsigned char roomName[50];
        memcpy( roomName, list->roomName.toStdString().c_str() , 50);
        fprintf(ofp, "%s\n ", roomName);
        fprintf(ofp, "%d ", list->minTemp);
        fprintf(ofp, "%d ", list->maxTemp);
        fprintf(ofp, "%d ", list->minHum);
        fprintf(ofp, "%d ", list->maxHum);
        fprintf(ofp, "%d ", list->minLight);
        fprintf(ofp, "%d ", list->maxLight);
        fprintf(ofp, "%d ", list->smartSwitchID);
        fprintf(ofp, "%d ", list->smartSwitchTemperature);
        fprintf(ofp, "%d ", list->smartSwitchHumidity);
        fprintf(ofp, "%d ", list->smartSwitchLighting);
        fprintf(ofp, "%d %d %d %d %d ", list->loadControllers[0], list->loadControllers[1],
                list->loadControllers[2], list->loadControllers[3], list->loadControllers[4] );
        /*fprintf(ofp, "%d", )

                QString deviceName;
                int loadControllerID;
                int deviceID;
                bool incremental;
                int currState;*/
        fprintf(ofp, "\n");
        list = list->next;
    }
    fclose(ofp);

    return true;
}

bool IOManager::sendSmartSwitchData(int smartSwitchID)
{
    //ID Code->Device Type 3 Bits, 0b001
    //Number of Device     3 Bits, smartSwitchID
    //Poll                 1 Bit,  1
    //Spare               21 Bits  ------
    //Checksum             4 Bits

    char smartSwitchData[4];
    char checksum = 0;

    smartSwitchData[0] = (1 << 5) + ((smartSwitchID & 0x07) << 2) + (1 << 1);
    smartSwitchData[1] = 0;
    smartSwitchData[2] = 0;

    for(int i = 0; i < 3; i++)
    {
        checksum = checksum ^ ((smartSwitchData[i] & 0xF0) >> 4);
        checksum = checksum ^ (smartSwitchData[i] & 0x0F);
    }

    smartSwitchData[3] = 0;
    smartSwitchData[3] = checksum ^ ((smartSwitchData[3] & 0xF0) >> 4);

    std::cout << "GOT GESTURE, SENDING POLL" << std::endl;
    return uartOut.sendData(smartSwitchData, false);
}

bool IOManager::sendLoadControlData(int smartSwitchID, char devNum, char percentOn, bool fromSS)
{
    //ID Code->Device Type 3 Bits, 0b010
    //Number of Device     3 Bits
    //Fan/Light ID         2 Bits
    //Percentage           4 Bits
    //Spare               16 Bits
    //Checksum             4 Bits

    char loadControllerCounts[6] = {0,0,0,0,0,0};

    bool flag = true;
    room *list = roomList;
    device *devList = list->devices;
    char loadController = 0;
    int smartSwitchVal = 0;

    while(flag)
    {
        if(list->smartSwitchID == smartSwitchID)
        {
            if(list->numDevices == 0)
                return false;
            std::cout << "Load controller to control = " << list->loadControllers[0] << std::endl;
            devList = list->devices;
            for(int i = 0; i < (int)devNum; i++)
            {
                if(devList->next != NULL)
                    devList = devList->next;

            }

            std::cout << "state = " << (int) percentOn << std::endl;
            loadController = devList->loadControllerID;
            if(!devList->incremental)
            {
                std::cout << "Not incremental" << std::endl;
                if(devList->currState == 0)
                    devList->currState = 4;
                else
                    devList->currState = 0;
                smartSwitchVal = devList->currState;
            }
            else
            {
                std::cout << "incremental" << std::endl;
                std::cout << "state = " << (int) percentOn << std::endl;
                switch(percentOn)
                {
                case 0:
                //Switch from on to off
                    if(devList->currState > 0)
                        devList->currState = 0;
                    else
                        devList->currState = 4;
                    break;
                //1: 25% increase event
                case 1:
                    if(devList->currState <= 3)
                        devList->currState++;
                    break;
                //2: 50% increase event
                case 2:
                    if(devList->currState <= 2)
                        devList->currState += 2;
                //3: 75% increase event
                case 3:
                    if(devList->currState <= 1)
                        devList->currState += 3;
                //4: 25% decrease event
                case 4:
                    if(devList->currState >= 1)
                        devList->currState--;
                    break;
                //5: 50% decrease event
                case 5:
                    if(devList->currState >= 2)
                        devList->currState -= 2;
                //6: 75% decrease event
                case 6:
                    if(devList->currState >= 3)
                        devList->currState -= 3;
                default:
                    break;
                }
                smartSwitchVal = devList->currState;
                std::cout << "smartSwitchVal = " << (int) smartSwitchVal << std::endl;
            }

            std::cout << "Num LCs = " << list->numLoadControllers << std::endl;
            std::cout << "Fan/Light ID = " <<  (int)devNum <<std::endl;
            flag = false;
        }
        if(list->next == 0)
            flag = false;
        else
            list = list->next;
    }

    char val = 0;

    if(!fromSS)
    {
        std::cout << "Not from smart Switch calc, " << (int) percentOn << std::endl;
        if(percentOn == 0)
            val = 20;
        else if(percentOn == 1)
            val = 78;
        else if(percentOn == 2)
            val = 137;
        else if(percentOn == 3)
            val = 196;
        else if(percentOn == 4)
            val = 250;
        else
            ;
        devList->currState = percentOn;
    }
    else
    {
        std::cout << "From smart Switch calc, " << (int)smartSwitchVal << std::endl;

        if(smartSwitchVal == 0)
            val = 20;
        else if(smartSwitchVal == 1)
            val = 78;
        else if(smartSwitchVal == 2)
            val = 137;
        else if(smartSwitchVal == 3)
            val = 196;
        else if(smartSwitchVal == 4)
            val = 250;
        else
            ;
    }

    char loadControlData[4];
    char checksum = 0;

    loadControlData[0] = (2 << 5) + ((3 & 0x07) << 2);
    loadControlData[1] = 0x77;
    loadControlData[2] = val;

    for(int i = 0; i < 3; i++)
    {
        checksum = checksum ^ ((loadControlData[i] & 0xF0) >> 4);
        checksum = checksum ^ (loadControlData[i] & 0x0F);
    }

    loadControlData[3] = (devNum & 0x01) << 4;
    loadControlData[3] = (checksum ^ ((loadControlData[3] & 0xF0) >> 4)) + ((devNum & 0x01) << 4);

    printf("Load Controller Message = %d %d %d %d\n", loadControlData[0], loadControlData[1], loadControlData[2], loadControlData[3]);

    return uartOut.sendData(loadControlData, false);
}

bool IOManager::sendVentControlData(int ventControlID, bool onOff, int roomNum)
{
    //ID Code->Device Type 3 Bits, 0b011
    //Number of Device     3 Bits
    //On/Off               1 Bit
    //Spare               21 Bits
    //Checksum             4 Bits

    char ventControlData[4];
    char checksum = 0;

    ventControlData[0] = (3 << 5) + ((ventControlID & 0x07) << 2) + (onOff);
    ventControlData[1] = 0;
    ventControlData[2] = 0;

    for(int i = 0; i < 3; i++)
    {
        checksum = checksum ^ ((ventControlData[i] & 0xF0) >> 4);
        checksum = checksum ^ (ventControlData[i] & 0x0F);
    }

    ventControlData[3] = 0;
    ventControlData[3] = checksum ^ ((ventControlData[3] & 0xF0) >> 4);

    bool success = uartOut.sendData(ventControlData, false);

    if(success)
    {
        room *list = roomList;

        if(numRooms < roomNum)
            return false;

        for(int i = 0; i < roomNum; i++)
        {
            list = list->next;
        }

        list->ventControlStatus = onOff;
    }

    return success;

}

bool IOManager::setThresholds(int tempLow, int tempHigh, int humLow, int humHigh,
                              int lightLow, int lightHigh)
{
    currentRoomManagerRoom->minTemp = tempLow;
    currentRoomManagerRoom->maxTemp = tempHigh;
    currentRoomManagerRoom->minHum = humLow;
    currentRoomManagerRoom->maxHum = humHigh;
    currentRoomManagerRoom->minLight = lightLow;
    currentRoomManagerRoom->maxLight = lightHigh;
    return true;

}

void IOManager::setCurrentRoomManagerRoom(int roomIndex)
{
    room *list = roomList;

    if(roomIndex >= numRooms)
        return;

    for(int i = 0; i < roomIndex; i++)
    {
        list = list->next;
    }

    currentRoomManagerRoom = list;
}

int IOManager::getCurrentTemperature(int roomIndex)
{
    room *list = roomList;

    if(roomIndex >= numRooms)
        return 0;

    for(int i = 0; i < roomIndex; i++)
    {
        list = list->next;
    }

    return list->smartSwitchTemperature;
}

int IOManager::getCurrentHumidity(int roomIndex)
{
    room *list = roomList;

    if(roomIndex >= numRooms)
        return 0;

    for(int i = 0; i < roomIndex; i++)
    {
        list = list->next;
    }

    return list->smartSwitchHumidity;
}

int IOManager::getCurrentLighting(int roomIndex)
{
    room *list = roomList;

    if(roomIndex >= numRooms)
        return 0;

    for(int i = 0; i < roomIndex; i++)
    {
        list = list->next;
    }

    return list->smartSwitchLighting;
}

bool IOManager::getCurrentPIR(int roomIndex)
{
    room *list = roomList;

    if(roomIndex >= numRooms)
        return 0;

    for(int i = 0; i < roomIndex; i++)
    {
        list = list->next;
    }

    return list->smartSwitchPIR;
}

int IOManager::getCurrentSmartSwitchID(int roomIndex)
{
    room *list = roomList;

    if(roomIndex >= numRooms)
        return 0;

    for(int i = 0; i < roomIndex; i++)
    {
        list = list->next;
    }

    return list->smartSwitchID;
}

bool IOManager::updateLightDisplay(int smartSwitchID, short data)
{
    bool flag = true;
    room *list = roomList;

    while(flag)
    {
        if(list->smartSwitchID == smartSwitchID)
        {
            list->smartSwitchLighting = data;

            //Adaptive Control
            if(list->smartSwitchLighting > list->maxLight)
            {
                //TODO: Send Load Control Message
            }
            else if(list->smartSwitchLighting < list->minLight)
            {
                //TODO: Send Load Controller Message
            }

            //Calculate average
            room *list = roomList;
            int sum = 0;
            int avg;

            for(int i = 0; i < numRooms; i++)
            {
                sum+= list->smartSwitchLighting;
                list = list->next;
            }

            avg = sum / numRooms;
            lightData = avg;
            return true;
        }
        if(list->next == 0)
            return false;
        else
            list = list->next;
    }

    return false;
}

bool IOManager::updatePIRDisplay(int smartSwitchID, bool data)
{
    bool flag = true;
    room *list = roomList;

    while(flag)
    {
        if(list->smartSwitchID == smartSwitchID)
        {
            list->smartSwitchPIR = data;

            //Adaptive Control
            if(list->smartSwitchPIR)
            {
                //TODO: Send Load Control Message
            }
            else if(!list->smartSwitchPIR)
            {
                //TODO: Send Load Controller Message
            }

            return true;
        }
        if(list->next == 0)
            return false;
        else
            list = list->next;
    }

    return false;
}

bool IOManager::updateTemperatureDisplay(int smartSwitchID, short data)
{
    bool flag = true;
    room *list = roomList;
    int minute = 60000;

    while(flag)
    {
        if(list->smartSwitchID == smartSwitchID)
        {
            list->smartSwitchTemperature = data;

            //Adaptive Control
            if(list->smartSwitchTemperature > list->maxTemp)
            {
                /*//if(fanTimer.elapsed() > minute)
                //{
                    if(!list->ventControlStatus)
                    {
                        //fanTimer.start();
                        sendVentControlData(list->ventControlID, true);
                    }

                    std::cout << "It's too hot in here! Turn down the temperature!" << std::endl;
                    changeFanRelay(false);
                    changeColdRelay(false);
                //}*/
            }
            else if(list->smartSwitchTemperature <= list->maxTemp &&
                    list->smartSwitchTemperature >= list->minTemp)
            {
                //if(fanTimer.elapsed() > minute)
                //{
                /*    if(list->ventControlStatus)
                    {
                        //fanTimer.start();
                        sendVentControlData(list->ventControlID, false);
                    }

                    changeFanRelay(true);
                    changeColdRelay(true);
                    changeHotRelay(true);*/
                //}
            }
            else if(list->smartSwitchTemperature < list->minTemp)
            {
                /*//if(fanTimer.elapsed() > minute)
                //{
                    if(!list->ventControlStatus)
                    {
                        //fanTimer.start();
                        sendVentControlData(list->ventControlID, true);
                    }
                    //std::cout << "It's too cold in here! Turn up the temperature!" << std::endl;
                    changeFanRelay(false);
                    changeHotRelay(false);*/
                //}
            }

            //Calculate average
            room *list = roomList;
            int sum = 0;
            int avg;

            for(int i = 0; i < numRooms; i++)
            {
                sum+= list->smartSwitchTemperature;
                list = list->next;
            }

            avg = sum / numRooms;

            tempData = avg;
            return true;
        }
        if(list->next == 0)
            return false;
        else
            list = list->next;
    }

    return false;
}

bool IOManager::updateHumidityDisplay(int smartSwitchID, short data)
{
    bool flag = true;
    room *list = roomList;

    while(flag)
    {
        if(list->smartSwitchID == smartSwitchID)
        {
            list->smartSwitchHumidity = data;

            //Adaptive Control
            if(list->smartSwitchHumidity > list->maxHum)
            {
                //TODO: Send Load Controller Message
                std::cout << "It's too humid in here!" << std::endl;
            }
            else if(list->smartSwitchHumidity < list->minHum)
            {
                //TODO: Send Load Controller Message
                std::cout << "It's too dry in here!" << std::endl;
            }

            //Calculate average
            room *list = roomList;
            int sum = 0;
            int avg;

            for(int i = 0; i < numRooms; i++)
            {
                sum+= list->smartSwitchHumidity;
                list = list->next;
            }

            avg = sum / numRooms;

            humData = avg;

            return true;
        }
        if(list->next == 0)
            return false;
        else
            list = list->next;
    }

    return false;
}

bool IOManager::sendDeviceDetect()
{
    std::cout << "Sending device detect " << std::endl;

    char write[4] = {0x12,0x34,0xAB,0xCD}; //Smart Switches
    uartOut.sendData(write, false);

    uartOut.setDiscoveryMode(true);
    uartIn.setDiscoveryMode(true);
}

void IOManager::addPossibleDevice(char type, char num)
{
    std::cout << "Adding a possible device : " << (int)type << " : " << (int)num << std::endl;
    devType[numStartUpDevices] = type;
    devNum[numStartUpDevices] = num;
    numStartUpDevices++;
}

bool IOManager::sendDevStartup()
{
    for(int i = 0; i < numStartUpDevices; i++)
    {
        char write[4] = {0,0,0,0};
        char checksum = 0;

        write[0] = ((devType[i] & 0x07) << 5) + ((devNum[i] & 0x07) << 2) + 0x03;
        write[1] = 0xC0;
        write[2] = 0x00; //Number of load controllers

        room * list = roomList;

        if(devType[i] == 0x01)//If Smart Switch, set how many load controllers the room has
        {
            for(int j = 0; j < numRooms; j++)
            {
                if(list->smartSwitchID == devNum[i])
                {
                    write[2] = list->numLoadControllers;
                    j = numRooms;
                }
                list = list->next;
            }

            std::cout << "Number load Controllers for smart switch " << devNum[i] << " = " << (int)write[2] << std::endl;
        }

        for(int j = 0; j < 3; j++)
        {
            checksum = checksum ^ ((write[i] & 0xF0) >> 4);
            checksum = checksum ^ (write[i] & 0x0F);
        }

        write[3] = 0;
        write[3] = checksum ^ ((write[3] & 0xF0) >> 4);

        uartOut.sendData(write, false);
        usleep(1000);
    }
}

bool IOManager::addSmartSwitch(char devNum, char roomNum)
{
    room *list = roomList;

    if(roomNum >= numRooms)
        return false;

    for(int i = 0; i < roomNum; i++)
    {
        list = list->next;
    }

    if(list->smartSwitchID == -1)
    {
        list->smartSwitchID = devNum;
        numSmartSwitches++;
        return true;
    }

    return false;
}

bool IOManager::changeFanRelay(bool onOff)
{
    if(onOff)
    {
        if(uartGlove.gpio1_15.setValue(BlackLib::high))
            ;//std::cout << "Successfully wrote high to gpio1_15" << std::endl;
        else
            ;//std::cout << "Failed to write high to gpio1_15" << std::endl;
    }

    else
    {
        if(uartGlove.gpio1_15.setValue(BlackLib::low))
            ;//std::cout << "Successfully wrote low to gpio1_15" << std::endl;
        else
            ;//std::cout << "Failed to low high to gpio1_15" << std::endl;
    }
}

bool IOManager::changeColdRelay(bool onOff)
{
    if(onOff)
    {
        //if(uartGlove.gpio1_6.setValue(BlackLib::high))
            ;//std::cout << "Successfully wrote high to gpio1_15" << std::endl;
        //else
            ;//std::cout << "Failed to write high to gpio1_15" << std::endl;
    }

    else
    {
        //if(uartGlove.gpio1_6.setValue(BlackLib::low))
            ;//std::cout << "Successfully wrote low to gpio1_15" << std::endl;
        //else
            ;//std::cout << "Failed to low high to gpio1_15" << std::endl;
    }
}

bool IOManager::changeHotRelay(bool onOff)
{
    if(onOff)
    {
        //if(uartGlove.gpio1_2.setValue(BlackLib::high))
            ;//std::cout << "Successfully wrote high to gpio1_15" << std::endl;
        //else
            ;//std::cout << "Failed to write high to gpio1_15" << std::endl;
    }

    else
    {
       // if(uartGlove.gpio1_2.setValue(BlackLib::low))
            ;//std::cout << "Successfully wrote low to gpio1_15" << std::endl;
        //else
            ;//std::cout << "Failed to low high to gpio1_15" << std::endl;
    }
}
