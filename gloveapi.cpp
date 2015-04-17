#include "gloveapi.h"
#include <unistd.h>

GloveAPI::GloveAPI()
{
    p_IOControl = IOManager::Instance();

    numTimes = 0;
    currentStart = 0;
    currentEnd = 0;
    accelX = 0;
    accelY = 0;
    accelZ = 0;
    gyroX = 0;
    gyroY = 0;
    gyroZ = 0;
    magnetX = 0;
    magnetY = 0;
    magnetZ = 0;
    flexThumb = 0;
    flexIndex = 0;
    flexMiddle = 0;
    flexRing = 0;
    flexPinky = 0;
    sound = 0;
    state = 0;
    alreadyCalibrated = false;
    mouseModeCounter = 0;
    previousIndexFlex = 0;
    mouseMode = false;

    xAccel = new short [6];
    yAccel = new short [6];
    zAccel = new short [6];

    xAccelConverted = new float [6];
    yAccelConverted = new float [6];
    zAccelConverted = new float [6];

    flexThumbCal = 0;
    flexIndexCal = 0;
    flexMiddleCal = 0;
    flexRingCal = 0;
    flexPinkyCal = 0;

    xAccelHistory = new float [5];
    yAccelHistory = new float [5];
    zAccelHistory = new float [5];
    historyIndex = 0;

    memset(xAccel, 0, 6);
    memset(yAccel, 0, 6);
    memset(zAccel, 0, 6);

    memset(xAccelHistory, 0, 5);
    memset(yAccelHistory, 0, 5);
    memset(zAccelHistory, 0, 5);

    memset(currentInput, 0, sizeof(currentInput));

    accelXConverted = 0.0;
    accelYConverted = 0.0;
    accelZConverted = 0.0;
    gyroXConverted = 0.0;
    gyroYConverted = 0.0;
    gyroZConverted = 0.0;
    magnetXConverted = 0.0;
    magnetYConverted = 0.0;
    magnetZConverted = 0.0;

    xCoord = 200;
    yCoord = 200;

    numErrors = 0;
    inGestureDetectMode = false;

    slideFlag1 = false;
    slideFlag2 = false;
    slideCount1 = 0;
    slideCount2 = 0;
    slideWait = 0;

    measuredRoomNum = false;
    measuredDevNum = false;

    currentRoomNum = 0;
    currentDeviceNum = 0;
}

void GloveAPI::useData(char data[])
{
    /*QByteArray data = 0;// = serial->readAll();
    unsigned char* dataArray = (unsigned char*)data.data();*/

    if(currentEnd >= 100)
    {
        currentEnd = 0;
        memset(currentInput, 0, sizeof(currentInput));
        std::cout << "Current end too large" << std::endl;
    }

    QString tempString = "";
    for(int i = 0; i < 34; i++)
    {
        currentInput[currentEnd] = data[i];
        currentEnd++;
        if(data[i]!='S'&& data[i]!='T'&& data[i]!='E'&& data[i]!='N')
            tempString.sprintf("%u ", data[i]);
        else
            tempString.sprintf("%c ", data[i]);

        output.append(tempString);

        if(currentInput[0] != 'S')
        {
            for(int i = 0; i < 99; i++)
            {
               currentInput[i] = currentInput[i+1];
            }
            currentEnd--;
        }
        else
        {
            //std::cout << "S IS THE FIRST ONE!" << std::endl;
            //std::cout << "Current input 0,1,32,33 = " << currentInput[0] << " " << currentInput[1] << " " << currentInput[32] << " " << currentInput[33] << " " << std::endl;
        }

        if(currentEnd > 35)
        {
            currentEnd = 0;
        }

        if(currentInput[0] == 'S' && currentInput[1] == 'T' && currentInput[32] == 'E' && currentInput[33] == 'N')
        {
            numTimes++;
            if(numTimes % 5000 == 0)
                std::cout << "Read glove values correctly: " << numTimes << std::endl;
            else if(numTimes > 100000)
                numTimes = 0;
            else
                ;
            accelX =(signed short) (currentInput[2] + (currentInput[3]<<8));
            accelY = currentInput[4] + (currentInput[5]<<8);
            accelZ = currentInput[6] + (currentInput[7]<<8);
            gyroX = currentInput[8] + (currentInput[9]<<8);
            gyroY = currentInput[10] + (currentInput[11]<<8);
            gyroZ = currentInput[12] + (currentInput[13]<<8);
            magnetX = currentInput[14] + (currentInput[15]<<8);
            magnetY = currentInput[16] + (currentInput[17]<<8);
            magnetZ = currentInput[18] + (currentInput[19]<<8);
            flexThumb = currentInput[20] + (currentInput[21]<<8);
            previousIndexFlex = flexIndex;
            flexIndex = currentInput[22] + (currentInput[23]<<8);
            flexMiddle = currentInput[24] + (currentInput[25]<<8);
            flexRing = currentInput[26] + (currentInput[27]<<8);
            flexPinky = currentInput[28] + (currentInput[29]<<8);

            ConvertSensorData();

            //Check if state was sent correctly to enter calibration mode
            if(currentInput[30] != state)
            {
               state = currentInput[30];
               alreadyCalibrated = false;
            }

            if(state < 3 || (state > 4 && state < 8))
            {
                std::cout << "State = " << state << std::endl;
            }

            if(state == 0 || alreadyCalibrated)
                ;
            else if(state < 3)//If calibration mode state, go through cal mode
                calibrationMode(state);
            else if(state == 4)
            {
                measuredRoomNum = false;
                measuredDevNum = false;
            }
            else if(state == 5 && !measuredRoomNum)//If room num detect state and
                recognizeNumber(5);                //we haven't already detected

            else if(state == 6 && !measuredDevNum) //If device num detect state and
                recognizeNumber(6);                //we haven't already detected
            else;

            //Flush out end sync word
            currentInput[32] = 0;
            currentInput[33] = 0;
            currentEnd = 0;
        }
    }
    //serial->flush();

    if(currentRoomNum >= 0 && currentDeviceNum >= 0)
    {
        ProcessSensorData();
    }
}

//Calibration mode will conduct 3 readings of each state and average them
void GloveAPI::calibrationMode(short currState)
{
    QString tempString = "";
    int index = currState - 1;

    if(currState == 1)
        ;//ui->prompt->setText("Palm Down");
    else if(currState == 2)
        ;//ui->prompt->setText("Palm Up");
    else if(currState == 3)
        ;//ui->prompt->setText("Palm Left");
    else if(currState == 0)
        ;//ui->prompt->setText("");
        ;

    //useData();
    xAccel[index] = accelX;
    yAccel[index] = accelY;
    zAccel[index] = accelZ;

    if(currState == 2)
    {
        flexThumbCal = flexThumb;
        flexIndexCal = flexIndex;
        flexMiddleCal = flexMiddle;
        flexRingCal = flexRing;
        flexPinkyCal = flexPinky;
    }

    std::cout << "Flex thumb cal = " << flexThumbCal << ", index = " << flexIndexCal << ", middle = " <<
                 flexMiddleCal << ", ring = " << flexRingCal <<  ", pinky = " << flexPinkyCal << std::endl;

    //useData();
    /*xAccel[index] = (accelX + xAccel[index]) / 2;
    yAccel[index] = (accelY + yAccel[index]) / 2;
    zAccel[index] = (accelZ + zAccel[index]) / 2;

    if(currState == 1)
    {
        flexThumbCal = (flexThumbCal + flexThumb) / 2;
        flexIndexCal = (flexIndexCal + flexIndex) / 2;
        flexMiddleCal = (flexMiddleCal + flexMiddle) / 2;
        flexRingCal = (flexRingCal + flexRing) / 2;
        flexPinkyCal = (flexPinkyCal + flexPinky) / 2;
    }

    //useData();
    xAccel[index] = ((accelX + xAccel[index]) * 2) / 3;
    yAccel[index] = ((accelY + yAccel[index]) * 2) / 3;
    zAccel[index] = ((accelZ + zAccel[index]) * 2) / 3;

    if(currState == 1)
    {
        flexThumbCal = (flexThumbCal*2 + flexThumb) / 3;
        flexIndexCal = (flexIndexCal*2 + flexIndex) / 3;
        flexMiddleCal = (flexMiddleCal*2 + flexMiddle) / 3;
        flexRingCal = (flexRingCal*2 + flexRing) / 3;
        flexPinkyCal = (flexPinkyCal*2 + flexPinky) / 3;
    }*/

    if(currState == 3)
    {
        /*ui->lineEdit_palmDown->setText(tempString.sprintf("%d, %d, %d",xAccel[0], yAccel[0], zAccel[0]));
        ui->lineEdit_palmUp->setText(tempString.sprintf("%d, %d, %d",xAccel[1], yAccel[1], zAccel[1]));
        ui->lineEdit_palmLeft->setText(tempString.sprintf("%d, %d, %d",xAccel[2], yAccel[2], zAccel[2]));
        ui->lineEdit_flexIndex->setText(tempString.sprintf("%d", flexIndexCal));*/
    }

    alreadyCalibrated = true;
}

//Converts raw analog data into understandable sensor data
void GloveAPI::ConvertSensorData()
{
    accelXConverted = (float) accelX * 32 / 8192 * 9.81;
    accelYConverted = (float) accelY * 32 / 8192  * 9.81;
    accelZConverted = (float) accelZ * 32 / 8192 * 9.81;
    gyroXConverted = (float) gyroX * 4000 / 65536;
    gyroYConverted = (float) gyroY * 4000 / 65536;
    gyroZConverted = (float) gyroZ * 4000 / 65536;
    magnetXConverted = (float) magnetX * 16.2 / 65536 * 1000;
    magnetYConverted = (float) magnetY * 16.2 / 65536 * 1000;
    magnetZConverted = (float) magnetZ * 16.2 / 65536 * 1000;
}

void GloveAPI::ProcessSensorData()
{
    //Flex index edge is the point in which anything higher is considered to be flexed
    //and anything lower is considered to be unflexed
    int flexIndexEdge = flexIndexCal + 30;

    //Start powerpoint when not in mouse mode
    if(previousIndexFlex > flexIndexEdge && flexIndex < flexIndexEdge && !mouseMode)
    {
#ifdef _WIN32
        keybd_event(VK_F5, 0, KEYEVENTF_EXTENDEDKEY, 0);
        keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
#endif
    }
    //Click if in mouse mode
    else if(previousIndexFlex > flexIndexEdge && flexIndex < flexIndexEdge && mouseMode)
    {
#ifdef _WIN32
        mouse_event(MOUSEEVENTF_LEFTDOWN,0, 0, 0,0);
        mouse_event(MOUSEEVENTF_LEFTUP,0, 0, 0,0);
#endif
    }
    else if(flexIndex > flexIndexEdge)
    {
        mouseModeCounter++;
        //If index sensor is flexed for a second
        if(mouseModeCounter > 100)
        {
            mouseMode = !mouseMode;
            mouseModeCounter = 0;
        }
    }
    else
    {
        mouseModeCounter = 0;
    }


    //If in mouse mode allow accelerometer data to control
    //mouse location and skip all other control.
    if(mouseMode)
    {
        if(accelY > 200 && xCoord < 1500)
            xCoord+=1;
        if(accelY < -200 && xCoord > 20)
            xCoord-=1;
        if(accelX < -200 && yCoord < 1500)
            yCoord+=1;
        if(accelX > 200 && yCoord > 20)
            yCoord-=1;

        //myCursor.setPos(xCoord,yCoord);

        //return;
    }

    for(int i = 1; i < 5; i++)
    {
        xAccelHistory[i] = xAccelHistory[i-1];
        yAccelHistory[i] = yAccelHistory[i-1];
        zAccelHistory[i] = zAccelHistory[i-1];
    }

    xAccelHistory[0] = accelXConverted;
    yAccelHistory[0] = accelYConverted;
    zAccelHistory[0] = accelZConverted;

    //Detect left sliding motion
    if(historyIndex < 3)
        historyIndex++;
    else if( slideWait > 0 && slideWait < 200 )
        slideWait++;
    else
    {
        slideWait = 0;
        bool leftSlide = false;
        bool rightSlide = false;
        if(yAccelHistory[0] > 9.0 && yAccelHistory[1] > 9.0 && yAccelHistory[2] > 9.0
                && yAccelHistory[3] > 9.0 && yAccelHistory[4] > 9.0)
        {
            leftSlide = true;
        }
        if(yAccelHistory[0] < -8.0 && yAccelHistory[1] < -8.0 && yAccelHistory[2] < -8.0
                && yAccelHistory[3] < -8.0 && yAccelHistory[4] < -8.0)
        {
            rightSlide = true;
        }
        if(leftSlide || rightSlide)
        {
            //If hand sliding, part 1
            if(abs(zAccelHistory[0]) > abs(zAccelHistory[1]) || abs(zAccelHistory[1]) > abs(zAccelHistory[2]))
            {
                slideFlag1 = true;
            }

            //If hand is horizontally sliding, part 2
            if(slideFlag1)
            {
                if((slideCount1++ < 60) && ((zAccelHistory[0] < 0 && zAccelHistory[1] > 0)))
                {
                    slideFlag2 = true;
                }
                else if(slideCount1 >= 60)
                {
                    slideFlag1 = false;
                    slideCount1 = 0;
                }
                else{;}
            }

            //If hand is horizontally sliding, part 3
            if(slideFlag2)
            {
                if((slideCount2++ < 60) && (zAccelHistory[0] > zAccelHistory[1]))
                {
                    if(leftSlide)
                    {
                        std::cout << "Left Slide for room "<< currentRoomNum << ", dev " << currentDeviceNum << std::endl;
                        int smartSwitchID = p_IOControl->getCurrentSmartSwitchID(currentRoomNum - 1);

                        p_IOControl->sendLoadControlData(smartSwitchID, (char)currentDeviceNum - 1 , 4, false);
                        //p_IOControl->changeFanRelay(true);
                        //p_IOControl->sendVentControlData(1, true, 0);
                        currentRoomNum = -1;
                        currentDeviceNum = -1;
#ifdef _WIN32
                        keybd_event(VK_RIGHT, 0, KEYEVENTF_EXTENDEDKEY, 0);
                        keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
                        //mouse_event(MOUSEEVENTF_LEFTDOWN,0, 0, 0,0);
                        //mouse_event(MOUSEEVENTF_LEFTUP,0, 0, 0,0);
#endif
                    }
                    if(rightSlide)
                    {
                        std::cout << "Right Slide for room "<< currentRoomNum << ", dev " << currentDeviceNum << std::endl;
                        int smartSwitchID = p_IOControl->getCurrentSmartSwitchID(currentRoomNum - 1);

                        p_IOControl->sendLoadControlData(smartSwitchID, (char)currentDeviceNum - 1, 0, false);
                        //p_IOControl->changeFanRelay(false);
                        //p_IOControl->sendVentControlData(1, false, 0);
                        currentRoomNum = -1;
                        currentDeviceNum = -1;
#ifdef _WIN32
                        keybd_event(VK_LEFT, 0, KEYEVENTF_EXTENDEDKEY, 0);
                        keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
                        //mouse_event(MOUSEEVENTF_WHEEL,0, 0, 120,0);
#endif
                    }
                    slideFlag1 = false;
                    slideFlag2 = false;
                    slideCount1 = 0;
                    slideCount2 = 0;
                    slideWait = 1;
                    historyIndex = 0;
                    memset(zAccelHistory, 0, 5);
                }
                else if(slideCount2 >= 60)
                {
                    slideFlag1 = false;
                    slideFlag2 = false;
                    slideCount1 = 0;
                    slideCount2 = 0;
                }
                else{;}
            }
        }
    }

}

void GloveAPI::run()
{
    while(1)
    {
        if(p_IOControl->uartGlove.receivedGloveData)
        {
            useData(p_IOControl->uartGlove.gloveData);
            p_IOControl->uartGlove.receivedGloveData = false;
        }
        msleep(1);
    }
}

void GloveAPI::recognizeNumber(char state)
{
    int flexIndexEdge = flexIndexCal + 20;
    int flexMiddleEdge = flexMiddleCal + 20;
    int flexRingEdge = flexRingCal + 20;
    int flexPinkyEdge = flexPinkyCal + 20;

    int currentRunningValue = -1;

    if(state == 5)
        currentRoomNum = -1;
    else if(state == 6)
        currentDeviceNum = -1;

    std::cout << "IN REC NUM Flex thumb cal = " << flexThumbCal << ", index = " << flexIndexCal << ", middle = " <<
                 flexMiddleCal << ", ring = " << flexRingCal <<  ", pinky = " << flexPinkyCal << std::endl;

    std::cout << "IN REC NUM Flex thumb = " << flexThumb << ", index = " << flexIndex << ", middle = " <<
                 flexMiddle << ", ring = " << flexRing <<  ", pinky = " << flexPinky << std::endl;


    if(flexIndex < flexIndexEdge)//If index finger is not bent
    {
        if(flexMiddle < flexMiddleEdge)//If middle finger is not bent
        {
            if(flexRing < flexRingEdge)//If ring finger is not bent
            {
                currentRunningValue = 3;
                if(flexPinky < flexPinkyEdge)//If pinky is not bent
                {
                    //currentRunningValue = 4;
                }
                else//Index, middle, and ring are straight, pinky bent
                {
                    //currentRunningValue = 3;
                }
            }
            else //Ring finger is bent
            {
                currentRunningValue = 2;
                if(flexPinky < flexPinkyEdge)//If pinky is not bent, invalid
                {
                    //currentRunningValue = -1;
                }
                else//Index and middle straight, pinky and ring bent
                {
                    //currentRunningValue = 2;
                }
            }
        }
        else
        {
            if(flexRing < flexRingEdge)//If ring finger is not bent, invalid
            {
                currentRunningValue = -1;
            }
            else
            {
                currentRunningValue = 1;
                if(flexPinky < flexPinkyEdge)//If pinky is not bent, invalid
                {
                    //currentRunningValue = -1;
                }
                else//Only pointer is straight, meaning a one was detected
                {
                    //currentRunningValue = 1;
                }
            }
        }
    }
    else//If index finger is bent, invalid data
    {
        currentRunningValue = -1;
    }


    if(state == 5)//Set detected gesture to appropriate variable
    {
        currentRoomNum = currentRunningValue;
        measuredRoomNum = true;
        printf("state 5 run through");
    }
    else if(state == 6)
    {
        currentDeviceNum = currentRunningValue;
        measuredDevNum = true;
        printf("state 6 run through");
    }

    printf("Measured room number = %d, measured device number = %d\n", currentRoomNum, currentDeviceNum);

}
