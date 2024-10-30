/*myFile1b.h, Ex1 a4 CSI2372A*/
#ifndef MYFILE1B_H
#define MYFILE1B_H

#include <iostream>
using namespace std;
#include "myFile1a.h"

class Student {
    int numID;             
    int nbCourses;            
    int maxCourses;           
    int* List_grades;         
    Course** List_courses;     

public:
    Student(int id, int maxCourses) : numID(id), maxCourses(maxCourses), nbCourses(0) {
        List_grades=new int[maxCourses];    
        List_courses=new Course*[maxCourses];  
    }
    ~Student() {
        delete[] List_grades;                    
        delete[] List_courses;            
    }
    double average() {
        if (nbCourses == 0) return 0.0;        
        double total = 0.0;
        for (int i = 0; i < nbCourses; i++) {
            total += List_grades[i];
        }
        return total / nbCourses;
    }

    int totalHours() {
        int total = 0;
        for (int i = 0; i < nbCourses; i++) {
            total += List_courses[i]->getHours();
        }
        return total;
    }


    bool addCourse(Course* course, int grade) {
	    
        if (nbCourses < maxCourses) {
            List_courses[nbCourses]=course;    
            List_grades[nbCourses]=grade;      
            nbCourses++;                           
            return true;
        }
        return false;  
    }
};

#endif

