#include "Label.h"

Label::Label() : Object()
{
	name = "default";
}

Label::Label(short _x, short _y, std::string _name) : Object(_x, _y)
{
	name = _name;
}

Label::~Label()
{

}

int Label::print()
{
	GoToXY();
	std::cout << name;
	return 0;
}