#pragma once
#include <vector>
#include <utility>
#include "fw.hpp"

class PalmTree : public Rocket
{
  public:
	~PalmTree();

	static std::vector<std::pair<float, float>> v1;

	/*
	Gives birth to particles of palmtree,
	Push_back position x y onto v1
	*/
	virtual void Trigger();
};