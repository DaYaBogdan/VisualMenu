#include "VisualMenu.h"

void func(int i)
{
	std::cout << "Yes" << std::endl;

	_getch();

	return;
}

int main()
{
	Button <void, int> obj = {func};

	VisualMenu <void, int> menu;

	menu.addElement(obj);

	menu.update();

	return 0;
}