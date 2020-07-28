#pragma once
#include <properties.h>
#include <Corps.h>
#include <Couple.h>
#include <CorpsRepetition.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class BouleDeFeu :
	public Corps
{
public:
	BouleDeFeu() : Corps() {
		this->frame = 0;
	};

	BouleDeFeu(std::string s, Couple pos) : Corps(s, pos, iCouple{ 8, 8 }) {
		this->frame = 0;
	};
	~BouleDeFeu();

	void update();
	void draw();
	bool collide(CorpsRepetition CORs[16]);

	int frame;
};

