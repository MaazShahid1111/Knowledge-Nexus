#include <iostream>
using namespace std;
#include "student.h"
#include "admin.h"
void display_chart()
{
    cout << "\t\t\t\t     Knowledege Nexus     "; // Main Menu
    cout << "\n\t\t==========================================================\n\t\t\t======================================";
    cout << "\n\n1. Student \n2. Admin \n3. Exit ";
}
int main()
{
    int choice_main;
    while (true)
    {
        display_chart();
        cout << "\nEnter a choice: ";
        cin >> choice_main;
        for (int i = 0; i < 0; i++)
        {
            if (choice_main == 1 || choice_main == 2 || choice_main == 3)
                break;
            else
                cout << "Enter a valid option";
        }
        if (choice_main == 1)
        {
            Student();
        }
        else if (choice_main == 2)
        {
            Admin();
        }
        else if (choice_main == 3)
        {
            exit(0);
        }
        else
        {
            cout << "Enter a valid option!";
        }
    }
    return 0;
}