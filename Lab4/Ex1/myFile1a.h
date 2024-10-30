/*myFile1a, Ex1 a4 CSI2372A*/

#ifndef MYFILE1A_H
#define MYFILE1A_H

#include <iostream>
using namespace std;

class Course {
    int num;    
    int hours;  
public:
    Course(int courseNum, int courseHours) : num(courseNum), hours(courseHours) {}
    int getNum() {
        return num;
    }
    int getHours() {
        return hours;
    }
};

#endif


