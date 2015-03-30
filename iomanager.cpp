#include <stddef.h>
#include "iomanager.h"
#include <iostream>


// Global static pointer used to ensure a single instance of the class.
IOManager* IOManager::m_pInstance = NULL;

IOManager::IOManager():
    uartGlove(3),
    uartIn(2),
    uartOut(1)
{
    numRooms = 0;
    initialize();
}

IOManager::~IOManager()
{
    uartGlove.exit();
    uartIn.exit();
    uartOut.exit();
}

bool IOManager::initialize()
{
    roomList = new room;
    roomList->next = 0;
    roomList->roomName = "";
    roomList->devices = 0;
    //roomList->devices = new device;
    //roomList->devices->currState = 0;
    //roomList->devices->deviceID = -1;
    //roomList->devices->deviceName = "";
    //roomList->devices->next = 0;
    roomList->minTemp = 32;
    roomList->maxTemp = 120;
    roomList->minHum = 0;
    roomList->maxHum = 100;
    roomList->minLight = 0;
    roomList->maxLight = 100;
    roomList->smartSwitchID = numRooms;
    roomList->numDevices = 0;
    roomList->smartSwitchTemperature = 0;
    roomList->smartSwitchHumidity = 0;
    roomList->smartSwitchLighting = 0;
    roomList->loadControllers[0] = 0;
    roomList->loadControllers[1] = 0;
    roomList->loadControllers[2] = 0;
    roomList->loadControllers[3] = 0;
    roomList->loadControllers[4] = 0;

    humData = 0;
    tempData = 0;
    lightData = 0;


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
        list->minTemp = 32;
        list->maxTemp = 120;
        list->minHum = 0;
        list->maxHum = 100;
        list->minLight = 0;
        list->maxLight = 100;
        list->smartSwitchID = numRooms;
        list->numDevices = 0;
        list->smartSwitchTemperature = 0;
        list->smartSwitchHumidity = 0;
        list->smartSwitchLighting = 0;
        list->loadControllers[0] = 0;
        list->loadControllers[1] = 0;
        list->loadControllers[2] = 0;
        list->loadControllers[3] = 0;
        list->loadControllers[4] = 0;
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
        roomList->smartSwitchID = numRooms;
        roomList->numDevices = 0;
        roomList->smartSwitchTemperature = smartSwitchTemp;
        roomList->smartSwitchHumidity = smartSwitchHum;
        roomList->smartSwitchLighting = smartSwitchLight;
        roomList->loadControllers[0] = loadControllers[0];
        roomList->loadControllers[1] = loadControllers[1];
        roomList->loadControllers[2] = loadControllers[2];
        roomList->loadControllers[3] = loadControllers[3];
        roomList->loadControllers[4] = loadControllers[4];
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
        list->minTemp = minTemp;
        list->maxTemp = maxTemp;
        list->minHum = minHum;
        list->maxHum = maxHum;
        list->minLight = minLight;
        list->maxLight = maxLight;
        list->smartSwitchID = numRooms;
        list->numDevices = 0;
        list->smartSwitchTemperature = smartSwitchTemp;
        list->smartSwitchHumidity = smartSwitchHum;
        list->smartSwitchLighting = smartSwitchLight;
        list->loadControllers[0] = loadControllers[0];
        list->loadControllers[1] = loadControllers[1];
        list->loadControllers[2] = loadControllers[2];
        list->loadControllers[3] = loadControllers[3];
        list->loadControllers[4] = loadControllers[4];
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

bool IOManager::addDevice(int devID, int index, int loadControllerID, QString devName)
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
        devList->incremental = 0;
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
        if(devList->next == NULL)
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
    smartSwitchData[3] = checksum ^ (smartSwitchData[3] & 0xF0 >> 4);

    return uartOut.sendData(smartSwitchData);
}

bool IOManager::sendLoadControlData(int smartSwitchID, char devNum, char percentOn)
{
    //ID Code->Device Type 3 Bits, 0b010
    //Number of Device     3 Bits
    //Fan/Light ID         2 Bits
    //Percentage           4 Bits
    //Spare               16 Bits
    //Checksum             4 Bits

    char loadControllerCounts[6] = {0,0,0,0,0,0};
    printf("Id code = 2, ");

    bool flag = true;
    room *list = roomList;
    device *devList = list->devices;
    char loadController = 0;

    while(flag)
    {
        if(list->smartSwitchID == smartSwitchID)
        {
            if(list->numDevices == 0)
                return false;

            devList = list->devices;
            for(int i = 0; i < (int)devNum; i++)
            {
                loadControllerCounts[devList->loadControllerID]++;
                if(devList->next != NULL)
                    devList = devList->next;

            }

            loadController = devList->loadControllerID;
            if(devList->incremental == 0 && devList->currState == 10)
                percentOn = 0;
            printf("Num Device = %d ", loadControllerCounts[loadController]);
            printf("Fan/Light ID = %d ", devNum);
            printf("Percentage = %d ", percentOn);
            devList->currState = percentOn;
            flag = false;
        }
        if(list->next == 0)
            flag = false;
        else
            list = list->next;
    }

    char loadControlData[4];
    char checksum = 0;

    loadControlData[0] = (2 << 5) + ((loadControllerCounts[loadController] & 0x07) << 2) + (devNum & 0x03);
    loadControlData[1] = ((percentOn & 0x0F) << 4);
    loadControlData[2] = 0;

    for(int i = 0; i < 3; i++)
    {
        checksum = checksum ^ ((loadControlData[i] & 0xF0) >> 4);
        checksum = checksum ^ (loadControlData[i] & 0x0F);
    }

    loadControlData[3] = 0;
    loadControlData[3] = checksum ^ (loadControlData[3] & 0xF0 >> 4);

    printf("Load Controller Message = %d %d %d %d\n", loadControlData[0], loadControlData[1], loadControlData[2], loadControlData[3]);

    return uartOut.sendData(loadControlData);
}

bool IOManager::sendVentControlData(int ventControlID, bool onOff)
{
    //ID Code->Device Type 3 Bits, 0b011
    //Number of Device     3 Bits
    //On/Off               1 Bit
    //Spare               21 Bits
    //Checksum             4 Bits

    char ventControlData[4];
    char checksum = 0;

    ventControlData[0] = (3 << 5) + ((ventControlID & 0x07) << 2) + (onOff << 1);
    ventControlData[1] = 0;
    ventControlData[2] = 0;

    for(int i = 0; i < 3; i++)
    {
        checksum = checksum ^ ((ventControlData[i] & 0xF0) >> 4);
        checksum = checksum ^ (ventControlData[i] & 0x0F);
    }

    ventControlData[3] = 0;
    ventControlData[3] = checksum ^ (ventControlData[3] & 0xF0 >> 4);

    return uartOut.sendData(ventControlData);
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
            lightData = data;
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

    std::cout << " TEMPERATURE RAW = " << data << std::endl;
    while(flag)
    {
        if(list->smartSwitchID == smartSwitchID)
        {
            list->smartSwitchLighting = data;
            tempData = data;
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
            list->smartSwitchLighting = data;
            humData = data;
            return true;
        }
        if(list->next == 0)
            return false;
        else
            list = list->next;
    }

    return false;
}
