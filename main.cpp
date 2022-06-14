#include <string>
#include <memory>
#include <unistd.h>
#include <ncurses.h>

#include "gameboard.hpp"

using namespace std;

#define WAIT_TICK 10000
WINDOW *wnd;
shared_ptr<Gameboard> gb; // Smart-Pointer auf das Gameboard-Objekt 


int init();
void run();
void close();

int main () 
{
    init();
    run();
    close();
}

int init() 
{
    gb = make_shared<Gameboard>(10, 10, ""); // Erstellen eines Gameboard-Objekts
    wnd = gb->getWindowHandle(); // Holen des Ncurses-Handlers
    return 0;
}

void run() 
{

    int in_char;
    bool exit_requested = false;

    while(!exit_requested) 
    {
        in_char = wgetch(wnd);
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
        wrefresh(wnd);
    } 
}

void close() 
{
    endwin();
}