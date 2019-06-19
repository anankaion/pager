#include<ncurses.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
	FILE *fp;
	char* line = NULL;
	size_t len = 0;

	int row;
	int col;
	int y;
	int x;
	
	//File stuff
	if(!(fp = fopen(argv[1], "r"))){
		printw("Could not open file!");
		getch();
		endwin();
		return 1;
	}

	//curses
	initscr();
	raw();
	noecho();
	getmaxyx(stdscr, row, col);
	
	while(getline(&line, &len, fp) != -1) {
		getyx(stdscr, y, x);
		if(y == (row - 1)) {
			printw("---Press Key---");
			getch();
			clear();
			move(0, 0);
		}

		printw(line);
		refresh();
	}
	
	fclose(fp);

	getch();
	endwin();
	return 0;
}
