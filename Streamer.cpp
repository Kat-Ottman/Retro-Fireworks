#include "streamer.hpp"
#include "fw.hpp"
#include <thread>
#include <chrono>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

void Streamer::Trigger(vector<Rocket *> &v)
{
	Streamer *s = new Streamer;
	v.push_back(s);
}

void DoubleStreamer::Trigger(vector<Rocket *> &v)
{
	DoubleStreamer *ds = new DoubleStreamer;
	v.push_back(ds);
}