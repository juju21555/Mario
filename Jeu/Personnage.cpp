#include "Personnage.h"
#include "iostream"



Personnage::Personnage(std::string s, Couple pos) {
	this->name = s;
	this->pos = pos;
	this->pos_abs = pos;

	this->size = Couple(16, 16);

	this->imp = Couple();
	this->maxImp = Couple(60, 60);

	this->idx_item = 0;
	this->time_fireball = 0;

	this->isJumping = false;
}

void Personnage::draw()
{
	float r, g, b, a;
	int i;
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			i = mario_sprite[y][x];
			r = COLORS_R[i];
			g = COLORS_G[i];
			b = COLORS_B[i];
			a = COLORS_A[i];
			glColor4f(r, g, b, a);
			glBegin(GL_QUADS);
			glVertex2i(SIZE_BY_PIXEL * x + this->pos.x, SIZE_BY_PIXEL * y + this->pos.y);
			glVertex2i(SIZE_BY_PIXEL * x + SIZE_BY_PIXEL + this->pos.x, SIZE_BY_PIXEL * y + this->pos.y);
			glVertex2i(SIZE_BY_PIXEL * x + SIZE_BY_PIXEL + this->pos.x, SIZE_BY_PIXEL * y + SIZE_BY_PIXEL + this->pos.y);
			glVertex2i(SIZE_BY_PIXEL * x + this->pos.x, SIZE_BY_PIXEL * y + SIZE_BY_PIXEL + this->pos.y);
			glEnd();
		}
	}
	for (int i = 0; i < this->idx_item and i < MAX_FIREBALLS; i++)
		this->items[i].draw();
}

void Personnage::update() {

	this->pos.x += this->imp.x / 10.0;
	this->pos.y += this->imp.y / 10.0;

	if (this->pos.x < SCREEN_WIDTH * 0.2) {

	}

	if (this->pos.y + this->size.y * SIZE_BY_PIXEL <= SCREEN_HEIGHT)
		this->imp.y += 1;
	else {
		this->imp.y = 0;
		this->isJumping = false;
	}

	for (int i = 0; i < this->idx_item and i < MAX_FIREBALLS; i++)
		this->items[i].update();
}

void Personnage::lancerBDF()
{
	BouleDeFeu bdf("bdf", this->pos);
	bdf.impulse(this->imp.x + 80, this->imp.y + 40);
	this->items[(this->idx_item++) % MAX_FIREBALLS] = bdf;
	this->time_fireball = 0;
}