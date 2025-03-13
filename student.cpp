#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include "student.h"
using namespace std;
namespace fs = std::filesystem;
void Student()
{
    while (true)
    {
        cout << "Student";
        cout << "\n\n\t\tWelcome Student\n\t   =======================\n\t\t   =========";
        cout << "\nWhat operation would you like to perform : ";
        int student_operation;
        cout << "\n1. View Your Books\n2.Explore Books\n3. View Due Books\n4. Exit.\n5. Go Back ";
        cin >> student_operation;
        if (student_operation == 1) // View books
        {
            bought_book();
        }
        else if (student_operation == 2) // Explore more books
        {
            explore();
        }
        else if (student_operation == 3) // View books that needs to be returned
        {
            due_books();
        }
        else if (student_operation == 4) // Quickly exit and leave the program
        {
            exit(0);
        }
        else if (student_operation == 5) // go to previous page
        {
            cout << "Going Back...";
            return;
        }
        else
            cout << "Enter a valid choice";
    }
}
void bought_book()
{ // COde to view books that have been bought by the students
    while (true)
    {
        cout << "Showing all taken books to student..."<<endl;
        string student_book_folder = "C:\\Users\\hp\\Desktop\\Projects\\Knowledge-Nexus\\student books";
        vector<string> book_path_student;
        int index = 1;
        for (const auto &entry : fs::directory_iterator(student_book_folder))
        {
            if (entry.path().extension() == ".pdf")
            {
                cout << index << " ." << entry.path().filename().string() << endl;
                book_path_student.push_back(entry.path().string());
                index++;
            }
        }
        if (index == 1)
            cout << "No books available!" << endl;
        while (true)
        {
            cout << "Enter 1 to open a book\nEnter 999 for going back : ";
            int choice2;
            cin >> choice2;
            if (choice2 != 999)
            {
                cout << "Enter number of book you would like to open! or 999 to go back ";
                int choice2;
                cin >> choice2;
                // Code to open book
                if (choice2 >= 1 && choice2 <= book_path_student.size())
                {
                    string book_to_open = book_path_student[choice2 - 1]; // Because compiler starts from 0 index
                    cout << "Opening book " << book_to_open << endl;
                    system(("start msedge \"" + book_to_open + "\"").c_str());
                }
            
            }
            else if (choice2 == 999)
            {
                return;
            }
            else
                cout << "Invalid Choice"<<endl;
        }
        cout << "\nType B to go back ";
        char back;
        cin >> back;
        if (back == 'B' || 'b')
            return;
        else
            cout << "Enter a valid choice";
    }
}
void explore()
{
    while (true)
    {
        cout << "Showing books to buy..."<<endl;
        // Code for sudent to buy more books
        int index = 1;
        vector<string> book_paths;
        string path = "C:\\Users\\hp\\Desktop\\Projects\\Knowledge-Nexus\\student books";
        vector<string> book_num;
        for (const auto &entry : fs::directory_iterator(path))
        {
            if (entry.path().extension() == ".pdf")
            {
                cout << "\n"
                     << index << ". " << entry.path().filename().string();
                book_paths.push_back(entry.path().string());
                index++;
            }
        }
        if (index == 1)
            cout << "NO books found!" << endl;
        while (true)
        {
            cout << "What do you want ?" << endl;
            cout << "1. Open a book\n2. Go back\n3. To rent a book\n";
            int choice;
            cin >> choice;
            if (choice == 1)
            { // Code to open the book
                cout << "Enter the number of the book you want to open : ";
                int book_number;
                cin >> book_number;
                if (book_number >= 1 && book_number <= book_paths.size())
                {
                    string book_to_open = book_paths[book_number - 1]; // Because compiler starts from 0 index
                    cout << "Opening book " << book_to_open << endl;
                    system(("start msedge \"" + book_to_open + "\"").c_str());
                }
            }
            else if (choice == 2)
            { // To go back
                return;
            }
            else if (choice == 3)
            {
                // Code to buy a book
                string bought_book_path = "C:\\Users\\hp\\Desktop\\Projects\\Knowledge-Nexus\\Bought books"; // The path where bought books will be put
                while (true)
                {
                    cout << "Enter the number of book you want to buy : or enter 57779 for going back.\n";
                    int book_number;
                    cin >> book_number;
                    if (book_number == 57779)
                    {
                        return;
                    }
                    else
                    {
                        if (book_number < 1 || book_number > book_paths.size())
                        {
                            cout << "The book number is wrong!";
                        }
                        else
                        {
                            string sourcepath = book_paths[book_number - 1]; // because C++ starts with 0 index
                            string destinationpath = bought_book_path + "\\" + fs::path(sourcepath).filename().string();
                            try
                            {
                                fs::copy_file(sourcepath, destinationpath, fs::copy_options::overwrite_existing);
                                cout << "Book bought successfully! " << endl;
                                return;
                            }
                            catch (const fs::filesystem_error &e)
                            {
                                cout << "The error is coming : " << e.what() << endl;
                            }
                        }
                    }
                }
            }
            else
                cout << "Invalid choice!";
        }
    }
}
void due_books()
{
    while (true)
    {
        cout << "These are the due books...";
        // Code to show due date books and fines
        cout << "\nType B to go back ";
        char back;
        cin >> back;
        if (back == 'B' || 'b')
            return;
        else
            cout << "Enter a valid choice";
    }
}