#include <curses.h>

#include "sparkler.hpp"
#include "fw.hpp"
#include <thread>
#include <chrono>

void Sparkler::Draw()
{
	int a = this->GetAge();

	if ((a % 2) == 0)
	{
		mvaddch(this->position.y, this->position.x, 'x');
	}
	else if ((a % 2) == 1)
	{
		mvaddch(this->position.y, this->position.x, '+');
	}
}