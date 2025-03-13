#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "admin.h"
using namespace std;
namespace fs = std::filesystem; // To avoid writting std::filesystem and write fs:: instead
void Admin()
{
    while (true)
    {
        cout << "\n\nWelcome Admin\n\n";
        cout << "\nWhat operation would you like to perform : ";
        int admin_operation;
        cout << "\n1. View Books\n2.Add Books\n3. View Students Information\n4. Exit\n5. Go back. ";
        cin >> admin_operation;
        if (admin_operation == 1)
        {
            view_books(); // Because admin can view all books
        }
        else if (admin_operation == 2)
        {
            add_book(); // Adds books from admin folder to student folder for student to view
        }
        else if (admin_operation == 3)
        {
            view_info(); // View all student information to admin
        }
        else if (admin_operation == 4)
        {
            exit(0);
        }
        else if (admin_operation == 5)
        {
            cout << "Going Back...";
            return;
        }
        else
            cout << "Enter a valid choice";
    }
}
void view_info() // View all student information to admin
{
    while (true)
    {
        cout << "Viewing all student details to admin...";
        // Code to view student details
        void view_student();
        cout << "\n\n";
        cout << "\nType B to go back ";
        char back;
        cin >> back;
        if (back == 'B' || 'b')
            return;
        else
            cout << "Enter a valid choice";
    }
}
void view_books() // Because admin can view all books
{
    cout << "Showing names of books available in the library...";
    // Code too show all pdfs of books available in the library
    int index = 1;
    vector<string> book_path_admin;
    string path_to_admin = "C:\\Users\\hp\\Desktop\\Projects\\Knowledge-Nexus\\admin books";
    for (const auto &entry : fs::directory_iterator(path_to_admin))
    {
        if (entry.path().extension() == ".pdf")
        {
            cout << "\n"
                 << index << ". " << entry.path().filename().string() << endl;
            book_path_admin.push_back(entry.path().string());
            index++;
        }
    }
    if (index == 1)
        cout << "No books found!\n";
    while (true)
    {
        cout << "What do you want ?" << endl;
        cout << "1. Open a book\n2. Go back\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the number of the book you want to open : or enter 999 to go back ";
            int choice1;
            cin >> choice1;
            if (choice1 != 999)
            {
                int book_number;
                cin >> book_number;
                // Code to open book
                if (book_number >= 1 && book_number <= book_path_admin.size())
                {
                    string book_to_open = book_path_admin[book_number - 1]; // Because compiler starts from 0 index
                    cout << "Opening book " << book_to_open << endl;
                    system(("start msedge \"" + book_to_open + "\"").c_str());
                }
            }
            else if (choice1 == 999)
            {
                return;
            }
            else
            {
                cout << "Enter a valid choice";
            }
        }
        else if (choice == 2)
        {
            return;
        }
        else
            cout << "Invalid choice!";
    }
}
void add_book() // Function to move books to student library
{               // Adds books from admin folder to student folder for student to view
    string admin_folder, student_folder;
    admin_folder = "C:\\Users\\hp\\Desktop\\Projects\\Knowledge-Nexus\\admin books";
    student_folder = "C:\\Users\\hp\\Desktop\\Projects\\Knowledge-Nexus\\student books";
    while (true)
    {
        cout << "Showing names of books available in the admin library to add to student library...";
        // Code too show all pdfs of books available in the library
        int index = 1;
        vector<string> book_paths;
        string path = "C:\\Users\\hp\\Desktop\\Projects\\Knowledge-Nexus\\admin books";
        for (const auto &entry : fs::directory_iterator(path))
        {
            if (entry.path().extension() == ".pdf")
            {
                cout << "\n"
                     << index << ". " << entry.path().filename().string() << endl;
                book_paths.push_back(entry.path().string());
                index++;
            }
        }
        while (true)
        {
            cout << "Type 1 to transfer book\nType 2 to go back ";
            int choice;
            cin >> choice;
            if (choice == 1)
            { // code to transfer book
                cout << "Enter the number of book you want to transfer : ";
                int book_number;
                cin >> book_number;
                if (book_number < 1 || book_number > book_paths.size())
                {
                    cout << "The book number is wrong!";
                }
                else
                {
                    string sourcepath = book_paths[book_number - 1]; // because C++ starts with 0 index
                    string destinationpath = student_folder + "\\" + fs::path(sourcepath).filename().string();
                    try
                    {
                        fs::copy_file(sourcepath, destinationpath, fs::copy_options::overwrite_existing);
                        cout << "Book Copied to " << destinationpath << endl;
                    }
                    catch (const fs::filesystem_error &e)
                    {
                        cout << "The error is coming : " << e.what() << endl;
                    }
                }
            }
            else if (choice == 2)
            {
                return;
            }
            else
                cout << "Invalid choice";
        }
        if (book_paths.empty())
            cout << "No books available to transfer!";
    }
}