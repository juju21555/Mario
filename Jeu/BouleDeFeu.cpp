#include "BouleDeFeu.h"
#include "iostream"


void BouleDeFeu::update()
{
	if (this->imp.x < 0.01)
		this->imp.x;

	if (this->imp.y < 0.01)
		this->imp.y;

	this->pos.x += this->imp.x / 10.0;
	this->pos.y += this->imp.y / 10.0;

	if (this->pos.y + this->size.y * SIZE_BY_PIXEL <= SCREEN_HEIGHT)
		this->imp.y += 1;
	else {
		this->imp.y *= -0.8;
		this->imp.x *= 0.9;
	}
}

void BouleDeFeu::draw()
{
	float r, g, b, a;
	int i;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			i = bdf_sprite_1[y][x];
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
}

