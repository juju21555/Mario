#pragma once
#include <string>

class Couple
{
public:

	Couple() : Couple(0, 0) {};
	Couple(double x, double y);

	void add(Couple c);
	void addMax(Couple c, Couple m);

	bool equals(Couple c);
	std::string toString();

	double x, y;

};

