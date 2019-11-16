#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#pragma once

using namespace std;

class Box
{
private:
    int length;
    int width;
    int height;

public:
    Box();                  //get and set to get an access to privately declared things
    void setLength(int x);
    void setWidth(int x);
    void setHeight(int x);
    int getLength();
    int getWidth();
    int getHeight();


};



