#pragma once
#include <vector>
#include "fw.hpp"

class PalmTree : public Rocket
{
  public:
	/*
  Spawns 8 sparklers
  */
	virtual void Trigger(std::vector<Rocket *> &v);
};