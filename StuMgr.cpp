#include "StuMgr.h"

StuMgr* StuMgr::manager = new StuMgr;

void StuMgr::init(char* filename)
{
    cleanData();
    bandFile(filename);
    ifstream file(filename, ios::in);
    
    Student stu;
    while(file >> stu)
    {
        data.push_back(stu);
    }
}

void StuMgr::showData()
{
    for(vector<Student>::iterator it = data.begin();
        it != data.end(); ++it)
    {
        cout << *it << endl;
    }
}

void StuMgr::addStu(const Student& stu)
{
    data.push_back(stu);    
}

void StuMgr::delStu(const Student& stu)
{
    for(vector<Student>::iterator it = data.begin();
        it != data.end(); ++it)
    {
        if(it->getNum() == stu.getNum()){
            data.erase(it);
            break;
        }
    }
}

Student* StuMgr::queryStu(long num)
{
    for(vector<Student>::iterator it = data.begin();
        it != data.end(); ++it){
        if(it->getNum() == num)
            return &*it;
    }
    
    cout << "No matched student";
    return nullptr;
}

void StuMgr::saveData()
{
    
    ofstream outfile(datafile, ios::out);
    
    for(vector<Student>::iterator it = data.begin();
        it != data.end(); ++it){
        outfile << it->getName()
            << "\t" << it->getAge()
            << "\t" << it->getNum()
            << "\t" << it->getLan()
            << "\t" << it->getMath()
            << "\t" << it->getEng() << endl;
    }
}

void StuMgr::cleanData()
{
    data.clear();
}

void StuMgr::bandFile(char* filename)
{
    strcpy(datafile, filename);
}
