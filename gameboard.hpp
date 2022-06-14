#ifndef GAMEBOARD_HPP // Sentinel (Wächter), verhindert das
#define GAMEBOARD_HPP // Mehrfachladen der Headerdatei!

#include <string> // Verweis auf string
#include <ncurses.h> // Verweis auf ncurses

using namespace std; // sollte klar sein!

class Gameboard 
{ // Klassendefinition
    private: // Sichtbarkeit
    WINDOW *wnd; // Eigenschaft

    public: // Sichtbarkeit
    Gameboard(int, int, string); // Konstruktor
    virtual ~Gameboard(); // Destruktor
    virtual WINDOW *getWindowHandle(); // eine Methode
};

class Point 
{ // Point-Klasse als Struktur-Ersatz
    public: // public-Attribute hier sinnvoll
    int x;
    int y;
}; 

#endif