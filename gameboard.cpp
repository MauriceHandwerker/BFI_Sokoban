#include <iostream>
#include <ncurses.h>
#include <string> // Standard Header

#include "gameboard.hpp" // Einbinden der eigenen Modul-Headerdatei

using namespace std; // no Comment 

Gameboard::Gameboard(int xMax, int yMax, int widht, int height, string fileName) 
{
    initscr(); // Ncurses: Initialisierung + neues Fenster
    wnd = newwin(Point.y, Point.x, widht, height);
    cbreak();
    noecho();
    clear();

    keypad(wnd, true); // schaltet Sondertasten ein
    curs_set(0); // Cursor nicht sichtbar
    start_color(); // Farben einschalten

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    wbkgd(wnd, COLOR_PAIR(1)); // Hintergrund/Vordergrundfarben

    attron(A_BOLD); // Box zeichnen
    box(wnd, 0, 0);
    attroff(A_BOLD);
}

Gameboard::~Gameboard() 
{

}

WINDOW *Gameboard::getWindowHandle() 
{
    return wnd;
}