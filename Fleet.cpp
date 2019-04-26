#include "fleet.hpp"
#include <vector>
#include <ncurses.h>
#include "fw.hpp"
#include "streamer.hpp"
#include "palmtree.hpp"
#include <list>
#include <iostream>

/*
Erases rocket pointers from rockets vector
if rocket's age exceeds age limit.
*/
void Fleet::Cull()
{
	for (auto it = rockets.begin(); it != rockets.end(); it++)
	{
		if ((*(it))->IsAlive())
		{
			continue;
		}
		else
		{
			delete *it;
			it = rockets.erase(it);
		}
	}
}

/*
Rockets are created and inserted into rockets vector.
*/
void Fleet::Birth(float initial_up_force)
{
	/*
	To keep rockets from birthing too fast,
	mod rand by 100, then say if int 15 or less,
	then birth. else, no.
	*/

	int birthR = rand() % 100;

	if (birthR <= 15)
	{
		for (int i = 0; i < (rand() % 5); i++)
		{
			rockets.push_back(RocketFactory(initial_up_force));
		}
	}
}

/*
Iterates through vector of rockets to move each rocket.

If rocket is at trigger_age, rocket will trigger into new rockets.

Vector will combine with vector with new triggered rockets.
*/
void Fleet::Step()
{
	Rocket r;
	r.Step(rockets);

	for (size_t i = 0; i < rockets.size(); i++)
	{

		if (rockets.at(i)->IsTriggered())
		{

			std::vector<Rocket *> newRockets;

			rockets.at(i)->Trigger(newRockets);

			rockets.insert(rockets.end(), newRockets.begin(), newRockets.end());

			newRockets.clear();
		}
	}
}

/*
Iterates through rockets vector causes each rocket
to be drawn in terminal.
*/
void Fleet::Draw()
{
	for (size_t i = 0; i < rockets.size(); i++)
	{
		rockets.at(i)->Draw();
	}
}

/*
Creates new rocket pointer.

Sets rocket force using function parameter.

Returns rocket pointer.
*/
Rocket *Fleet::RocketFactory(float initial_up_force)
{
	Rocket *pr;
	int chooseType = rand() % 3;

	if ((chooseType = 0))
	{
		pr = new PalmTree;
	}
	else if ((chooseType = 1))
	{
		pr = new Streamer;
	}
	else if ((chooseType = 2))
	{
		pr = new DoubleStreamer;
	}

	(*pr) = Rocket();

	(*pr).SetForce(0, -initial_up_force);
	(*pr).SetTriggerAge(7);
	(*pr).SetAgeLimit(30);
	(*pr).SetPosition(rand() % (COLS - 1), (LINES - 1));
	return pr;
}