#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>

#include "gameboard.hpp"

using namespace std;


Gameboard::Gameboard( int pos1, int pos2, string fileName){
	wnd = nullptr;
	initscr();
	
	wnd = loadGameboard();
	cbreak();
	noecho();
	clear();
	
	refresh();
	
	
	keypad(wnd, true);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);	
	wbkgd(wnd, COLOR_PAIR(1));
	
	attron(A_BOLD);
	//box(wnd, 0, 0);
	attroff(A_BOLD);

}

Gameboard::~Gameboard() {
}

WINDOW *Gameboard::getWindowHandle() {
	return wnd;
}

WINDOW *Gameboard::loadGameboard(){
	WINDOW *w;
	char play = '@';
	char chest1 = '$';
	char chest2 = '$';
	char ch = '#';
	char dot = '.';
	player.y = 4;
	player.x = 4;
	max.y = 7;
	max.x = 10;
	
	w = newwin(max.y, max.x, 1 ,1);
    mvwaddch(w, player.y, player.x, play);
	mvwaddch(w, 2, 2, chest1);
	mvwaddch(w, 2, 4, chest2);
	mvwaddch(w, 0, 0, ch);
	mvwaddch(w, 0, 1, ch);
	mvwaddch(w, 0, 2, ch);
	mvwaddch(w, 0, 3, ch);
	mvwaddch(w, 0, 4, ch);
	mvwaddch(w, 0, 5, ch);
	mvwaddch(w, 0, 6, ch);
	mvwaddch(w, 0, 7, ch);
	mvwaddch(w, 1, 7, ch);
	mvwaddch(w, 2, 7, ch);
	mvwaddch(w, 3, 7, ch);
	mvwaddch(w, 3, 8, ch);
	mvwaddch(w, 3, 9, ch);
	mvwaddch(w, 4, 9, ch);
	mvwaddch(w, 5, 9, ch);
	mvwaddch(w, 5, 8, ch);
	mvwaddch(w, 5, 7, ch);
	mvwaddch(w, 6, 7, ch);
	mvwaddch(w, 6, 6, ch);
	mvwaddch(w, 6, 5, ch);
	mvwaddch(w, 6, 4, ch);
	mvwaddch(w, 6, 3, ch);
	mvwaddch(w, 6, 2, ch);
	mvwaddch(w, 6, 1, ch);
	mvwaddch(w, 6, 0, ch);
	mvwaddch(w, 5, 0, ch);
	mvwaddch(w, 4, 0, ch);
	mvwaddch(w, 3, 0, ch);
	mvwaddch(w, 2, 0, ch);
	mvwaddch(w, 1, 0, ch);
	mvwaddch(w, 4, 1, ch);
	mvwaddch(w, 4, 2, ch);
	mvwaddch(w, 4, 3, ch);
	mvwaddch(w, 5, 1, dot);
	mvwaddch(w, 5, 2, dot);


	return w;
}
Point Gameboard::getPlayer(){
	return player;
}
void Gameboard::movePlayer(Point move){
	char ch = mvwinch(wnd, move.y, move.x) & A_CHARTEXT;
	if('#' == ch || '$' == ch){
	
	}else{
		mvwaddch(wnd, move.y, move.x,'@');
		mvwaddch(wnd, player.y, player.x,prestau);
		player = move;
		prestau = ' ';
		wrefresh(wnd);
	}
	if(ch == '.' ){
		prestau = '.';
	}
	
}
char Gameboard::getItem(Point pt){
	char ch = mvwinch(wnd, pt.y, pt.x) & A_CHARTEXT;
	return ch;
}
void Gameboard::moveItem(Point from, Point to){
	char ch = mvwinch(wnd, to.y, to.x) & A_CHARTEXT;
	if('#' == ch || '$' == ch){

	}else{
		mvwaddch(wnd, to.y, to.x, '$');
		mvwaddch(wnd, from.y, from.x, irestau);
		wrefresh(wnd);
	}
	
}