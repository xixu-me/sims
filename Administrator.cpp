// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#include "Administrator.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cstring>

int Administrator::maxno = 0;

Student Administrator::getstu(int i)
{
    return stu[i];
}

int Administrator::getmaxno()
{
    maxno++;
    return maxno;
}

int Administrator::add(char *i_name, bool i_gender, int i_age, char *i_major, int i_cls, double i_score)
{
    Student temp(getmaxno(), i_name, i_gender, i_age, i_major, i_cls, i_score);
    stu.push_back(temp);
    return maxno;
}

int Administrator::find(int i_no)
{
    for (int i = 0; i < stu.size(); i++)
        if (stu[i].getno() == i_no)
            return i;
    return -1;
}

int Administrator::find(char *i_name)
{
    for (int i = 0; i < stu.size(); i++)
        if (strcmp(stu[i].getname(), i_name) == 0)
            return i;
    return -1;
}

std::vector<int> Administrator::findbycls(char *i_major, int i_cls)
{
    std::vector<int> tmp;
    for (int i = 0; i < stu.size(); i++)
        if (strcmp(stu[i].getmajor(), i_major) == 0 && stu[i].getcls() == i_cls)
            tmp.push_back(i);
    return tmp;
}

bool Administrator::erase(int i_no)
{
    int i = find(i_no);
    if (i == -1)
        return false;
    else
    {
        stu.erase(stu.begin() + i);
        return true;
    }
}

bool Administrator::erase(char *i_name)
{
    int i = find(i_name);
    if (i == -1)
        return false;
    else
    {
        stu.erase(stu.begin() + i);
        return true;
    }
}

bool Administrator::edit(int i_no, char *i_name, bool i_gender, int i_age, char *i_major, int i_cls, double i_score)
{
    int i = find(i_no);
    if (i == -1)
        return false;
    else
    {
        stu[i].setname(i_name);
        stu[i].setgender(i_gender);
        stu[i].setage(i_age);
        stu[i].setmajor(i_major);
        stu[i].setcls(i_cls);
        stu[i].setscore(i_score);
        return true;
    }
}

void Administrator::display()
{
    if (!stu.empty())
    {
        std::cout << " No.            Name  Gender  Age           Major  Class  Score" << std::endl;
        for (Student s : stu)
        {
            std::cout << s << std::endl;
        }
    }
    else
        std::cout << "No information exists!" << std::endl;
}

struct ascende
{
    bool operator()(const Student &__x, const Student &__y) const
    {
        return __x.getscore() - __y.getscore() < 0;
    }
};

struct descende
{
    bool operator()(const Student &__x, const Student &__y) const
    {
        return __x.getscore() - __y.getscore() > 0;
    }
};

void Administrator::sequence(bool ascending)
{
    if (ascending)
        sort(stu.begin(), stu.end(), ascende());
    else
        sort(stu.begin(), stu.end(), descende());
}

double Administrator::average()
{
    double tmp = 0.0;
    for (Student s : stu)
        tmp += s.getscore();
    tmp /= stu.size();
    return tmp;
}

void Administrator::loadfile()
{
    std::ifstream in("Student_Information.txt");
    if (!in)
    {
        std::cout << "Unable to open the file \"Student_Information.txt\"!" << std::endl;
        return;
    }
    Student s;
    int no;
    char name[MAXN];
    char gender[MAXN];
    int age;
    char major[MAXN];
    int cls;
    double score;
    while (in >> no >> std::setw(MAXN) >> name >> std::setw(MAXN) >> gender >> age >> std::setw(MAXN) >> major >> cls >> score)
    {
        s.setno(no);
        s.setname(name);
        if (strcmp(gender, "male") == 0)
            s.setgender(true);
        else if (strcmp(gender, "female") == 0)
            s.setgender(false);
        s.setage(age);
        s.setmajor(major);
        s.setcls(cls);
        s.setscore(score);
        stu.push_back(s);
    };
    in.close();
    for (Student s : stu)
        if (s.getno() > maxno)
            maxno = s.getno();
}

void Administrator::writefile()
{
    std::ofstream out("Student_Information.txt");
    for (Student s : stu)
    {
        out << std::setw(4) << s.getno() << std::setw(16) << s.getname();
        if (s.getgender())
            out << "    male";
        else
            out << "  female";
        out << std::setw(5) << s.getage() << std::setw(16) << s.getmajor() << std::setw(7) << s.getcls() << std::setw(7) << s.getscore() << std::endl;
    }
    out.close();
}