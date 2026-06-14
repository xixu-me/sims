// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#include "Administrator.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void Login(Administrator &admin);
void Menu(Administrator &admin);

int main()
{
    Administrator admin;
    Login(admin);
    return 0;
}

void print() { cout << " No.            Name  Gender  Age           Major  Class  Score" << endl; }

void Login(Administrator &admin)
{
    char password[MAXN] = "", input[MAXN];
    std::ifstream in("password.dat", ios::binary);
    in.read(password, MAXN);
    in.close();
    if (strcmp("", password) != 0)
    {
        cout << "Please enter your password to log in to the Student Information Management System: ";
        cin >> setw(MAXN) >> input;
        if (strcmp(input, password) != 0)
        {
            cout << "Wrong password!" << endl;
            exit(0);
        }
    }
    cout << "Do you want to modify or create a password? (Y/N): ";
    cin >> setw(MAXN) >> input;
    if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0)
        cout << endl;
    else if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0)
    {
        cout << "Please enter a password: ";
        cin >> setw(MAXN) >> input;
        std::ofstream out("password.dat", ios::binary);
        out.write(input, MAXN);
        out.close();
        cout << "Password modification or creation successful!" << endl
             << endl;
    }
    Menu(admin);
}

void Menu(Administrator &admin)
{
    char input1[MAXN], input4[MAXN];
    int input2, input5, input7;
    bool input3;
    double input6;
    cout << "Welcome to the Student Information Management System!" << endl;
    admin.loadfile();
    while (true)
    {
        cout << endl
             << "Please enter instructions: Find(F) Add(A) Edit(E) Delet(D) Sort(S) Average(V) Display(P) Quit(Q): ";
        cin >> setw(MAXN) >> input1;
        // #################### Find ####################
        if (strcmp("F", input1) == 0 || strcmp("f", input1) == 0)
        {
            cout << "Find by no.(0) or name(1) or class(2): ";
            cin >> input2;
            // Find by no.
            if (input2 == 0)
            {
                cout << "Please enter no.: ";
                cin >> input2;
                int i = admin.find(input2);
                if (i == -1)
                    cout << "Not found!" << endl;
                else
                {
                    print();
                    cout << admin.getstu(i) << endl;
                }
                continue;
            }
            // Find by name
            else if (input2 == 1)
            {
                cout << "Please enter name: ";
                cin >> setw(MAXN) >> input1;
                int i = admin.find(input1);
                if (i == -1)
                    cout << "Not found!" << endl;
                else
                {
                    print();
                    cout << admin.getstu(i) << endl;
                }
                continue;
            }
            // Find by class
            else if (input2 == 2)
            {
                cout << "Please enter major: ";
                cin >> setw(MAXN) >> input1;
                cout << "class: ";
                cin >> input2;
                vector<int> vi = admin.findbycls(input1, input2);
                if (!vi.size())
                    cout << "Not found!" << endl;
                else
                {
                    print();
                    for (int i : vi)
                    {
                        cout << admin.getstu(i) << endl;
                    }
                }
                continue;
            }
            else
                cout << "Enter error!" << endl;
        }
        // #################### Add ####################
        else if (strcmp("A", input1) == 0 || strcmp("a", input1) == 0)
        {
            cout << "Please enter name: ";
            cin >> setw(MAXN) >> input1;
            cout << "male(1) or female(0): ";
            cin >> input3;
            cout << "age: ";
            cin >> input2;
            cout << "major: ";
            cin >> setw(MAXN) >> input4;
            cout << "class: ";
            cin >> input5;
            cout << "score: ";
            cin >> input6;
            cout << "no.: " << admin.add(input1, input3, input2, input4, input5, input6) << endl;
            continue;
        }
        // #################### Edit ####################
        else if (strcmp("E", input1) == 0 || strcmp("e", input1) == 0)
        {
            cout << "Please enter no.: ";
            cin >> input2;
            if (admin.find(input2) == -1)
                cout << "Not exist!" << endl;
            else
            {
                cout << "name: ";
                cin >> setw(MAXN) >> input1;
                cout << "male(1) or female(0): ";
                cin >> input3;
                cout << "age: ";
                cin >> input7;
                cout << "major: ";
                cin >> setw(MAXN) >> input4;
                cout << "class: ";
                cin >> input5;
                cout << "score: ";
                cin >> input6;
                admin.edit(input2, input1, input3, input7, input4, input5, input6);
                cout << "Edited successfully!" << endl;
            }
            continue;
        }
        // #################### Delete ####################
        else if (strcmp("D", input1) == 0 || strcmp("d", input1) == 0)
        {
            cout << "Delete by no.(1) or name(0): ";
            cin >> input3;
            if (input3)
            {
                cout << "Please enter no.: ";
                cin >> input2;
                if (admin.erase(input2))
                    cout << "Deleted successfully!" << endl;
                else
                    cout << "Not exist!" << endl;
                continue;
            }
            else
            {
                cout << "Please enter name: ";
                cin >> setw(MAXN) >> input1;
                if (admin.erase(input1))
                    cout << "Deleted successfully!" << endl;
                else
                    cout << "Not exist!" << endl;
                continue;
            }
        }
        // #################### Sort ####################
        else if (strcmp("S", input1) == 0 || strcmp("s", input1) == 0)
        {
            cout << "Ascending(1) or descending(0) order: ";
            cin >> input3;
            admin.sequence(input3);
            cout << "Sorted successfully!" << endl;
        }
        // #################### Average ####################
        else if (strcmp("V", input1) == 0 || strcmp("v", input1) == 0)
            cout << "Average score: " << admin.average() << endl;
        // #################### Display ####################
        else if (strcmp("P", input1) == 0 || strcmp("p", input1) == 0)
            admin.display();
        // #################### Quit ####################
        else if (strcmp("Q", input1) == 0 || strcmp("q", input1) == 0)
        {
            cout << "Quit successfully!" << endl;
            break;
        }
        else
        {
            cout << "Enter error!" << endl;
            continue;
        }
    }
    admin.writefile();
}