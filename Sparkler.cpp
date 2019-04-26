#include <curses.h>

#include "sparkler.hpp"
#include "fw.hpp"

void Sparkler::Draw()
{
	int a = this->GetAge();

	if ((a % 2) == 0)
	{
		mvaddch(this->position.y, this->position.x, 'x');
	}
	else
	{
		mvaddch(this->position.y, this->position.x, '+');
	}
}