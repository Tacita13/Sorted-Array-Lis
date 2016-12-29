//Client file
//******************************************************************
//
//   Programador : Isamar López Rodríguez CCOM 3034 Sección 0U1
//   Num. Est.   : 801-08-3174            Primer Semestre 2016-2017
//   Asignación 4                         Prof. R. J. Colorado
//   Archivo     : menu.cpp             Fecha : 27/09/16
//
//******************************************************************
//    Propósito :This file holds the main that finally displays the values
//               of the class SAList that inherits from UAList.
//
//******************************************************************

#include <iostream>
#include "SAList.h"
#include<iostream>

using namespace std;

int main(){
    int choice, index, max;
    int element=0;

    cout<<  "Choose the max size of your list:\n";
    cin >> max;
    SAList list(max);

    do{

    // Display the menu and get a choice.
    cout << "What do you wish to do with your list?\n\n"
    << "1. Add an element\n"
    << "2. Search for an element\n"
    << "3. Remove an element\n"
    << "4. Display list\n"
    << "5. List capacity\n"
    << "6. Length of the list\n"
    << "7. Clear list\n"
    << "8. Quit the Program\n\n"
    << "Enter your choice: ";
    cin >> choice;

    switch (choice){
    case 1: cout << "Which integer would you like to insert?\n";
             cin >> element;
             list.insert(element);
    break;
    case 2: cout << "Which integer would you like to search?\n";
            cin >> element;
            index=list.search(element);
            if(index == -1)
                cout<< "Item not in list.\n";
            else
                cout<<"Item is in the position:"<< index<<endl;
    break;
    case 3: cout << "Which integer would you like to remove?\n";
            cin >> element;
            list.remove(element);
    break;
    case 4: list.print();
    break;
    case 5: cout << "List capacity: " << list.listSize()<<endl;
    break;
    case 6: cout << "Length of the list: " << list.listLength()<<endl;
    break;
    case 7: cout<< "List is now empty.\n";
            list.clear();
    break;
    case 8: cout << "Program ending.\n";
    break;
    default: cout << "The valid choices are 1 through 8. Run the\n"
                  << "program again and select one of those.\n";
    }

    }while(choice !=8);

    return 0;
}
