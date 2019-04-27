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
		std::this_thread::sleep_for(std::chrono::milliseconds(3));
	}
	else if ((a % 2) == 1)
	{
		mvaddch(this->position.y, this->position.x, '+');
		std::this_thread::sleep_for(std::chrono::milliseconds(3));
	}
}