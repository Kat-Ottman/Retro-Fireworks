#pragma once
#include <limits>
#include <vector>
#include <fstream>

float frand();

class Rocket
{
  public:
	Rocket();
	virtual ~Rocket();

	/*
	Must create own function for "birthing a rocket"
	Choose the type of rocket within this function
	Push_back onto vector
	*/

	/*
	Keep in mind with LINE and COLS,
	it is really (y, x)
	*/

	void SetTriggerAge(int i);
	void SetAgeLimit(int i);
	void SetPosition(Rocket &other);
	void SetPosition(float x, float y);
	void SetForce(float x, float y);
	virtual void Draw();
	virtual void Step(std::vector<Rocket *> &v);

	/*
	Call to Trigger every time Step is called to see if
	trigger_age should be implemented and set true if
	right age
	*/
	virtual void Trigger(std::vector<Rocket *> &v);

	int GetAge();
	bool IsAlive();
	bool IsTriggered();

	static void SetGravity(float g);

  protected:
	int age;
	/*
	age_limit and trigger_age should be one number
	randomized by adding a little or subracting a little
	*/
	int age_limit;
	int trigger_age;

	struct
	{
		float x, y;
	} position;

	struct
	{
		float x, y;
	} force;

	static float gravity;
};