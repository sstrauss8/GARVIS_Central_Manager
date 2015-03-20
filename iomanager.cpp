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

bool IOManager::sendSmartSwitchData(int smartSwitchID, int pollBits)
{
    char smartSwitchData[100];
    uartOut->sendData(smartSwitchData);
    return true;
}

bool IOManager::sendLoadControlData(int loadControlID, char devType, char percentOn)
{
    char loadControlData[100];
    uartOut->sendData(loadControlData);
    return true;
}

bool IOManager::sendVentControlData(int ventControlID, bool onOff)
{
    char ventControlData[100];
    uartOut->sendData(ventControlData);
    return true;
}
