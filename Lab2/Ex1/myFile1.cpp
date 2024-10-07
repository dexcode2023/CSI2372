#include <iostream>
using namespace std;

int main(void) {
    int tab[10];  
    int* p;       

    for (int i = 0; i < 10; i++) {
        tab[i] = i * i;
    }

    cout << tab[2] << endl;  // Print the value of tab[2] 

    tab[2] = tab[1];         // Set tab[2] to the value of tab[1] 
    cout << tab[2] << endl;  // Print the value of tab[2] 

    tab[2] = *(tab + 1);     // Set tab[2] to the value at tab[1] 
    cout << tab[2] << endl;  // Print the value of tab[2] 

    *(tab + 2) = tab[1];     // Set the value at tab[2] to tab[1] 
    cout << *(tab + 2) << endl;  // Print the value at tab[2] 

    *(tab + 2) = *(tab + 1); // Set tab[2] to the value at tab[1] 
    cout << *(tab + 2) << endl;  // Print the value at tab[2] 

    p=&tab[0];             // Point p to the start of the array
    p=tab + 1;             // Point p to tab[1]
    
    tab[4] = *p;             // Set tab[4] to the value pointed by p 
    cout << tab[4] << endl;  // Print the value of tab[4] 
    
    return 0;
}

