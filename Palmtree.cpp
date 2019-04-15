#include "palmtree.hpp"
#include <vector>

void PalmTree::Trigger(std::vector<Rocket *> &v)
{
	PalmTree *p = new PalmTree;
	v.push_back(p);
}