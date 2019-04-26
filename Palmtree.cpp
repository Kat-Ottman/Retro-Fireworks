#include "palmtree.hpp"
#include <vector>
#include "sparkler.hpp"

void PalmTree::Trigger(std::vector<Rocket *> &v)
{
	for (int i = 0; i < 8; i++)
	{
		Sparkler *s = new Sparkler;
		s->SetForce(this->force.x + frand(), this->force.y - 1);
		s->SetPosition(this->position.x, this->position.y);
		v.push_back(s);
	}
}