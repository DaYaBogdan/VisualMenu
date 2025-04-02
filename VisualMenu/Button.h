#ifndef BUTTON
#define BUTTON

#include "Label.h"

template <class in = int&, class out = int>
class Button :
	public Label
{
public:
	using Function = out(*) (in);

	out callFunction(in obj) const { return func(obj); };

	Button(Function _func) : func(_func) {};
	Button(short _x, short _y, std::string _name, Function _func) : Label(_x, _y, _name), func(_func) {};

private:
	Function func;
};

#endif // !BUTTON
