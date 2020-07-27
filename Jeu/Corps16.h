#pragma once
#include <Corps8.h>

class Corps16
{
public:
	Corps16() : Corps16("noname", Couple()) {};
	Corps16(std::string s, Couple pos);

	void setSprite(int sprite[16][16]);
	void update();
	void draw();
	void impulse(double x, double y);
	void lancerBDF();


	bool isJumping;
	std::string name;
	int sprite[16][16], idx_item;
	int time_fireball;
	Corps8 items[MAX_FIREBALLS];
	Couple pos, pos_abs, size, imp, maxImp;

};
