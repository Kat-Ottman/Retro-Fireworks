#include "fw.hpp"
#include <curses.h>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>

void Rocket::SetTriggerAge(int i)
{
	this->trigger_age = i;
}

void Rocket::SetAgeLimit(int i)
{
	this->age_limit = i;
}

void Rocket::SetPosition(Rocket &other)
{
	this->position.x = other.position.x;
	this->position.y = other.position.y;
}

void Rocket::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

void Rocket::SetForce(float x, float y)
{
	this->force.x = x;
	this->force.y = y;
}

void Rocket::Draw()
{
	mvaddch(this->position.x, this->position.y, 'x');
}

void Rocket::Step()
{
}