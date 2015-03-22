#ifndef COMMANDCREATOR_H
#define COMMANDCREATOR_H

#include <QThread>
#include "constants.h"
#include "iomanager.h"

class CommandCreator: public QThread
{
private:
    int temperatureData[];
    int humidityData[];
    int currHumidity;
    int currTemp;
    IOManager * p_IOControl;

    bool initialize();
    bool processData(char data[]);
    bool processCapTouchData(char smartSwitchID, short rawData);
    bool processHumidityData(char smartSwitchID, short rawData);
    bool processLightData(char smartSwitchID, short rawData);
    bool processPIRData(char smartSwitchID, short rawData);
    bool processTemperatureData(char smartSwitchID, short rawData);

protected:
    void run();

public:
    CommandCreator();
    bool sendHVACCommand();
    bool sendDeviceControlCommand(int devID, int commandID);
    bool sendHVACControlCommand(int commandID);

};

#endif // COMMANDCREATOR_H
