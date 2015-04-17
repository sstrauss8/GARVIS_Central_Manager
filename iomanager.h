#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "bb_uart.h"
#include <QElapsedTimer>

struct device {
    QString deviceName;
    int loadControllerID;
    int deviceID;
    bool incremental;
    int currState;
    device *next;
};

struct room {
  QString roomName;
  int minTemp;
  int maxTemp;
  int minHum;
  int maxHum;
  int minLight;
  int maxLight;
  int smartSwitchID;
  int smartSwitchTemperature;
  int smartSwitchHumidity;
  int smartSwitchLighting;
  bool smartSwitchPIR;
  room *next;
  device *devices;
  bool ventControlConnected;
  bool ventControlStatus;
  int ventControlID;
  int numLoadControllers;
  int numDevices;
  int loadControllers[5];
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
    bool previousConfig;

    bool gpio1On;

    QElapsedTimer coolDownTimer;
    QElapsedTimer warmUpTimer;
    QElapsedTimer fanTimer;


public:
    static IOManager* Instance();
    BB_UART uartIn;
    BB_UART uartOut;
    BB_UART uartGlove;

    int numRooms;
    room *roomList;
    room *lastRoom;
    room *currentRoomManagerRoom;
    int humData, tempData, lightData;
    int numStartUpDevices;
    int numSmartSwitches;
    bool allowStatusMonitor;
    char devNum[8];
    char devType[8];

    void startUART(){uartIn.start();
                     uartOut.start();
                     uartGlove.start();}

    bool addRoom(QString roomName);
    bool addRoom(QString name, int minTemp, int maxTemp, int minHum, int maxHum,
                 int minLight, int maxLight, int smartSwitchID, int smartSwitchTemp,
                 int smartSwitchHum, int smartSwitchLight, int loadControllers[]);
    bool deleteRoom(int index);

    void setCurrentRoomManagerRoom(int roomIndex);
    int getNumRooms();
    void setRoomClear();
    QString getRoom(int index);

    bool addDevice(int devID, int index, int loadControllerID, QString devName, bool vc);
    bool removeDevice(int devID, int index);

    bool addLoadController(int loadControllerID, int index);
    bool addVentController(int ventControllerID, int index);
    bool getLoadControllers(int roomID, int lc[]);
    int getVentControllerID(int roomNum);
    bool getVentControllerStatus(int roomNum);
    void setVentControllerStatus(int roomNum, bool status);

    QString getDevice(int currRoomIndex, int deviceIndex, int lc);
    QString getDeviceName(int currRoomIndex, int deviceIndex, int lc);
    int getDevicePercent(int currRoomIndex, int deviceIndex, int lc);

    bool updateTemperatureDisplay(int smartSwitchID, short data);
    bool updateHumidityDisplay(int smartSwitchID, short data);
    bool updateLightDisplay(int smartSwitchID, short data);
    bool updatePIRDisplay(int smartSwitchID, bool data);


    int receiveSmartSwitchData();
    bool sendSmartSwitchData(int smartSwitchID);
    bool sendLoadControlData(int smartSwitchID, char devType, char percentOn, bool fromSS);
    bool sendVentControlData(int ventControlID, bool onOff, int roomNum);


    bool sendDevStartup();
    bool sendDeviceDetect();
    void addPossibleDevice(char devType, char devNum);
    void clearPossibleDeviceList();
    bool addSmartSwitch(char devNum, char roomNum);

    bool setThresholds(int tempLow, int tempHigh, int humLow, int humHigh,
                       int lightLow, int lightHigh);

    bool setIncremental(bool setIncr, int devID, int index, int loadControllerID, QString devName);

    bool changeFanRelay(bool onOff);
    bool changeColdRelay(bool onOff);
    bool changeHotRelay(bool onOff);

    bool setCurrentPIR();

    bool setCurrentTemperature();
    int getCurrentTemperature(int roomIndex);

    bool setCurrentHumidity();
    int getCurrentHumidity(int roomIndex);
    bool getCurrentPIR(int roomIndex);
    int getCurrentLighting(int roomIndex);

    int getCurrentSmartSwitchID(int roomIndex);

    bool ReadConfigFile();
    bool updateConfigFile();
    bool ClearConfigFile();

};

#endif // IOMANAGER_H
