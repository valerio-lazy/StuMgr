#include "Student.h"

ostream& operator <<(ostream& os, const Sec& sec)
{
    os << "Score: "
		<< sec.language << "(L) "
        << sec.math << "(M) "
        << sec.english << "(E)";
    return os;
}

ostream& operator <<(ostream& os, const Student& stu ) 
{
    os  << "Name: " << stu.getName()
        << "\tAge: " << stu.getAge()
        << "\tNum: " << stu.getNum()
        << "\t" << stu.getScore();
    return os;
}

istream& operator >>(istream& is, Student& stu)
{
    string name;
    int age;
    long num;
    double lan, math, eng;
    is >> name >> age >> num >> lan >> math >> eng;
    stu.init(name, age, num, lan, math, eng);
    return is;
}

Student::Student(string name, int age, long num)
{
    setName(name);
    setAge(age);
    setNum(num);
}

Student::Student(string name, int age, long num,
                 double lan, double math, double eng)
{
    setName(name);
    setAge(age);
    setNum(num);
    setScore(lan, math, eng);
}
void Student::init(string name, int age, long num,
                   double lan, double math, double eng)
{
    name_ = name;
    age_ = age;
    num_ = num;
    setScore(lan, math, eng);
}

void Student::setScore(double language, double math, double english)
{
    setLan(language);
    setMath(math);
    setEng(english);
    score.average = (language+math+english)/3;
}

double Student::getAverage()
{
    score.average = (score.language + score.math + score.english)/3;
    return score.average;
}
