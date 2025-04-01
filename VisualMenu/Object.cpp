#include "Object.h"

Object::Object()
{
	x = 0;
	y = 0;
}

Object::Object(short _x, short _y)
{
	x = _x;
	y = _y;
}

Object::~Object()
{

}

int Object::GoToXY()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, {x, y});
	return 0;
}