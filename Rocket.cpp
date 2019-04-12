#include "fw.hpp"
#include <curses.h>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;

float Rocket::gravity = -1.0;
ofstream *Rocket::log_file = nullptr;
vector<Rocket *> *Rocket::rockets = nullptr;

Rocket::Rocket()
{
	//put in main
	srand((unsigned int)time(nullptr));

	//this->SetTriggerAge(int i);
	//this->SetAgeLimit(int i);
	this->SetPosition(rand() % COLS, 0);
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
	mvaddch(this->position.y, this->position.x, 'x');
}

/*
Add force to current position
Subtract Gravity from y force
Graphics can only be used in integers,
	there will be a difference between numerical
	value and where it is drawn because floats
	will be rounded.

*/
void Rocket::Step()
{
	this->age += 1;
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

/*
Print to with debugging output so it will be easier to
read debugging output
Check to see if ofstream exists or not
If not, don't care, don't use
*/
void Rocket::SetLogFile(std::ofstream *log_file)
{
	log_file = log_file;
}
void Rocket::SetVector(std::vector<Rocket *> *rockety)
{
	rockets = rockety;
}
void Rocket::Trigger() {}

int Rocket::GetAge()
{
	return this->age;
}