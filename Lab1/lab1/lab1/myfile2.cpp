// Q1. The main function displays the option to calculate disk, cylinder or exit.

//Q2. 
//Note: I modified the annex to be slighty more polite
#include <iostream>
#include <cmath>
#include "myfile2.h"  
using namespace std;

double surface(double radius) {
    return M_PI *radius*radius;
}

// cylinder
double volume(double radius, double height) {
    return M_PI *radius*radius* height;
}

int main() {
    int choice;
    double radius, height;

    static int surfaceCount=0, volumeCount=0;

    do {
        cout <<" 𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽\n";

        cout << "What would you like to do?\n";
        cout << "Calculate the area of a disk from a radius (Press 1)\n";
        cout << "Calculate the volume of a cylinder from a radius and a height (Press 2)\n";
        cout << "Exit the program (Press 3)\n";
        cout << "Please enter your choice? ";

        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Surface calculation\n";
                cout << "Please enter the radius? ";
                cin >> radius;
                cout << "Boom! The surface is: " << surface(radius) << endl;
                surfaceCount++;

                break;

            case 2:
                cout << "Volume calculation\n";
                cout << "Please enter the radius: ";
                cin >> radius;
                cout << "Please enter the height: ";
                cin >> height;
                cout << "Tada! The volume is: " << volume(radius, height) << endl;
                volumeCount++;
                break;

            case 3:
                cout << "Exit the program\n";
                cout << "Volume function has been executed " << volumeCount << " times\n";
                cout << "Surface function has been executed " << surfaceCount << " times\n";
                break;
            default:
                cout << "Sorry! Invalid choice, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
