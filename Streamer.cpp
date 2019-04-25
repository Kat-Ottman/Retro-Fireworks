#include "streamer.hpp"
#include "fw.hpp"
#include "sparkler.hpp"
#include <thread>
#include <chrono>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

void Streamer::Trigger(vector<Rocket *> &v)
{
	for (int i = 1; i <= 8; i++)
	{
		Sparkler *s = new Sparkler;

		v.push_back(s);
	}
}

void DoubleStreamer::Trigger(vector<Rocket *> &v)
{
	DoubleStreamer *ds = new DoubleStreamer;
	v.push_back(ds);
}