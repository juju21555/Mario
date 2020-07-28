#pragma once
#include "Corps.h"
#include <properties.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class CorpsRepetition :
    public Corps
{
public:
	CorpsRepetition() : Corps() {};

	CorpsRepetition(std::string s, Couple pos, int x, int y) : Corps(s, pos, iCouple{ x, y }) {};

	void update();
	void draw();

};

