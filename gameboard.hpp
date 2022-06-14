#ifndef GAMEBOARD_HPP		// Sentinel (Wächter), verhindert das
#define GAMEBOARD_HPP		// Mehrfachladen der Headerdatei! 

#include <string>
#include <ncurses.h>
#include <vector>
using namespace std;

class Point {
	public:
		int x;
		int y;
};

class Gameboard{
	private:
		WINDOW *wnd;
		Point max;
		Point player;
		char prestau = ' ';
		char irestau = ' ';
		WINDOW *loadGameboard();

	public:
		Gameboard(int, int,string);
		virtual ~Gameboard();
		virtual WINDOW *getWindowHandle();
		Point getPlayer();
		void movePlayer(Point);
		char getItem(Point pt);
		void moveItem(Point from, Point to);
};


#endif
