#include <Corps8.h>


Corps8::Corps8(std::string s, Couple pos)
{
	this->name = s;
	this->pos = pos;
	this->pos_abs = pos;

	this->size = Couple(8, 8);

	this->imp = Couple();
	this->maxImp = Couple(120, 120);
}

void Corps8::setSprite(int sprite[8][8])
{
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			this->sprite[x][y] = sprite[x][y];
		}
	}
}

void Corps8::update()
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

void Corps8::draw()
{
	float r, g, b, a;
	int i;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			i = this->sprite[y][x];
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

void Corps8::impulse(double x, double y)
{
	this->imp.addMax(Couple(x, y), this->maxImp);
}
