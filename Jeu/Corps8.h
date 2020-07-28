#pragma once
#include <Couple.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <properties.h>

class Corps8
{
public:
	Corps8() : Corps8("noname", Couple()) {};
	Corps8(std::string s, Couple pos);

	void setSprite(int sprite[8][8]);
	void update();
	void draw();
	void impulse(double x, double y);

	std::string name;
	int sprite[8][8];
	Couple pos, pos_abs, size, imp, maxImp;
};

