#ifndef VISUALMENU
#define VISUALMENU

#include "Button.h"
#include <list>
#include <conio.h>

template <class out, class in> class VisualMenu
{
public:

	VisualMenu();
	~VisualMenu();

	int update();

	int addElement(Label obj);
	int addElement(Button <out, in> obj);

private:

	int print();

	int hideCursor();
	int moveCursor();

	int execute();

	int cursor;

	std::list <Label> labels;
	std::list <Button <out, in>> buttons;
};

#include "VisualMenu_impl.h"

#endif