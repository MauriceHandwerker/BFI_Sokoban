#include <string>
#include <unistd.h>
#include <ncurses.h>

#define WAIT_TICK 10000
WINDOW *wnd;

int init();
void run();
void close();

int main () {
init();
run();
close();
}

int init() {
    wnd = initscr(); // Ncurses: Initialisierung mit wnd-Handler
    cbreak(); // siehe Part01
    noecho();
    clear();

    keypad(wnd, true); // Sondertasten ein, für Spielersteuerung

    curs_set(0); // Cursor aus, würde sonst am Spieler blinken

    start_color(); // Farben einschalten

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(1)); // Hintergrund/Vordergrundfarben des Fensters

    attron(A_BOLD); // Attribut Fett ein
    box(wnd, 0, 0); // Box über gesamten Bildschirm zeichnen
    attroff(A_BOLD); // Attribut Fett aus

    return 0;
}

void run() {
    bool exit_requested = false;

    while(!exit_requested) {
    int in_char = wgetch(wnd);
    switch(in_char) {
    case 'l': // quit game
    exit_requested = true;
    break;
    case KEY_UP: // up
    case 'w':
    break;
    case KEY_DOWN: // down
    case 's':
    break;
    case KEY_LEFT: // left
    case 'a':
    break;
    case KEY_RIGHT: // right
    case 'd':
    break;
    default:
    break;
    }
    usleep(WAIT_TICK); // 10 ms
    refresh();
    }
}

void close() {
    endwin();
}