#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "truck.h"
#include "box.h"

using namespace std;

Box :: Box()            //constructor
{
    length = width = height = 5;
}

//get and set functions to get access to privately declared things

void Box :: setLength(int x)
{
    length = x;
}

void Box :: setWidth(int x)
{
    width = x;
}

void Box :: setHeight(int x)
{
    height = x;
}

int Box :: getLength()
{
    return length;
}

int Box :: getWidth()
{
    return width;
}

int Box :: getHeight()
{
    return height;
}



