#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
using namespace std;

class Sec
{
    friend ostream& operator <<(ostream&, const Sec&);
public:
    Sec(){}
    Sec(double lan, double math, double eng):language(lan),math(math),english(eng){}
    double language;
    double math;
    double english;
    double average;
};

class Student
{
    friend class StuMgr;
    friend ostream& operator <<(ostream&, const Student&);
    friend istream& operator >>(istream&, Student&);
public:
    Student(){}
    Student(string, int, long);
    Student(string, int, long, double, double, double);

    void init(string, int, long, double, double, double);
    void setName(string name){name_ = name;}
    void setAge(int age){age_ = age;}
    void setNum(long num){num_ = num;}
    void setLan(double lan){score.language = lan;}
    void setMath(double math){score.math = math;}
    void setEng(double eng){score.english = eng;}
    void setScore(double, double, double);


    string getName() const {return name_;}
    int getAge() const {return age_;}
    long getNum() const {return num_;}
	double getLan() const{return score.language;}
	double getMath() const{return score.math;}
	double getEng() const{return score.english;}
    Sec getScore() const {return score;}

    double getAverage();
private:
    string name_;
    int age_;
    long num_;
    Sec score;
};
#endif
