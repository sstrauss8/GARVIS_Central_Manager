#include <stddef.h>
#include "iomanager.h"


// Global static pointer used to ensure a single instance of the class.
IOManager* IOManager::m_pInstance = NULL;


IOManager::IOManager():
    uartIn(2),
    uartOut(1)
{
    numRooms = 0;
    initialize();
}

IOManager::~IOManager()
{
    uartIn.exit();
    uartOut.exit();
}

bool IOManager::initialize()
{
    roomList = new room;
    roomList->next = 0;
    roomList->roomName = "";
    roomList->devices = 0;
    roomList->devices = new device;
    roomList->devices->currState = 0;
    roomList->devices->deviceID = 0;
    roomList->devices->deviceName = "";
    roomList->devices->next = 0;
    roomList->minTemp = 32;
    roomList->maxTemp = 120;
    roomList->minHum = 0;
    roomList->maxHum = 100;
    roomList->minLight = 0;
    roomList->maxLight = 100;
    roomList->smartSwitchTemperature = 0;
    roomList->smartSwitchHumidity = 0;
    roomList->smartSwitchLighting = 0;

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
        list->devices->deviceID = 0;
        list->devices->deviceName = "";
        list->devices->next = 0;
        list->minTemp = 32;
        list->maxTemp = 120;
        list->minHum = 0;
        list->maxHum = 100;
        list->minLight = 0;
        list->maxLight = 100;
        list->smartSwitchTemperature = 0;
        list->smartSwitchHumidity = 0;
        list->smartSwitchLighting = 0;
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

    ifp = fopen("config.conf", "r");

    fscanf(ifp, "%d\n", &rooms);

    for(int i = 0; i < rooms; i++)
    {
        fscanf(ifp,"\n%[^\n]",c);
        QString currRoomName(c);
        addRoom(currRoomName);
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

QString IOManager::getDevice(int currRoomIndex, int deviceIndex)
{
    room *list = roomList;
    device *devList;

    if(currRoomIndex >= numRooms)
        return "";

    for(int i = 0; i < currRoomIndex; i++)
    {
        list = list->next;
    }

    devList = list->devices;

    if(devList == NULL)
        return "";

    for(int i = 0; i < deviceIndex; i++)
    {
        if(devList->next != NULL)
            devList = devList->next;
        else
            return "";
    }

    QString devID =  QString::number(devList->deviceID);
    return devID;
}

QString IOManager::getDeviceName(int currRoomIndex, int deviceIndex)
{
    room *list = roomList;
    device *devList;

    if(currRoomIndex >= numRooms)
        return "";

    for(int i = 0; i < currRoomIndex; i++)
    {
        list = list->next;
    }

    devList = list->devices;

    if(devList == NULL)
        return "";

    for(int i = 0; i < deviceIndex; i++)
    {
        if(devList->next != NULL)
            devList = devList->next;
        else
            return "";
    }

    return devList->deviceName;
}


int IOManager::getNumRooms()
{
    return numRooms;
}

bool IOManager::addDevice(int devID, int index)
{
    room *list = roomList;

    if(numRooms < index)
        return false;

    for(int i = 0; i < index; i++)
    {
        list = list->next;
    }

    bool flag = true;

    device *devList = list->devices;

    if(devList->deviceID == 0)
    {
        devList->currState = 0;
        devList->deviceID = devID;
        devList->next = 0;
        devList->deviceName = "Stuff";
        return true;
    }

    while(flag)
    {
        //Check if user is trying to enter name that already exists
        if(devList->deviceID == devID)
            return false;

        if(devList->next == NULL)
            flag = false;
        else
            devList = devList->next;

    }

    devList->next = new device;
    devList = devList->next;
    devList->next = 0;
    devList->deviceID = devID;
    devList->deviceName = "Things";
    devList->currState = 0;

    updateConfigFile();

    return true;
}

bool IOManager::removeDevice(int devID, int index)
{
    return true;
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
        fprintf(ofp, "%s\n", roomName);
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

bool IOManager::sendLoadControlData(int loadControlID, char devNum, char percentOn)
{
    //ID Code->Device Type 3 Bits, 0b010
    //Number of Device     3 Bits
    //Fan/Light ID         2 Bits
    //Percentage           4 Bits
    //Spare               16 Bits
    //Checksum             4 Bits

    char loadControlData[4];
    char checksum = 0;

    loadControlData[0] = (2 << 5) + ((loadControlID & 0x07) << 2) + (devNum & 0x03);
    loadControlData[1] = (percentOn & 0x0F << 4);
    loadControlData[2] = 0;

    for(int i = 0; i < 3; i++)
    {
        checksum = checksum ^ ((loadControlData[i] & 0xF0) >> 4);
        checksum = checksum ^ (loadControlData[i] & 0x0F);
    }

    loadControlData[3] = 0;
    loadControlData[3] = checksum ^ (loadControlData[3] & 0xF0 >> 4);

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
