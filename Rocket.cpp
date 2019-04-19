#include "fw.hpp"
#include <curses.h>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;

float Rocket::gravity = 1.0;

Rocket::Rocket()
{
	this->SetAgeLimit(rand() % (LINES - 10));
	this->SetTriggerAge(rand() % (LINES - 20));
	this->SetPosition(0, rand() % (COLS - 1));
	this->age = 0;
}

Rocket::~Rocket()
{
}

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

/*
0 = LINES - 1
Starting at 0 to COLS - 1

*/
void Rocket::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

/*
IF x force is 0, rocket only goes up and down
IF y force is 0, rocket only goes right to left
*/
void Rocket::SetForce(float x, float y)
{
	this->force.x = x;
	this->force.y = y;
}

void Rocket::Draw()
{
	mvaddch(this->position.y, this->position.x, '*');
}

/*
Add force to current position
Subtract Gravity from y force
Graphics can only be used in integers,
	there will be a difference between numerical
	value and where it is drawn because floats
	will be rounded.

*/
void Rocket::Step(vector<Rocket *> &v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		Rocket r = *(v.at(i));

		r.position.x += r.force.x;
		r.position.y += r.force.y;

		r.position.y += r.gravity;

		r.age += 1;
	}
}

bool Rocket::IsAlive()
{
	if (this->age <= age_limit)
	{
		return true;
	}
	else
	{
		return false;
	}
	return true;
}
bool Rocket::IsTriggered()
{
	if (this->age >= this->trigger_age)
	{
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

/*
Gravity only affects y force
*/
void Rocket::SetGravity(float g)
{
	gravity = g;
}

void Rocket::Trigger(vector<Rocket *> &v)
{
	Rocket *r = new Rocket();
	(*r).age = 0;
}

int Rocket::GetAge()
{
	return this->age;
}