#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "bb_uart.h"
#include "commandcreator.h"

struct device {
    QString deviceName;
    int deviceID;
    int currState;
    device *next;
};

struct room {
  QString roomName;
  room *next;
  device *devices;
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
    bool updateConfigFile();

    CommandCreator m_CommandCreator;
    int currentPIR;
    int currentTemp;
    int currentHumidity;
    bool previousConfig;

public:
    static IOManager* Instance();
    BB_UART uartIn;
    BB_UART uartOut;
    int numRooms;
    room *roomList;
    room *lastRoom;

    void startUART(){uartIn.start();
                     uartOut.start();}

    bool addRoom(QString roomName);
    bool deleteRoom(int index);

    int getNumRooms();
    QString getRoom(int index);

    bool addDevice(int devID, int index);
    bool removeDevice(int devID, int index);

    QString getDevice(int currRoomIndex, int deviceIndex);
    QString getDeviceName(int currRoomIndex, int deviceIndex);

    bool updateTemperatureDisplay();
    bool updateHumidityDisplay();
    bool updatePIRDisplay();

    int receiveSmartSwitchData();
    bool sendSmartSwitchData(int smartSwitchID);
    bool sendLoadControlData(int loadControlID, char devType, char percentOn);
    bool sendVentControlData(int ventControlID, bool onOff);

    bool setCurrentPIR();
    int getCurrentPIR();

    bool setCurrentTemperature();
    int getCurrentTemperature();

    bool setCurrentHumidity();
    int getCurrentHumidity();

    bool ReadConfigFile();
    bool ClearConfigFile();

};

#endif // IOMANAGER_H
