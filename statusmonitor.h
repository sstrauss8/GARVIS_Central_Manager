#ifndef STATUSMONITOR_H
#define STATUSMONITOR_H

#include <QThread>
#include "iomanager.h"

class StatusMonitor: public QThread
{

private:

    IOManager * p_IOControl;

    bool Initialize();
    int timerId;
    int currentState;

protected:
    void run();
    void timerEvent(QTimerEvent *event);


public:
    StatusMonitor();
    ~StatusMonitor();

};

#endif // STATUSMONITOR_H
