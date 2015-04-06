#ifndef GLOVEAPI_H
#define GLOVEAPI_H

#include <QCursor>
#include <QString>
#include <QThread>

#include "iomanager.h"


class GloveAPI: public QThread
{
public:
    GloveAPI();

    unsigned int xCoord, yCoord;
    QCursor myCursor;
    QString output;
    unsigned char currentInput[100];
    int currentStart;
    int currentEnd;
    int numErrors;
    IOManager * p_IOControl;

    void calibrationMode(short currState);
    void ConvertSensorData();
    void ProcessSensorData();
    void useData(char data[]);

    enum AccelDirPalm { NONE = 0, DOWN = 1, UP = 2, LEFT = 3, RIGHT = 4, FORWARD = 5, BACKWARD = 6 };

    //Raw Sensor input data
    short accelX, accelY, accelZ;
    short gyroX, gyroY, gyroZ;
    short magnetX, magnetY, magnetZ;
    short flexThumb, flexIndex, flexMiddle, flexRing, flexPinky;
    short sound;
    short state;
    bool alreadyCalibrated;

    int mouseModeCounter;
    int previousIndexFlex;
    bool mouseMode;

    short * xAccel;
    short * yAccel;
    short * zAccel;

    float * xAccelConverted;
    float * yAccelConverted;
    float * zAccelConverted;
    short flexThumbCal, flexIndexCal, flexMiddleCal, flexRingCal, flexPinkyCal;

    //Converted Sensor input data
    float accelXConverted, accelYConverted, accelZConverted;
    float gyroXConverted, gyroYConverted, gyroZConverted;
    float magnetXConverted, magnetYConverted, magnetZConverted;

    float * xAccelHistory;
    float * yAccelHistory;
    float * zAccelHistory;
    int historyIndex;

    bool slideFlag1;
    bool slideFlag2;

    int slideCount1;
    int slideCount2;
    int slideWait;

protected:
    void run();

private:
    int numTimes;

};

#endif // GLOVEAPI_H
