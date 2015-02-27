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
    bool processData();
    bool processTemperatureData();
    bool processHumidityData();
    bool processPIRData();

protected:
    void run();

public:
    CommandCreator();
    bool sendHVACCommand();
    bool sendDeviceControlCommand(int devID, int commandID);
    bool sendHVACControlCommand(int commandID);

};

#endif // COMMANDCREATOR_H
