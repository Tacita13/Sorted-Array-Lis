//Specification/Implementation file
//******************************************************************
//
//   Programador : Isamar López Rodríguez CCOM 3034 Sección 0U1
//   Num. Est.   : 801-08-3174            Primer Semestre 2016-2017
//   Asignación 4                         Prof. R. J. Colorado
//   Archivo     : SAList.h               Fecha : 27/09/16
//
//******************************************************************
//    Propósito :This file contains the SAList class declaration
//               with its private data member and public member
//               functions to manage a sorted list.
//
//******************************************************************

#include "UAList.h"

#ifndef SALIST_H
#define SALIST_H

class SAList : public UAList{
   public:

    //constructor
    SAList(int = 100);

    //redefined functions
    int search(int) const;
    void insert(int);
    void remove(int);

};

//Implementation

//constructor
SAList::SAList(int ms) : UAList(ms){}

//redefined functions
int SAList::search(int item) const{

    int position = -1;
    bool found = false;

    int first = 0;
    int last = length - 1;
    int middle;

    while(first <= last && !found){

        middle = (first + last)/2;
        if(item == list[middle]){
            found = true;
            position = middle;
        }
        else if(item < list[middle]){
            last = middle -1;
        }
        else{
            first = middle +1;
        }
    }
    return position;
}
void SAList::insert(int item)
{
    if (UAList::isFull())
        cout << "List is full, cannot add '" << item << "'\n";
    else if (search(item) != -1)
        cout << "Item already in list.\n";
    else
    {

        int location = 0;
        while (location < length && item > list[location])
        {
            location++;
        }

        for (int i = length; i > location; i--)
            list[i] = list[i - 1];

        //insert
        list[location] = item;

        //adjust length after insertion
        length++;
    }
}


void SAList::remove(int item){
    if (UAList::isEmpty())
            cout << "Empty List, cannot remove component.";
        else
        {
            int location = search(item);
            if (location == -1)
                cout << item << " is not found in list.";

            else //proceed with remotion
            {
                for (int i = location + 1; i < length; i++)
                    list[i - 1] = list[i];

                //ajustar length
                length--;
            }
        }

}

#endif // SALIST_H
