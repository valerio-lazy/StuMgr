#include "Menu.h"
using namespace std;

static bool flag = false;
int op = 0;
char c;
char datafile[20] = "default.data";

int transOp(char& c)
{
    if(int(c) > 57 || int(c) < 48)
        throw -1;
    else
        return atoi(&c);
}

Menu::Menu()
{
    mgr = StuMgr::getInstance();
    char name[20] = "valerio";
    char password[20] = "min-shuai-";
    User user(name,password);
    users.push_back(user);

    mgr->init(datafile);
}

void Menu::login()
{
    char name[20], pwd[20];
    vector<User>::iterator it = users.begin();
    cout << "===================================" << endl
        << "UserName: ";
    cin >> name;
    cout << "Password: ";
    cin >> pwd;
    User user(name, pwd);
    if(*it == user){
        cout << "login successfully" << endl;
        flag = true;
    }
    else{
        cout << "login failed" << endl;
    }
}

void Menu::welcome()
{
    system("clear");
    cout << "\t\t==============================\t\t" << endl
        << "Welcome To the Manager Of Student Info" << endl
        << "1.Login 0.Exit" << endl
        << "=====Input the number: ";
    while(1){
        cin >> c;
        cin.ignore(INT_MAX, '\n');
        try{
            op = transOp(c);
        }catch(int){
            cout << "=====Please input correct option: ";
            continue;
        }

        switch(op){
        case BACK: cout << "Bye ~~~" << endl;exit(0);
        case Login: login();break;
        default:
                    /* cout << "Please choose correct option: "; */
                    cout << "=====Please input correct option: ";
                    continue;
        }

        if(flag){
            menu();
        }
    }
}


void Menu::menu()
{
    system("clear");
    cout << "\t\t==============================\t\t" << endl
        << "\t1.Load\t2.View\t3.Add\t4.Del\t5.Query\t0.Back" << endl;
    cout << "=====Choose the Num: ";
    while(1){
        cin >> c;
        cin.ignore(INT_MAX, '\n');
        try{
            op = transOp(c);
        }catch(int){
            cout << "=====Please input correct option: ";
            continue;
        }

        switch(op)
        {
        case BACK:      welcome(); break;
        case LOAD:      load(); break;
        case VIEW:      view(); break;
        case ADD:       add();  break;
        case DELETE:    del();  break;
        case QUERY:     query();    break;
        default:
                        /* cout << "Incorrect option!!!" << endl; */
                        cout << "=====Please input correct option: ";
                        continue;
        }

        cout << "go back with any key";
        cin >> c;
    }
}

void Menu::load()
{
    string name = "";
    system("ls *.data");

    //输入并判断要载入的文件是否存在
    while(true){
        cout << "请输入要载入的文件名:";
        cin >> name;

        string::size_type pos = name.rfind(".");
        if(pos == string::npos){
            cout << "请输入完整的文件名" << endl;
            continue;
        }
        if(strcmp(name.substr(pos+1).c_str(), "data") == 0
           && access(name.c_str(), F_OK) == 0)
            break;
        cout << "输入的文件不存在" << endl;
    }

    //文件存在，载入
    memset(datafile,0, sizeof(datafile));
    strcpy(datafile, name.c_str());

    mgr->init(datafile);    //重新载入新数据文本
}

void Menu::view()
{
    mgr->showData();

}

void Menu::add()
{
    string name;
    int age;
    long num;
    double lan, math, eng;

    char c;
    do{
        cout << "Please input the information: " << endl;
        cout << "Name: ";       cin >> name;
        cout << "Age: ";        cin >> age;
        cout << "Num: ";        cin >> num;
        cout << "Language: ";   cin >> lan;
        cout << "Math: ";       cin >> math;
        cout << "English ";     cin >> eng;
        Student stu(name, age, num, lan, math, eng);

        cout << "Are You Sure?(input 'y' to save): ";
        cin >> c;
        if(c == 'y'){
            mgr->addStu(stu);
        }
        cout << "Continue adding?(input '0' to back): ";
        cin >> op;
        cin.ignore(INT_MAX, '\n');
    }while(op);

    mgr->saveData();
}

void Menu::del()
{
    long dit;
    mgr->showData();
    cout << "input the num you want: ";
    cin >> dit;
    Student* stu = mgr->queryStu(dit);
    if(stu == nullptr){
        return ;
    }

    mgr->delStu(*stu);
    cout << "delete success!!!" << endl;

    mgr->saveData();
}

void Menu::query()
{
    long dit;
    cout << "input the num you want: ";
    cin >> dit;
    Student* stu = mgr->queryStu(dit);
    if( stu == nullptr ){
        return;
    }

    cout << *stu << endl;
}
