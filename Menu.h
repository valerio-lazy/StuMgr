#ifndef _MENU_H_
#define _MENU_H_

#include "StuMgr.h"
#include "User.h"
#include <climits>
#include <unistd.h>
#include <string.h>

#define Login 1

extern int op;
extern char datafile[20];

enum{
    BACK, LOAD, VIEW, ADD, DELETE, QUERY
};

class Menu
{
public:
    Menu();

    //登录操作
    void login();
    

    //菜单选项
    void welcome(); //登录界面
    void menu();    //主界面
    void load();    //选择载入文件
    void view();    //查看数据
    void add();     //添加学生信息
    void del();     //删除学生信息
    void query();   //查询学生信息
public:
    StuMgr* mgr;
    vector<User> users;
};
#endif
