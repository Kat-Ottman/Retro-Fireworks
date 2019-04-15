#include "fleet.hpp"
#include <vector>
#include <ncurses.h>
#include "fw.hpp"
#include "streamer.hpp"
#include "palmtree.hpp"

void Fleet::Cull()
{
	for (size_t i = 0; i < rockets.size(); i++)
	{
		Rocket r = *(rockets.at(i));

		if (!r.IsAlive())
		{
			delete rockets.at(i);
			i -= 1;
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
	}
}

/*
Iterates through vector of rockets to move each rocket.

If rocket is at trigger_age, rocket will trigger into new rockets.

Vector will combine with vector with new triggered rockets.
*/
void Fleet::Step()
{
	std::vector<Rocket *> newRockets;
	Rocket r;

	r.Step(rockets);

	if (r.IsTriggered())
	{
		r.Trigger(newRockets);
	}

	rockets.insert(rockets.end(), newRockets.begin(), newRockets.end());
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
	Rocket *r;

	if (chooseType = 1)
	{
		r = new PalmTree;
	}
	else if (chooseType = 2)
	{
		r = new Streamer;
	}
	else if (chooseType = 3)
	{
		r = new DoubleStreamer;
	}

	//put r.SetTriggerAge(), r.SetLimitAge(), r.SetPosition(), and r.SetForce()

	return r;
}