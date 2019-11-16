#include <iostream>
#include "node.h"

using namespace std;

class Stack
{
    private :
            Node * head ;
    public :
        Stack ();
        void Push(int);
        int Pop();
        bool isEmpty();
        int Top();
        int Bottom();
};
