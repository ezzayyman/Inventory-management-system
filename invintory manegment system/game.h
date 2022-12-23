#pragma once
#include<iostream>
#include<conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class GAMEshope {
public:
    void control_panel();
    void add_GAME();
    void show_GAME();
    void check_GAME();
    void update_GAME();
    void del_GAME();
};

// Function to display the menus
void GAMEshope::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t\tCONTROL  PANEL";
    cout << "\n\n1. ADD GAME";
    cout << "\n2. DISPLAY GAMES";
    cout << "\n3. CHECK PARTICULAR GAME";
    cout << "\n4. UPDATE GAME";
    cout << "\n5. DELETE GAME";
    cout << "\n6. BACK";
}

// Function to add GAME
void GAMEshope::add_GAME()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, a_name, b_id;
    cout << "\n\n\t\t\t\tADD GAMES";
    cout << "\n\nGAME ID : ";
    cin >> b_id;
    cout << "\nGAME Name : ";
    cin >> b_name;
    cout << "\nAuthor Name : ";
    cin >> a_name;
    cout << "\nNo. of GAMEs : ";
    cin >> no_copy;

    // Open file in append or
    // output mode
    file.open("/GAME.txt",
        ios::out | ios::app);
    file << " " << b_id << " "
        << b_name << " " << a_name
        << " " << no_copy << "\n";
    file.close();
}

// Function to display GAME
void GAMEshope::show_GAME()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, b_id, a_name;
    cout << "\n\n\t\t\t\t\tAll GAMES";

    // Open the file in input mode
    file.open("D:// GAME.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nGAME ID\t\tGAME"
            << "\t\tAuthor\t\tNo. of "
            "GAMEs\n\n";
        file >> b_id >> b_name;
        file >> a_name >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {

            cout << "  " << b_id
                << "\t\t" << b_name
                << "\t\t" << a_name
                << "\t\t" << no_copy
                << "\n\n";
            file >> b_id >> b_name;
            file >> a_name >> no_copy;
        }

        system("pause");

        // Close the file
        file.close();
    }
}

// Function to check the GAME
void GAMEshope::check_GAME()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string b_id, b_name, a_name, b_idd;

    cout << "\n\n\t\t\t\tCheck "
        << "Particular GAME";

    // Open the file in input mode
    file.open("D:// GAME.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nGAME ID : ";
        cin >> b_idd;
        file >> b_id >> b_name;
        file >> a_name >> no_copy;

        while (!file.eof()) {

            if (b_idd == b_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                    << "Check Particular GAME";
                cout << "\n\nGAME ID : "
                    << b_id;
                cout << "\nName : "
                    << b_name;
                cout << "\nAuthor : "
                    << a_name;
                cout << "\nNo. of GAMEs : "
                    << no_copy;
                cout << endl
                    << endl;
                count++;
                break;
            }
            file >> b_id >> b_name;
            file >> a_name >> no_copy;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nGAME ID Not"
            << " Found...";
    }
}

// Function to update the GAME
void GAMEshope::update_GAME()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string b_name, b_na, a_name;
    string a_na, b_idd, b_id;

    cout << "\n\n\t\t\t\tUpdate GAME Record";
    file1.open("D:// GAME1.txt",
        ios::app | ios::out);
    file.open("D:// GAME.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nGAME ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {
            if (b_id == b_idd) {
                system("cls");
                cout << "\t\t\t\t"
                    << "Update GAME Record";
                cout << "\n\nNew GAME Name : ";
                cin >> b_na;
                cout << "\nAuthor Name : ";
                cin >> a_na;
                cout << "\nNo. of GAMEs : ";
                cin >> no_co;
                file1 << " " << b_id << " "
                    << b_na << " "
                    << a_na << " " << no_co
                    << "\n\n";
                count++;
            }
            else
                file1 << " " << b_idd
                << " " << b_name
                << " " << a_name
                << " " << no_copy
                << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nGAME ID"
            << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("D:// GAME.txt");
    rename("D:// GAME1.txt",
        "D:// GAME.txt");
}

// Function to delete GAME
void GAMEshope::del_GAME()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string b_id, b_idd, b_name, a_name;
    cout << "\n\n\t\t\t\tDelete a GAME";

    // Append file in output mode
    file1.open("D:// GAME1.txt",
        ios::app | ios::out);
    file.open("D:// GAME.txt",
        ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nGAME ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> no_copy;
        while (!file.eof()) {

            if (b_id == b_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                    << "Delete a GAME";
                cout << "\n\nGAME is Deleted "
                    "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << b_idd
                << " " << b_name
                << " " << a_name
                << " " << no_copy
                << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nGAME ID "
            << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("D:// GAME.txt");
    rename("D:// GAME1.txt",
        "D:// GAME.txt");
}

// Function for GAME shop record
void GAMEShopRecord()
{
    int choice;
    char x;
    GAMEshope b;

    while (true) {

        b.control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_GAME();
                cout << "\n\nWant to add"
                    << " another GAME? "
                    "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.show_GAME();
            break;

        case 3:
            b.check_GAME();
            break;
        case 4:
            b.update_GAME();
            break;

        case 5:
            b.del_GAME();
            break;

        case 6:
            main();
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}


