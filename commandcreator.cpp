#include "commandcreator.h"
#include <iostream>

using namespace std;

CommandCreator::CommandCreator()
{
}

void CommandCreator::run()
{
    while(1)
    {
        cout << "TESTING" << endl;
        usleep(SLEEP_TIME_SECOND);
    }
}

bool CommandCreator::sendDeviceControlCommand(int devID, int commandID)
{
    return false;
}
