#ifndef VISUALMENU_IMPL
#define VISUALMENU_IMPL

#include "VisualMenu.h"

template <class out, class in> 
int VisualMenu<out, in>::update()
{
	hideCursor();
	while (1)
	{
		system("cls");
		print();
		moveCursor();
	}
}

template <class out, class in> 
int VisualMenu<out, in>::addElement(Label obj)
{
	labels.push_back(obj);
	return 0;
};

template <class out, class in> 
int VisualMenu<out, in>::addElement(Button <out, in> obj)
{
	buttons.push_back(obj);
	return 0;
};

template <class out, class in> 
int VisualMenu<out, in>::print()
{
	int i = 0;
	HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);

	for (Label& elem : labels)
		elem.print();

	for (Button<out, in>& elem : buttons)
	{
		SetConsoleTextAttribute(handler, 8);
		if (i == cursor)
			SetConsoleTextAttribute(handler, 15);
		elem.print();
		i++;
	}

	SetConsoleTextAttribute(handler, 15);
	return 0;
};

template <class out, class in> 
int VisualMenu<out, in>::hideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE;  // Скрываем курсор
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	return 0;
};

template <class out, class in>
int VisualMenu<out, in>::moveCursor()
{
	int i = (int)_getch();

	switch (i)
	{
	case 80:
		++cursor;
		if (cursor >= buttons.size()) cursor = 0;
		break;
	case 72:
		--cursor;
		if (cursor < 0) cursor = buttons.size() - 1;
		break;
	case 13:
		execute();
		break;
	case 0 || 0xE0:
		moveCursor();
	default:
		break;
	}

	return 0;
};

template <class out, class in>
int VisualMenu<out, in>::execute()
{
	for (Button<out, in>& elem : buttons)
	{
		if (!cursor)
		{
			system("cls");
			objects = iter->callFunction(objects);
			break;
		}
		--cursor;
	}
	return 0;
};

template <class out, class in>
VisualMenu<out, in>::VisualMenu() : cursor(0) {}

template <class out, class in>
VisualMenu<out, in>::~VisualMenu() {}

#endif