#ifndef _STU_MANAGER_H_
#define _STU_MANAGER_H_

#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include "Student.h"
using namespace std;

class Student;

class StuMgr
{
public:
    static StuMgr* getInstance(){return manager;}

    void init(char*);   //初始化系统，载入信息
    void showData();    //列出当前全部信息
    void addStu(const Student&);    //添加学生信息
    void delStu(const Student&);    //删除学生信息
    void saveData();            //保存数据到文件
    void cleanData();       //清楚当前信息
    Student* queryStu(long);     //按学号查找学生

    void bandFile(char*);   //绑定数据文件
    
private:
    StuMgr(){}
    
    static StuMgr* manager;
    vector<Student> data;
    char datafile[20];
};

/* StuMgr* StuMgr::manager = new StuMgr; */

#endif
