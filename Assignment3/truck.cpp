#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "truck.h"



using namespace std;

Truck :: Truck()
{
     towardsBoxes = 0;
}

void Truck ::Load(int numBox)
{
    towardsBoxes = new Box[numBox];         //a pointer pointing towards an array of boxes

    int counter = 0;
    cout<<"LOAD DIMENSIONS"<<endl;
    while(counter != numBox)        //giving a random length,width & height to all boxes
    {
        (towardsBoxes[counter]).setLength(rand()%25+5);
        (towardsBoxes+counter)->setWidth((rand()%25)+5);
        (towardsBoxes+counter)-> setHeight(rand()%25+5);
        cout<<"dimensions of the box are:  length: "<<(towardsBoxes[counter]).getLength()<<"  width: "<<(towardsBoxes[counter]).getWidth()<<"  height: "<<(towardsBoxes[counter]).getHeight()<<endl;

        counter++;
    }
}

void Truck :: Unload(int numBox)
{
    int counter = 0;
    if(towardsBoxes!= 0)        //if pointer is null the truck haven't loaded any boxes so no unloading
    {
        cout<<"UNLOAD DIMENSIONS"<<endl;
        while(counter != numBox)
        {
            cout<<"dimensions of the box are:  length: "<<(towardsBoxes[counter]).getLength()<<"  width: "<<(towardsBoxes[counter]).getWidth()<<"  height: "<<(towardsBoxes[counter]).getHeight()<<endl;
            counter++;
        }
        delete[] towardsBoxes;        //deallocating the memory upon unloading of the boxes
    }

}

bool Truck :: Cost ()
{
    float moneyOnpetrol = (50-petrol)*2.73;         //money to be spent on petrol
    float moneyLeft = money - moneyOnpetrol;        //money left after spending on petrol
    money = moneyLeft;

    float mileagePetrol = (60/fullMileage)+(60/emptyMileage); //petrol spent on journey = petrol used when loaded + petrol used when unloaded
    float petrolLeft = 50-mileagePetrol;        //petrol left after the journey
    petrol = petrolLeft;

    if((moneyLeft>=0) && (mileagePetrol<=50))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Truck::setDriver(char arr[])
{
    int i;
    for(i = 0; arr[i]; i++)
    {
        driver[i] = arr[i];
    }
    driver[i] = '\0';

}

void  Truck :: setPetrol(float x)
{
    petrol = x;
}

void  Truck :: setMoney(float x)
{
    money = x;
}

void  Truck :: setFullMileage(float x)
{
    fullMileage = x;
}

void  Truck :: setEmptyMileage(float x)
{
    emptyMileage = x;
}


float Truck ::  getPetrol()
{
    return petrol;
}

float Truck ::  getMoney()
{
    return money;
}

float Truck ::  getFullMileage()
{
    return fullMileage;
}

float Truck ::  getEmptyMileage()
{
    return emptyMileage;
}

char* Truck::getDriver()
{
    return driver;
}
