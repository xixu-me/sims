// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef STUDENT_INFORMATION_MANAGEMENT_SYSTEM_STUDENT_H
#define STUDENT_INFORMATION_MANAGEMENT_SYSTEM_STUDENT_H

#include <ostream>

const int MAXN = 20;

class Student
{
private:
    int no;
    char name[MAXN];
    bool is_male;
    int age;
    char major[MAXN];
    int cls;
    double score;

public:
    Student();
    Student(int, char *, bool, int, char *, int, double);
    void setno(int);
    void setname(char *);
    void setgender(bool);
    void setage(int);
    void setmajor(char *);
    void setcls(int);
    void setscore(double);
    int getno() const;
    char *getname() const;
    bool getgender() const;
    int getage() const;
    char *getmajor() const;
    int getcls() const;
    double getscore() const;
    friend std::ostream &operator<<(std::ostream &, const Student &);
};

#endif // STUDENT_INFORMATION_MANAGEMENT_SYSTEM_STUDENT_H