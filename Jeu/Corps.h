#pragma once
#include <Couple.h>
#include <properties.h>

class Corps
{
public:
	Corps() : Corps("noname", Couple(), iCouple{ 0,0 }) {};
	Corps(std::string s, Couple pos, iCouple dim);

	void impulse(double x, double y);

	std::string name;
	iCouple size;
	Couple pos, pos_abs, imp, maxImp;

};

