#ifndef COMMANDCREATOR_H
#define COMMANDCREATOR_H

#include <QThread>
#include "constants.h"

class CommandCreator: public QThread
{
private:
    int temperatureData[];
    int humidityData[];
    int currHumidity;
    int currTemp;

    bool initialize();
    bool processData(int dataType);
    bool processCapTouchData();
    bool processHumidityData();
    bool processLightData();
    bool processPIRData();
    bool processTemperatureData();
    bool newDataAvailFlag;

protected:
    void run();

public:
    CommandCreator();
    bool sendHVACCommand();
    void setNewDataAvail(bool flag);
    bool sendDeviceControlCommand(int devID, int commandID);
    bool sendHVACControlCommand(int commandID);

};

#endif // COMMANDCREATOR_H
