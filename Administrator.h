// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef STUDENT_INFORMATION_MANAGEMENT_SYSTEM_ADMINISTRATOR_H
#define STUDENT_INFORMATION_MANAGEMENT_SYSTEM_ADMINISTRATOR_H

#include "Student.h"
#include <vector>

class Administrator
{
private:
    std::vector<Student> stu;
    static int maxno;

public:
    Student getstu(int i);
    static int getmaxno();
    int add(char *i_name, bool i_gender, int i_age, char *i_major, int i_cls, double i_score);
    int find(int i_no);
    int find(char *i_name);
    std::vector<int> findbycls(char *i_major, int i_cls);
    bool erase(int i_no);
    bool erase(char *i_name);
    bool edit(int i_no, char *i_name, bool i_male, int i_age, char *i_major, int i_cls, double i_score);
    void display();
    void sequence(bool ascending = true);
    double average();
    void loadfile();
    void writefile();
};

#endif // STUDENT_INFORMATION_MANAGEMENT_SYSTEM_ADMINISTRATOR_H