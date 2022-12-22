#include<iostream>
#include<conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//mahmoud 
//ezz
int main();

class bookshop {
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
    cout << "\n\n\t\t\t\tCONTROL  PANEL";
    cout << "\n\n1. ADD BOOK";
    cout << "\n2. DISPLAY BOOKS";
    cout << "\n3. CHECK PARTICULAR BOOK";
    cout << "\n4. UPDATE BOOK";
    cout << "\n5. DELETE BOOK";
    cout << "\n6. BACK";
}

// Function to add book
void bookshop::add_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, a_name, b_id;
    cout << "\n\n\t\t\t\tADD BOOKS";
    cout << "\n\nBook ID : ";
    cin >> b_id;
    cout << "\nBook Name : ";
    cin >> b_name;
    cout << "\nAuthor Name : ";
    cin >> a_name;
    cout << "\nNo. of Books : ";
    cin >> no_copy;

    // Open file in append or
    // output mode
    file.open("D:// book.txt",
        ios::out | ios::app);
    file << " " << b_id << " "
        << b_name << " " << a_name
        << " " << no_copy << "\n";
    file.close();
}

// Function to display book
void bookshop::show_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, b_id, a_name;
    cout << "\n\n\t\t\t\t\tAll BOOKS";

    // Open the file in input mode
    file.open("D:// book.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nBook ID\t\tBook"
            << "\t\tAuthor\t\tNo. of "
            "Books\n\n";
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

// Function to check the book
void bookshop::check_book()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string b_id, b_name, a_name, b_idd;

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
        file >> a_name >> no_copy;

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
                cout << "\nNo. of Books : "
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
            cout << "\n\nBook ID Not"
            << " Found...";
    }
}

// Function to update the book
void bookshop::update_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string b_name, b_na, a_name;
    string a_na, b_idd, b_id;

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
        file >> a_name >> no_copy;

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
                cout << "\nNo. of Books : ";
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
    int no_copy, count = 0;
    string b_id, b_idd, b_name, a_name;
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
        file >> a_name >> no_copy;
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
                << " " << no_copy
                << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> no_copy;
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
            //exit(false);
            //listing();
            main();
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}




// Driver Code

class MOVIEshope {
public:
    void control_panel();
    void add_MOVIE();
    void show_MOVIE();
    void check_MOVIE();
    void update_MOVIE();
    void del_MOVIE();
};

// Function to display the menus
void MOVIEshope::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t\tCONTROL  PANEL";
    cout << "\n\n1. ADD MOVIE";
    cout << "\n2. DISPLAY MOVIES";
    cout << "\n3. CHECK PARTICULAR MOVIE";
    cout << "\n4. UPDATE MOVIE";
    cout << "\n5. DELETE MOVIE";
    cout << "\n6. BACK";
}

// Function to add MOVIE
void MOVIEshope::add_MOVIE()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, a_name, b_id;
    cout << "\n\n\t\t\t\tADD MOVIES";
    cout << "\n\nMOVIE ID : ";
    cin >> b_id;
    cout << "\nMOVIE Name : ";
    cin >> b_name;
    cout << "\nAuthor Name : ";
    cin >> a_name;
    cout << "\nNo. of MOVIEs : ";
    cin >> no_copy;

    // Open file in append or
    // output mode
    file.open("/MOVIE.txt",
        ios::out | ios::app);
    file << " " << b_id << " "
        << b_name << " " << a_name
        << " " << no_copy << "\n";
    file.close();
}

// Function to display MOVIE
void MOVIEshope::show_MOVIE()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name, b_id, a_name;
    cout << "\n\n\t\t\t\t\tAll MOVIES";

    // Open the file in input mode
    file.open("D:// MOVIE.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nMOVIE ID\t\tMOVIE"
            << "\t\tAuthor\t\tNo. of "
            "MOVIEs\n\n";
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

// Function to check the MOVIE
void MOVIEshope::check_MOVIE()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string b_id, b_name, a_name, b_idd;

    cout << "\n\n\t\t\t\tCheck "
        << "Particular MOVIE";

    // Open the file in input mode
    file.open("D:// MOVIE.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nMOVIE ID : ";
        cin >> b_idd;
        file >> b_id >> b_name;
        file >> a_name >> no_copy;

        while (!file.eof()) {

            if (b_idd == b_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                    << "Check Particular MOVIE";
                cout << "\n\nMOVIE ID : "
                    << b_id;
                cout << "\nName : "
                    << b_name;
                cout << "\nAuthor : "
                    << a_name;
                cout << "\nNo. of MOVIEs : "
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
            cout << "\n\nMOVIE ID Not"
            << " Found...";
    }
}

// Function to update the MOVIE
void MOVIEshope::update_MOVIE()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string b_name, b_na, a_name;
    string a_na, b_idd, b_id;

    cout << "\n\n\t\t\t\tUpdate MOVIE Record";
    file1.open("D:// MOVIE1.txt",
        ios::app | ios::out);
    file.open("D:// MOVIE.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nMOVIE ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {
            if (b_id == b_idd) {
                system("cls");
                cout << "\t\t\t\t"
                    << "Update MOVIE Record";
                cout << "\n\nNew MOVIE Name : ";
                cin >> b_na;
                cout << "\nAuthor Name : ";
                cin >> a_na;
                cout << "\nNo. of MOVIEs : ";
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
            cout << "\n\nMOVIE ID"
            << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("D:// MOVIE.txt");
    rename("D:// MOVIE1.txt",
        "D:// MOVIE.txt");
}

// Function to delete MOVIE
void MOVIEshope::del_MOVIE()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string b_id, b_idd, b_name, a_name;
    cout << "\n\n\t\t\t\tDelete a MOVIE";

    // Append file in output mode
    file1.open("D:// MOVIE1.txt",
        ios::app | ios::out);
    file.open("D:// MOVIE.txt",
        ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nMOVIE ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> no_copy;
        while (!file.eof()) {

            if (b_id == b_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                    << "Delete a MOVIE";
                cout << "\n\nMOVIE is Deleted "
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
            cout << "\n\nMOVIE ID "
            << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("D:// MOVIE.txt");
    rename("D:// MOVIE1.txt",
        "D:// MOVIE.txt");
}

// Function for MOVIE shop record
void MOVIEShopRecord()
{
    int choice;
    char x;
    MOVIEshope b;

    while (true) {

        b.control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_MOVIE();
                cout << "\n\nWant to add"
                    << " another MOVIE? "
                    "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.show_MOVIE();
            break;

        case 3:
            b.check_MOVIE();
            break;
        case 4:
            b.update_MOVIE();
            break;

        case 5:
            b.del_MOVIE();
            break;

        case 6:
            main();
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}

// GAMEshop Class
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

/*int listing() {



}
*/


int main() {

    int choice = 0;

    system("cls");

    cout << "\n";


    for (int i = 0; i < 26; i++) {
        cout << "/";
    }

    cout << " Digital Market ";

    for (int i = 0; i < 26; i++) {
        cout << "/";
    }


    cout << endl;
    cout << "\n\n 1.BOOKS ";
    cout << "\n 2.MOVIES";
    cout << "\n 3.GAMES";
    cout << "\n 4.EXIT";

    cout << "\n\n please enter your choice\n";
    cin >> choice;



    switch (choice) {
    case 1:  bookShopRecord();
        break;
    case 2: MOVIEShopRecord();
        break;
    case 3: GAMEShopRecord();
        break;
    case 4:
        exit(0);
        break;
    default: cout << "\n\n invaled choice\n";
    }

    
    //listing();

}









