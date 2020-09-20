#include <iostream>
using namespace std;

/*
 * Import library
 */
#include <vector>
#include <windows.h>

/*
 * MACRO
 */
#define WIDTH 40
#define HEIGHT 20
#define BODY '*'

// Each point is a part of the snake
struct Point
{
	int x;
	int y;
};

/*
 * Global variables
 */
// Create snake
vector<Point> snake = {
	Point{ WIDTH / 2 + 2, HEIGHT / 2 },
	Point{ WIDTH / 2 + 1, HEIGHT / 2 },
	Point{ WIDTH / 2, HEIGHT / 2 },
	Point{ WIDTH / 2, HEIGHT / 2 },
	Point{ WIDTH / 2 - 2, HEIGHT / 2 }
};


/*
 * Prototype
 */
void drawSnakePart(Point);
void drawSnake();
void gotoxy(int, int);
void ShowConsoleCursor(bool);


/*
 * Let's the game start
 */
int main()
{
	ShowConsoleCursor(false);

	drawSnake();

	ShowConsoleCursor(true);
	return 0;
}


/*
 * Snake functions
 */
// Draw a part of snake
void drawSnakePart(Point p)
{
	gotoxy(p.x, p.y);
	cout << BODY;
}

// Draw whole snake
void drawSnake()
{
	for (size_t i = 0; i < snake.size(); i++)
		drawSnakePart(snake[i]);
}

/*
 * Console functions
 */
// Goto position (x, y)
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

// Set the visibility of cursor
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}