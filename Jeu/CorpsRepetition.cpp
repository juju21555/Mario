#include "CorpsRepetition.h"

void CorpsRepetition::update()
{

}

void CorpsRepetition::draw()
{
	float r, g, b, a;
	int i;
	for (int x = 0; x < this->size.x; x++) {
		for (int y = 0; y < this->size.y; y++) {
			i = brick_sprite[y%8][x%8];
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
