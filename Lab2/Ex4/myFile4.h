/*myFile4.h : Ex4 a2 CSI2372A*/

#include <iostream>
#include <cstdlib>       // for exit() (cross-platform)
#include <string.h>      // for strcmp, strcpy
#include <limits.h>      // for INT_MAX
using namespace std;

const int size_ch = 20;  // maximum size of a string
const int nb_ch = 5;     // Number of strings processed

// Function declarations
void display(char* tab[], int const& nbre);     // displays strings
char menu(void);                                // displays a menu and returns the choice
void replace(char* tab[], int const& nbre, int const& size); // replaces one string by another
void sort(char* tab[], int const& nbre);        // insertion sort
