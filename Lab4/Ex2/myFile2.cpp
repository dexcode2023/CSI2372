/*Ex2 devoir4 CSI2772A*/


#include <iostream> 
#include "myFile2.h"
using namespace std;

SetInt::SetInt(int list[], int size) : size(size){
    elem = new int[size];
    for(int i = 0; i<size;i++){
        elem[i] = list[i];
    }

}

SetInt::~SetInt(){
    delete[] elem;
}

SetInt::SetInt(const SetInt& t){
    size = t.size;
    if(t.elem == nullptr){
        elem = nullptr;
        return;
    }
    elem = new int[size];
    for(int i = 0; i< size; i++){
        elem[i] = t.elem[i];
    }
}

bool SetInt::contains(int t){
    if(elem == nullptr){
        return false;
    }
    for(int i = 0; i<size; i++){
        if(t ==*(elem + i)){
            return true;;

        }
    }
    return false;
}

void SetInt::add(int t){
    if(contains(t)){
        cout << "The element already exists in the set." << endl;
        return;
    }
    
    int* res = new int[size++];
    for(int i = 0; i < size-1; i++){
        res[i] = elem[i];
    }
    res[size-1] = t;
    delete[] elem;
    elem = res;
}

void SetInt::remove(int t){
    if(!contains(t)){
        return;
    }
}



bool SetInt::containsIn(int t, int& el){
    if(elem[el] == t){
        return true;
    }
    return false;
}



int main() {
    SetInt a; 	// object creation
    int* tab;

    while (a.nbElem() < 5)
    {
        cout << "add an int element" << endl;
        int elem;
        cin >> elem;
        a.add(elem);

    }
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "remove 10 " << endl;
    a.remove(10);
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "a contains :" << a.nbElem() << " elements " << endl;
    tab = a.tabElem();
    cout << "The elements of a are :" << endl;
    for (int i =0; i<a.nbElem(); i++)
        cout << tab[i] << endl;

    return 0;
}