#include "fw.hpp"
#include <curses.h>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>
#include "palmtree.hpp"
#include "streamer.hpp"

float Rocket::gravity = 1.0;

/*
Randomnly assigns rocket with age limit,
trigger age, and position.
Sets age to 0.
*/
Rocket::Rocket()
{
	this->SetAgeLimit(__INT_MAX__);
	this->SetTriggerAge(__INT_MAX__);
	this->SetPosition(0, 0);
	this->SetForce(0, 0);
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

/*
Assigns rocket position with position
of another rocket.
*/
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

/*
Shows character in terminal based on current
rocket position.
*/
void Rocket::Draw()
{
	mvaddch(this->position.y, this->position.x, '*');
	std::this_thread::sleep_for(std::chrono::milliseconds(3));
}

/*
Add force to current position
Subtract Gravity from y force
Graphics can only be used in integers,
	there will be a difference between numerical
	value and where it is drawn because floats
	will be rounded.
*/
void Rocket::Step(std::vector<Rocket *> &v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		(v.at(i))->position.x += (v.at(i))->force.x;
		(v.at(i))->position.y += (v.at(i))->force.y;

		(v.at(i))->force.y -= (v.at(i))->gravity;

		(v.at(i))->age += 1;
	}
}

void Rocket::Trigger(std::vector<Rocket *> &v)
{
	Rocket *r = new Rocket();
	v.push_back(r);
}

int Rocket::GetAge()
{
	return this->age;
}

bool Rocket::IsAlive()
{
	if (this->age <= this->age_limit)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rocket::IsTriggered()
{
	if (this->age == this->trigger_age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Gravity only affects y force
*/
void Rocket::SetGravity(float g)
{
	gravity = g;
}

/*
Rocket is randomnly assigned a rocket type between
Palmtree, Streamer, and Double Streamer.
New rockets of that rocket type are created and added to
a new vector.
The new vector is inserted onto the rockets vector.
Initial rocket pointer is deleted to deallocate memory.
*/
