#pragma once
#include<iostream>
#include<conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include<string>
using namespace std;

class genre {
    int choice;
public:

    string book_genre() {
        cout << "\n\n 1.Fiction";
        cout << "\t 2.NonFiction";
        cout << "\t 3.Drama";
        cout << "\t 4.Poetry";
        cout << "\t 5.Folkatale\n";
        cin >> choice;

        switch (choice) {
        case 1: return "Fiction ";
            break;
        case 2: return "NonFiction";
            break;
        case 3: return "Drama";
            break;
        case 4: return "Poerty";
            break;
        case 5: return"Folkatale";
            break;
        default:  cout << "\n\n invaled choice\n";

        };

    };




};

class bookshop : public genre {
public:
    bookshop() {};

    void control_panel();
    void add_book();
    void show_book();
    void check_book();
    void update_book();
    void del_book();



};



// Function to display the menus
void bookshop::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t\tBook  Shop";
    cout << "\n\n1. ADD BOOK";
    cout << "\n2. DISPLAY BOOKS";
    cout << "\n3. CHECK PARTICULAR BOOK";
    cout << "\n4. UPDATE BOOK";
    cout << "\n5. DELETE BOOK";
    cout << "\n6. BACK";
}

// Function to add book


void bookshop::add_book() {


    system("cls");
    fstream file;
    int no_copy;
    string b_name, a_name, b_id, b_genre, b_price;





    cout << "\n\n\t\t\t\tADD BOOKS";
    cout << "\n\nBook ID : ";
    cin >> b_id;
    cout << "\nBook Name : ";
    cin >> b_name;
    cout << "\nAuthor Name : ";
    cin >> a_name;
    cout << "\nChoose Book Genre : ";
    b_genre = book_genre();
    cout << "\nbook price : ";
    cin >> b_price;
    cout << "\nNo. of Books : ";
    cin >> no_copy;


    // Open file in append or
    // output mode
    file.open("D:// book.txt",
        ios::out | ios::app);

    file << " " << b_id << " "
        << b_name << " " << a_name << " " << b_genre
        << " " << b_price << " " << no_copy << "\n";
    file.close();
}

// Function to display book
void bookshop::show_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, b_id, a_name, b_genre, b_price;
    cout << "\n\n\t\t\t\t\tAll BOOKS";

    // Open the file in input mode
    file.open("D:// book.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nBook ID\t\tBook"
            << "\t\tAuthor\t\tBook genre\t\tbook price\t\tNo. of "
            "Books\n\n";
        file >> b_id >> b_name;
        file >> a_name >> b_genre >> b_price >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {

            cout << "  " << b_id
                << "\t\t" << b_name
                << "\t\t" << a_name
                << "\t\t" << b_genre
                << "\t\t\t" << b_price
                << "\t\t\t" << no_copy
                << "\n\n";
            file >> b_id >> b_name;
            file >> a_name >> b_genre;
            file >> b_price >> no_copy;
        }

        system("pause");

        // Close the file
        file.close();
    }
}

// Function to check the book
void bookshop::check_book()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string b_id, b_name, a_name, b_idd, b_genre, b_price;

    cout << "\n\n\t\t\t\tCheck "
        << "Particular Book";

    // Open the file in input mode
    file.open("D:// book.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nBook ID : ";
        cin >> b_idd;
        file >> b_id >> b_name;
        file >> a_name >> b_genre >> b_price >> no_copy;

        while (!file.eof()) {

            if (b_idd == b_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                    << "Check Particular Book";
                cout << "\n\nBook ID : "
                    << b_id;
                cout << "\nName : "
                    << b_name;
                cout << "\nAuthor : "
                    << a_name;
                cout << "\n Book genre:"
                    << b_genre;
                cout << "\n Book price:"
                    << b_price;
                cout << "\nNo. of Books : "
                    << no_copy;
                cout << endl
                    << endl;
                count++;
                break;
            }
            file >> b_id >> b_name;
            file >> a_name >> b_genre >> b_price >> no_copy;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nBook ID Not"
            << " Found...";
    }
}

// Function to update the book
void bookshop::update_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, b_price, b_pr, count = 0;
    string b_name, b_na, b_genre, a_name;
    string a_na, b_idd, b_id, b_ge;

    cout << "\n\n\t\t\t\tUpdate Book Record";
    file1.open("D:// book1.txt",
        ios::app | ios::out);
    file.open("D:// book.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nBook ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> b_genre >> b_price >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {
            if (b_id == b_idd) {
                system("cls");
                cout << "\t\t\t\t"
                    << "Update Book Record";
                cout << "\n\nNew Book Name : ";
                cin >> b_na;
                cout << "\nAuthor Name : ";
                cin >> a_na;
                cout << "\nbook genre : ";
                b_ge = book_genre();
                cout << "\nbook price : ";
                cin >> b_pr;
                cout << "\nNo. of Books : ";
                cin >> no_co;
                file1 << " " << b_id << " "
                    << b_na << " "
                    << a_na << " " << b_ge << " " << b_pr <<
                    " " << no_co
                    << "\n\n";
                count++;
            }
            else
                file1 << " " << b_idd
                << " " << b_name
                << " " << a_name
                << " " << b_genre
                << " " << b_price
                << " " << no_copy
                << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> b_genre;
            file >> b_price >> no_copy;
        }
        if (count == 0)
            cout << "\n\nBook ID"
            << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("D:// book.txt");
    rename("D:// book1.txt",
        "D:// book.txt");
}

// Function to delete book
void bookshop::del_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, b_price, count = 0;
    string b_id, b_idd, b_name, a_name, b_genre;
    cout << "\n\n\t\t\t\tDelete a Book";

    // Append file in output mode
    file1.open("D:// book1.txt",
        ios::app | ios::out);
    file.open("D:// book.txt",
        ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nBook ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> b_genre;
        file >> b_price >> no_copy;
        while (!file.eof()) {

            if (b_id == b_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                    << "Delete a Book";
                cout << "\n\nBook is Deleted "
                    "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << b_idd
                << " " << b_name
                << " " << a_name
                << " " << b_genre
                << " " << b_price
                << " " << no_copy
                << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> b_genre;
            file >> b_price >> no_copy;
        }
        if (count == 0)
            cout << "\n\nBook ID "
            << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("D:// book.txt");
    rename("D:// book1.txt",
        "D:// book.txt");
}

// Function for book shop record
void bookShopRecord()
{
    int choice;
    char x;
    bookshop b;

    while (true) {

        b.control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_book();
                cout << "\n\nWant to add"
                    << " another book? "
                    "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.show_book();
            break;

        case 3:
            b.check_book();
            break;
        case 4:
            b.update_book();
            break;

        case 5:
            b.del_book();
            break;

        case 6:

            main();
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}
