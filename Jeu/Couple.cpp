#include "Couple.h"
#include "iostream"
#include "string"


Couple::Couple(double x, double y)
{
    this->x = x, this->y = y;
}

void Couple::add(Couple c)
{
    this->x += c.x;
    this->y += c.y;
}

void Couple::addMax(Couple c, Couple m)
{
    if (this->x + c.x > m.x)
        this->x = m.x;
    else if (this->x + c.x < -m.x)
        this->x = -m.x;
    else
        this->x += c.x;

    if (this->y + c.y > m.y)
        this->y = m.y;
    else if (this->y + c.y < -m.y)
        this->y = -m.y;
    else
        this->y += c.y;
}

bool Couple::equals(Couple c)
{
    return (this->x == c.x and this->y == c.y);
}

std::string Couple::toString()
{
    return (std::to_string(this->x) + ", " + std::to_string(this->y));
}
