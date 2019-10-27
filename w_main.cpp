#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Student.h"
#include "StuMgr.h"
#include "Menu.h"

using namespace std;

void test01()
{
    Student stu("Valerio", 24, 20141004270);
    stu.setScore(80,80,80);
    cout << stu << endl;
    /* cout << stu.getScore() << endl; */
}

void test02()
{
    Student stu;
    cin >> stu;
    cout << stu << endl;
}

void test03()
{
    Student stu;
    ifstream in("data.txt",ios::in);
    while(in >> stu)
    {
        cout << stu << endl;
    }

}

void test04()
{
    StuMgr* mgr = StuMgr::getInstance();
    Student stu("YuanYuan", 24, 004);
    stu.setScore(100,100,100);
    char name[20] = "data.txt";

    mgr->init(name);
    mgr->showData();
    cout << "===============================================" << endl;
    mgr->addStu(stu);
    mgr->showData();
    
}

void test05()
{
    Student stu("YuanYuan", 24, 004);
    stu.setScore(100,100,100);
    char name[20] = "data.txt";
    Menu menu;
    menu.welcome();
}

int main()
{
    /* test01(); */
    /* test02(); */
    /* test03(); */
    /* test04(); */
    test05();
    return 0;
}
