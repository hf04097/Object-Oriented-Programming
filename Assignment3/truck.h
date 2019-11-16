#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "box.h"
#pragma once

class Truck
{
private:
                            //making variables private
    float petrol;
    float money;
    float fullMileage;
    float emptyMileage;
    Box* towardsBoxes;
    char driver[32];

public:

    Truck();
    void Load(int numBox);
    void Unload(int numBox);
    bool Cost();

    void setDriver(char arr[]);
    void setPetrol(float);            //using get and set to access private variables
    void setMoney(float);
    void setFullMileage(float);
    void setEmptyMileage(float);

    char* getDriver();
    float getPetrol();
    float getMoney();
    float getFullMileage();
    float getEmptyMileage();
};
