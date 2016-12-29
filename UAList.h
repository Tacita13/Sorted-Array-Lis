//Specification/Implementation file
//******************************************************************
//
//   Programador : Isamar López Rodríguez CCOM 3034 Sección 0U1
//   Num. Est.   : 801-08-3174            Primer Semestre 2016-2017
//   Asignación 4                         Prof. R. J. Colorado
//   Archivo     : UAList.h               Fecha : 27/09/16
//
//******************************************************************
//    Propósito :This file contains the UAList class declaration
//               with its private data member and public member
//               functions to manage a unsorted list.
//
//******************************************************************
#include <iostream>
using namespace std;

#ifndef UALIST_H
#define UALIST_H

class UAList{

protected:
    int maxSize;
    int length;
    int * list;
public:
    //constructor
    UAList(int =100);
    //copy constrcutor
    UAList( const UAList&);
    //Overloaded A operator
    const UAList& operator=(const UAList&);
    //destructor
    ~UAList();
    //
    void copy(const UAList& );
    //Observers
    bool isEmpty() const;
    bool isFull() const;
    int  listSize() const;
    int listLength() const;
    int search(int) const;
    void print() const;
    //Mutators
    void insert(int);
    void remove(int);
    void clear();
};

#endif // UALIST_H

//constructor
UAList::UAList(int s){
    maxSize=(s>1)? s : 100;
    length=0;
    //generar el arreglo
    list = new int[maxSize];

}

void UAList::copy(const UAList& original){

    maxSize =original.maxSize;
    length =original.length;

    //Crear lista
    list= new int[maxSize];

    //Copiar lista de original

    for (int i=0; i <length ; i++){
        list[i]=original.list[i];
    }
}


//copy constructor
//UAList tiene q ser call by reference pq sino cae en un ciclo
UAList::UAList( const UAList& original){

    copy(original);
}

//Overloaded A operator (OAO)
const UAList& UAList:: operator=(const UAList& original){
    //avoid self-assignment
    if(this != &original){     }

    //Devolver la lista original
    delete [] list;

    //Crear lista
    list= new int[maxSize];

    copy(original);


    return *this;
}

//destructor
UAList::~UAList(){
    delete[]list;
    list= NULL ;
}
//Observers
bool UAList::isEmpty() const{
    return length ==0;

}
bool UAList::isFull() const{
     return length ==maxSize;

}
int  UAList::listSize() const{

     return maxSize;
}
int UAList::listLength() const{

     return length;
}
int UAList::search(int item) const{

    //Lineal or sequentioal search

    int position = -1;
    bool found = false;

    for(int i=0; i<length && not found; i++){
        if(item==list[i]){
            position=i;
            found=true;
        }
    }
    return position;
}
void UAList::print() const{
    if(isEmpty()){
        cout<<"Empty List. Cannot display"<<endl;
    }
    else{
        cout<<"The elements in the list are:\n";
        for(int i=0; i<length; i++){
            cout<< (i+1) << ")" << list[i] << endl;

        }
    }

}
//Mutators

void UAList::insert(int item){
    if(isFull()){
        cout<< "List is full, cannot insert.\n";
    }
        else if(search(item) != -1){
            cout<< item << "already in list.\n";
        }
        else{
            //insert item
            list[length]= item;
            length++;
        }

}
void UAList::remove(int item){

    if(isEmpty()){
        cout<< "\n Empty list. Cannot remove.\n";
    }
        else{
            int location = search(item);
            if(location == -1){
                cout<<"Item not in list.\n";
            }
            else{
                list[location] = list[length-1];
                length--;
            }
        }
    }

void UAList::clear(){

    length =0;
}
