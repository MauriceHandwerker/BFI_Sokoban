#include <iostream>
#include <string>
#include <ncurses.h>

using namespace std;

int main()
{
    string str1 = "Hello#World#and#Coders";
    string str2 = "Wie#Geht#es#den#so?";

    initscr();

    printw(str1);
    printw(str2);

    getch();
    endwin();

    return 0;
}