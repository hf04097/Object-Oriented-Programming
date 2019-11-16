#include <iostream>
#include "struct.h"

using namespace std;

Stack :: Stack()
{
    head = 0;
}

void Stack :: Push(int val)
{
    if (head == 0)
    {
        head = new Node;
        head -> data = val;
        head -> next = 0;
    }

    else
    {
        Node* temp = head;
        head = new Node;
        head -> data = val;
        head -> next = temp;
    }
}
int Stack :: Pop ()
{
    int val = -1;
    if( head != NULL )
    {
        Node * temp = head ;
        head = head -> next ;
        val = temp -> data ;
        delete temp ;
        temp = NULL ;
    }
    return val ;
}

bool Stack :: isEmpty()
{
    if (head == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Stack :: Top()
{
    return head -> data;
}

int Stack :: Bottom()
{
    while(head->next != 0)
    {
        head = head -> next;
    }
    return head ->data;
}


