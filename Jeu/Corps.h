#pragma once
#include <string>
#include <Couple.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "properties.h"

class Corps
{
public:
	Corps() : Corps("noname", Couple(), Couple()) {};
	Corps(std::string s, Couple pos, Couple dim);

	void impulse(double x, double y);

	std::string name;
	Couple pos, pos_abs, size, imp, maxImp;

};

