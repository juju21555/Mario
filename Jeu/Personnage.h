#pragma once
#include "BouleDeFeu.h"
#include "Corps.h"

class Personnage :
    public Corps
{
public:
	Personnage() : Personnage("noname", Couple()) {};
	Personnage(std::string s, Couple pos);

	void update();
	void draw();
	void lancerBDF();


	bool isJumping;
	std::string name;
	int idx_item, time_fireball;
	BouleDeFeu items[MAX_FIREBALLS];
};

