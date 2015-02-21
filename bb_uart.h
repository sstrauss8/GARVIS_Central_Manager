#ifndef BB_UART_H
#define BB_UART_H
#include <QThread>
#include "BlackLib/v2_0/BlackGPIO.h"
#include "BlackLib/v2_0/BlackCore.h"
#include "BlackLib/v2_0/BlackUART.h"

class BB_UART: public QThread
{
    public:
        QString output;
        BB_UART();

    protected:
        void run();

    private:
        BlackLib::BlackUART uart;
};

#endif // BB_UART_H
