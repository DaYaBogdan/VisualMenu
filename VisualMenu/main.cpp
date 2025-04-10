#include "VisualMenu.h"

int func(int& i)
{
	std::cout << "Yes" << std::endl;

	i++;

	_getch();

	return 1;
}

int func2(int& i)
{
	std::cout << i << std::endl;

	_getch();

	return 1;
}

int main()
{
	int i = 0;
	 
	Label label = { 2 , 3, "Label"};

	Button <> obj = {2, 1, "func1", func};

	Button <> obj2 = {2, 2, "func2", func2};

	VisualMenu <> menu(i);

	menu.addElement(label);
	menu.addElement(obj);
	menu.addElement(obj2);

	menu.openMenu();

	return 0;
}