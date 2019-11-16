#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

const double PI = 3.14159265;
int amplitude=50;

void GraphMaker()
{
    ofstream myfile;
    myfile.open ("sineGraph.txt");

    for (int i=0; i<=360; i++)
    {
        int sineSpace=amplitude*sin(i*(PI/180)); // value of sine(after converting into radians) at x-coordinates
        int counter=0;
        while(counter<(amplitude)+(sineSpace)) // at y-axis it will sum of amplitude and sine value
        {
            myfile<<" ";
            counter++;
        }

        myfile<<"*";
        myfile<<"\n";

    }
}



int combine(int part1, int part2)  // This function will combine two integers
 {
   int times = 1;
   if (part2 == 0)
    times *= 10;
   while (times <= part2)
      times *= 10;

   return part1*times + part2;
}

int NumberOfOperator(char charExp[])  // To know the number or operator in an expression
{
    int counter=0;
    for( int expIterator=0; charExp[expIterator] != '\0'; expIterator++ )
    {
     if ((int(charExp[expIterator]) > 41) && (int(charExp[expIterator]) < 48)) // Iterating over the expression and seeing how many operators are there
        {
            counter++;
        }
    }
    return counter;
}

void SeperateChar(char charExp[])
{
    char arrChar[64];
    int charIterator=0;
    int counter=NumberOfOperator(charExp);

    for( int expIterator=0; charExp[expIterator] != '\0'; expIterator++ )
    {
        if((int(charExp[expIterator])>41) && (int(charExp[expIterator])<48))
                {
                    arrChar[charIterator]=charExp[expIterator];  // appending characters in char array
                    charIterator++;
                }
    }

    for(int intIterator=0 ; intIterator<counter;intIterator++)
    {
        cout<<arrChar[intIterator]<<" ";  // printing character array
    }
}

int SeperateInt(char charExp[])
{

    int arrInteger[64];
    int intIterator = 0;
    int part1;

    for( int expIterator=0; charExp[expIterator] != '\0'; expIterator++ )
    {
        part1 = charExp[expIterator] - 48;  // changing the char into int

        while(((int (charExp[expIterator+1]) >= 41 ) || (int (charExp[expIterator+1]) <= 48)) && (charExp[expIterator] != '\0')&& (charExp[expIterator] - 48 >=0 && charExp[expIterator] - 48 <= 9)) // ord of operators in between 42 and 47
        {
            if ( charExp[expIterator+1] == '\0')  // last element of char array is always '\0'

            {
                arrInteger[intIterator] = part1;  // append combined integer in integer array
                break;
            }

            else
            {
                int partCombine = combine((part1),(charExp[expIterator+1] - 48)) ; //combining integers
                part1=partCombine;
                expIterator++;
            }

            if((int(charExp[expIterator+1])<41) || (int(charExp[expIterator+1])<48))
            {
                arrInteger[intIterator]=part1; // appending combined integer in integer array
                intIterator++;
            }
        }




    }

    int counter=NumberOfOperator(charExp);
    cout <<counter <<endl;
    for(int intIterator=0 ; intIterator<counter+1;intIterator++)
    {
        cout<<arrInteger[intIterator]<<" ";  // printing integer array
    }

}

int main()

{   char charExp[]="24*356+489*5/45*54";
    NumberOfOperator(charExp);
    SeperateInt(charExp);
    cout<<endl;
    SeperateChar(charExp);
    GraphMaker();
    return 0;
}
