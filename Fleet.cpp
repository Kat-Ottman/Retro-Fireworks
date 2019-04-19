#include "fleet.hpp"
#include <vector>
#include <ncurses.h>
#include "fw.hpp"
#include "streamer.hpp"
#include "palmtree.hpp"
#include <list>
#include <iostream>

void Fleet::Cull()
{
	auto it = rockets.begin();

	if (it != rockets.end())
	{
		if (!((*it)->IsAlive()))
		{
			it = rockets.erase(it);
		}
		else
		{
			++it;
		}
	}
}

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
		for (int i = 0; i < birthR; i++)
		{
			Rocket *r = RocketFactory(initial_up_force);
			rockets.push_back(r);
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

	if (r.IsTriggered())
	{
		std::vector<Rocket *> newRockets;

		r.Trigger(newRockets);

		rockets.insert(rockets.end(), newRockets.begin(), newRockets.end());
	}
}

void Fleet::Draw()
{
	for (size_t i = 0; i <= rockets.size(); i++)
	{
		Rocket r = *(rockets.at(i));

		r.Draw();
	}
}

Rocket *Fleet::RocketFactory(float initial_up_force)
{
	int chooseType = rand() % 3;
	Rocket r = Rocket();
	Rocket *pr = &r;

	if ((chooseType = 1))
	{
		pr = new PalmTree;
	}
	else if ((chooseType = 2))
	{
		pr = new Streamer;
	}
	else if ((chooseType = 3))
	{
		pr = new DoubleStreamer;
	}

	r.SetForce(initial_up_force, 4.0 + frand());

	return pr;
}