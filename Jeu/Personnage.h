#pragma once
#include <properties.h>
#include <Corps.h>
#include <Couple.h>
#include <BouleDeFeu.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Personnage :
    public Corps
{
public:
	Personnage() : Personnage("noname", Couple(), None) {};
	Personnage(std::string s, Couple pos, Sprite sp);

	void update(CorpsRepetition CORs[16]);
	void update(BouleDeFeu BDFs[16]);
	void draw();
	BouleDeFeu lancerBDF();
	void deplacementAuto();

	char infos;
	std::string name;
	Sprite sprite;
	int idx_item, timer;
};
