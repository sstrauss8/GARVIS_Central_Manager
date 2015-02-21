#ifndef COMMANDCREATOR_H
#define COMMANDCREATOR_H

class CommandCreator
{
private:
    int temperatureData[];
    int humidityData[];
    int currHumidity;
    int currTemp;

    bool Initialize();
    bool ProcessData();
    bool ProcessTemperatureData();
    bool ProcessHumidityData();
    bool ProcessPIRData();

public:
    CommandCreator();
    bool SendHVACCommand();
    bool SendDeviceControlCommand(int devID, int commandID);
    bool SendHVACControlCommand(int commandID);
    void SetTemperature();
    void SetHumidity();

};

#endif // COMMANDCREATOR_H
