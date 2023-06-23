// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#include "Student.h"
#include <ostream>
#include <iomanip>
#include <cstring>

Student::Student() {}
Student::Student(int i_no, char *i_name, bool i_gender, int i_age, char *i_major, int i_cls, double i_score)
{
    no = i_no, strcpy(name, i_name), is_male = i_gender, age = i_age, strcpy(major, i_major), cls = i_cls, score = i_score;
}

void Student::setno(int i_no) { no = i_no; }
void Student::setname(char *i_name) { strcpy(name, i_name); }
void Student::setgender(bool i_gender) { is_male = i_gender; }
void Student::setage(int i_age) { age = i_age; }
void Student::setmajor(char *i_major) { strcpy(major, i_major); }
void Student::setcls(int i_cls) { cls = i_cls; }
void Student::setscore(double i_score) { score = i_score; }

int Student::getno() const { return no; }
char *Student::getname() const
{
    char *ret = new char[MAXN];
    strcpy(ret, name);
    return ret;
}
bool Student::getgender() const { return is_male; }
int Student::getage() const { return age; }
char *Student::getmajor() const
{
    char *ret = new char[MAXN];
    strcpy(ret, major);
    return ret;
}
int Student::getcls() const { return cls; }
double Student::getscore() const { return score; }

std::ostream &operator<<(std::ostream &out, const Student &s)
{
    out << std::setw(4) << s.no << std::setw(16) << s.name;
    if (s.is_male)
        out << "    male";
    else
        out << "  female";
    out << std::setw(5) << s.age << std::setw(16) << s.major << std::setw(7) << s.cls << std::setw(7) << s.score;
    return out;
}