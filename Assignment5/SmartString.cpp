#include "SmartString.h"
#include <iostream>

using namespace std;

SmartString::SmartString()
{
    length = 0;
    text = 0;
}

SmartString::~SmartString()
{
    delete[] text;
}

int SmartString::CalculateTextLength(const char* arr)
{
    int i=0;
    if (arr != 0)
    {
        for (i; arr[i]!='\0';i++)    //iterating over the array to know text's length
        {

        }
    }

    return i;
}

void SmartString::CopyText( char* dest, const char* src)
{
    int srcLength = CalculateTextLength(src);
    text = new char[srcLength+1];
    int i=0;

    for(i;i<srcLength;i++)  //copying source text to destination text
    {
        text[i]=src[i];
    }
    text[i]='\0';

}

SmartString::SmartString(const char* arr)
{
    length = CalculateTextLength(arr);
    CopyText(text,arr); // arrays text will be copied in the dynamic array
}

SmartString::SmartString(const SmartString& val)
{
    length = val.length;
    CopyText(text,val.text);    //object's text will be copied in the dynamic array

}

void SmartString::Join(const SmartString& val)
{
    Join(val.text);  //giving smartstrings object as parameter.

}

void SmartString::Join(const char* arr)
{
    int arrLength=CalculateTextLength(arr);

    char* aText = text;
    int fullLength = length+arrLength+1; //length of the new text (+1 for '\0')

    text= new char[fullLength];
    int i=0;
    if (aText!=0)
    {
        for(i;i<length;i++)
        {
            text[i]= aText[i]; //copying aText;
        }
    }

    int j=0;
    if (arr!=0)
    {
        for(i;i<fullLength;i++)
        {
            text[i]=arr[j];     //copying from array
            j++;
        }
    }

    text[i]='\0';
    length=length+arrLength;
    delete[] aText;
}

int SmartString::Length()
{
    return length;
}

void SmartString ::Show()
{
    if(text!=0)
    {
        for(int i=0; i<length+1;i++)
        {
            cout<<text[i];
        }
    }

    cout<<endl;
}

SmartString SmartString::operator+(const SmartString& val)
{
    SmartString newVal;
    newVal.Join(text);
    newVal.Join(val.text);
    return newVal;

}

SmartString SmartString::operator+(const char* arr)
{
    SmartString newVal;
    newVal.Join(text);
    newVal.Join(arr);
    return newVal;
}

SmartString& SmartString::operator=(const SmartString& val)
{
  operator=(val.text);


}

SmartString& SmartString::operator=(const char* arr)
{
    CopyText(text,arr); //copying array's text to assign to text
    length=CalculateTextLength(arr);

}

SmartString& SmartString::operator += (const SmartString& val)
{
    this->Join(val);
}

SmartString& SmartString::operator += (const char* arr)
{
    this->Join(arr);
}

bool SmartString::operator==(const SmartString& val )
{
    operator==(val.text);
}

bool SmartString::operator==(const char* arr )
{
    if(length!=CalculateTextLength(arr))    // if lengths are not equal then false
    {
        return false;
    }
     if (CalculateTextLength(arr)==length)
     {
         for(int i=0; i<length;i++)
         {
             if(text[i]!=arr[i])    //comparing each index
             {
                 return false;
             }

         }
     }
    return true;
}
