#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "truck.h"
#include "box.h"
#include <time.h>
#include <fstream>

using namespace std;

int LineCounter();
int HowManyTrucks();    // to calculate the number of trucks who will make the journey

int HowManyTrucks()
{
    int noOfTruck = LineCounter()/5;
    int travelTruck = 0;
    Truck ural;
    FILE* filePointer;
    char buff[32];

    filePointer = fopen("Drivers.txt", "r");

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    for(int i=0; i<noOfTruck; i++)
    {
        fgets(buff, 32, (FILE*)filePointer);
        ural.setDriver(buff);


        fgets(buff, 32, (FILE*)filePointer);
        ural.setPetrol(atof(buff));

        fgets(buff, 32, (FILE*)filePointer);
        ural.setMoney(atof(buff));

        fgets(buff, 32, (FILE*)filePointer);
        ural.setFullMileage(atof(buff));

        fgets(buff, 32, (FILE*)filePointer);
        ural.setEmptyMileage(atof(buff));

        if (ural.Cost()==true)  //if petrol and money for truck are sufficient incrementing the counter
        {
            travelTruck++;
        }
    }
    fclose(filePointer);

    return travelTruck;

}

int LineCounter()
{
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");         //Opening file as read only

    if (filePointer == NULL)                    //If file is not found
    {
        perror ("Error opening file");          //Show Error
        return 0;
    }

    int counter = 0;                            //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}

int main()
{
    srand (time(NULL));     //for random
    int numBox = (rand()%8)+12;     //random number of boxes
    int noOfTruck = HowManyTrucks();
    Truck* towardsTruck1 = new Truck[noOfTruck];            // pointer pointing towards array of trucks

    cout<<"Number of trucks making the journey are: " <<noOfTruck<<endl;
    cout<<endl;


    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    for(int i=0; i<noOfTruck;) //for number of trucks that will be ale to make the journey
    {
        fgets(buff, 32, (FILE*)filePointer);
        towardsTruck1[i].setDriver(buff); //Reading the name of the driver directly

        fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
        towardsTruck1[i].setPetrol(atof(buff));                  //Converting the string to integer

        fgets(buff, 32, (FILE*)filePointer);
        towardsTruck1[i].setMoney(atof(buff));

        fgets(buff, 32, (FILE*)filePointer);
        towardsTruck1[i].setFullMileage(atof(buff));

        fgets(buff, 32, (FILE*)filePointer);
        towardsTruck1[i].setEmptyMileage(atof(buff));

        if (towardsTruck1[i].Cost()==true)
        {
            i++; //if petrol and money for truck are sufficient iterate over the array
        }
    }

    fclose(filePointer); //Closing file
    ofstream myfile;
    myfile.open("Trip.txt");

    for(int i=0; i<noOfTruck; i++)      //for all trucks
    {
        cout<<"Truck number "<<i+1<<endl;
        cout<<endl;
        cout << "Truck driver is: " << towardsTruck1[i].getDriver();
        cout<<endl;

        towardsTruck1[i].Load(numBox);      // loading boxes for trucks
        cout<<endl;

        myfile<<towardsTruck1[i].getDriver();             //write down details of the truck in the trip.txt
        myfile<<towardsTruck1[i].getPetrol()<<endl;
        myfile<<towardsTruck1[i].getMoney()<<endl<<endl;

    }
    myfile.close();

    for(int i=0; i<noOfTruck; i++)
    {
        cout<<endl;
        cout << "Truck driver is: " << towardsTruck1[i].getDriver();
        cout<<endl;

        towardsTruck1[i].Unload(numBox);     //after reaching the destination unloading the truck


        cout<<endl;
    }

    delete[] towardsTruck1; // deallocating memory



    return 0;
}
