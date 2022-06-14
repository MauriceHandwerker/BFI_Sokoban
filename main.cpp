#include <string>
#include <iostream>
#include <memory>
#include <unistd.h>
#include <ncurses.h>

#include "gameboard.hpp"

using namespace std;

#define WAIT_TICK 10000
WINDOW *wnd1;
WINDOW *wnd2;
WINDOW *wnd3;

shared_ptr<Gameboard> gb; // Smart-Pointer auf das Gameboard-Objekt 
shared_ptr<Gameboard> gb2;
shared_ptr<Gameboard> gb3;

Point player;

int init();
void run();
void close();

int main () 
{
    player.x = 7;
    player.y = 5;
    cout << player.x << endl << player.y << endl;
    init();
    run();
    close();
}

int init() 
{
    gb = make_shared<Gameboard>(10, 10, 1, 1, ""); // Erstellen eines Gameboard-Objekts
    wnd1 = gb->getWindowHandle(); // Holen des Ncurses-Handlers
    gb2 = make_shared<Gameboard>(10, 10, 1, 15, "");
    wnd2 = gb2->getWindowHandle();
    gb3 = make_shared<Gameboard>(10, 10, 1, 30, "");
    wnd3 = gb3->getWindowHandle();
    return 0;
}

void run() 
{

    int in_char;
    bool exit_requested = false;

    while(!exit_requested) 
    {
        wrefresh(wnd1);
        wrefresh(wnd2);
        wrefresh(wnd3);

        in_char = wgetch(wnd1);
        switch(in_char) 
        {
            case 'q':
            exit_requested = true;
            break;
            case KEY_UP:
            case 'w':
            break;
            case KEY_DOWN:
            case 's':
            break;
            case KEY_LEFT:
            case 'a':
            break;
            case KEY_RIGHT:
            case 'd':
            break;
            default:
            break;
        }   
        usleep(WAIT_TICK);
    } 
}

void close() 
{
    endwin();
}