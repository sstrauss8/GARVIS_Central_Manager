#include <stddef.h>
#include "iomanager.h"


// Global static pointer used to ensure a single instance of the class.
IOManager* IOManager::m_pInstance = NULL;


IOManager::IOManager():
    uart()
{
    initialize();
    numRooms = 0;
}

IOManager::~IOManager()
{
    uart.exit();
}

bool IOManager::initialize()
{
    roomList = new room;
    roomList->next = 0;
    roomList->roomName = "";

    return true;
}

bool IOManager::addRoom(QString name)
{
    room *list = roomList;
    while(list->next != 0)
    {
        if(QString::compare(list->roomName, name, Qt::CaseInsensitive) == 0)
            return false;

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
    }

    numRooms++;

    return true;
}

IOManager* IOManager::Instance()
{
       if (!m_pInstance)   // Only allow one instance of class to be generated.
          m_pInstance = new IOManager;

       return m_pInstance;
}
