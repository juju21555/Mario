#include <Corps.h>

Corps::Corps(std::string s, Couple pos, iCouple dim)
{
	this->name = s;
	this->pos = pos;
	this->pos_abs = pos;

	this->size = dim;

	this->imp = Couple();
	this->maxImp = Couple(120, 120);
}

void Corps::impulse(double x, double y)
{
	this->imp.addMax(Couple(x, y), this->maxImp);
}
