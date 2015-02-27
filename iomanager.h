#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "bb_uart.h"

struct room {
  QString roomName;
  room *next;
};


class IOManager
{

private:
    IOManager();
    ~IOManager();
    IOManager(IOManager const&){}
    IOManager& operator=(IOManager const&){}  // assignment operator is private
    static IOManager* m_pInstance;

    bool initialize();
    int currentPIR;
    int currentTemp;
    int currentHumidity;

public:
    static IOManager* Instance();
    BB_UART uart;
    int numRooms;
    room *roomList;
    room *lastRoom;

    void startUART(){uart.start();}

    bool addRoom(QString roomName);
    bool updateTemperatureDisplay();
    bool updateHumidityDisplay();
    bool updatePIRDisplay();

    int receiveSmartSwitchData();
    bool sendSmartSwitchData();

    bool setCurrentPIR();
    int getCurrentPIR();

    bool setCurrentTemperature();
    int getCurrentTemperature();

    bool setCurrentHumidity();
    int getCurrentHumidity();

    bool setCurrentHVACCommand();
    int getCurrentHVACCommand();

};

#endif // IOMANAGER_H
