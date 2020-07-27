#pragma once
#include <string>
#include <Couple.h>
#include <Corps.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "properties.h"

class BouleDeFeu :
	public Corps
{
public:
	BouleDeFeu() : Corps("noname", Couple(), Couple(8,8)) {};
	BouleDeFeu(std::string s, Couple pos) : Corps(s, pos, Couple(8, 8)) {};

	void update();
	void draw();
};

