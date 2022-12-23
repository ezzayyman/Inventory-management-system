#include<iostream>
#include<conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main();
#include "book.h"
#include "movie.h"
#include "game.h"




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


    

}
