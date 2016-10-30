//
// Created by pool_little on 30/10/2016.
//

#ifndef ALGORITHM_CPP_STUDENT_H
#define ALGORITHM_CPP_STUDENT_H
#include <iostream>
#include <string>

using namespace std;
struct Student{
    string name;
    int score;

    /*
     * 对运算符的重载，用于结构体Student之间的比较
     */
    bool operator<(const Student &otherStudent){
        return score < otherStudent.score;
    }

    /*
     * 对输出运算符的重载，用于对结构体Student的输出
     */
    friend ostream& operator<<(ostream &os, const Student &student){
        os<<"Student:"<<student.name<<" "<<student.score<<endl;
        return os;
    }

};

#endif //ALGORITHM_CPP_STUDENT_H
