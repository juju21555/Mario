#include <BouleDeFeu.h>

BouleDeFeu::~BouleDeFeu()
{
}

void BouleDeFeu::update()
{	
	if (this->imp.x < 0.01)
		this->imp.x;

	if (this->imp.y < 0.01)
		this->imp.y;
		
	this->pos.x += this->imp.x / 10.0;
	this->pos.y += this->imp.y / 10.0;


}

void BouleDeFeu::draw()
{
	float r, g, b, a;
	int i;
	for (int x = 0; x < this->size.x; x++) {
		for (int y = 0; y < this->size.y; y++) {
			switch (this->frame/5) {
			case 1:
				i = bdf_sprite_1[7-y][x];
				break;
			case 2:
				i = bdf_sprite_1[7-y][7-x];
				break;
			case 3:
				i = bdf_sprite_1[y][7-x];
				break;
			default:
				i = bdf_sprite_1[y][x];
				break;
			}
			r = COLORS_R[i];
			g = COLORS_G[i];
			b = COLORS_B[i];
			a = COLORS_A[i];
			glColor4f(r, g, b, a);
			glBegin(GL_QUADS);
			glVertex2i(SIZE_BY_PIXEL * x + this->pos.x,					SIZE_BY_PIXEL * y + this->pos.y);
			glVertex2i(SIZE_BY_PIXEL * x + SIZE_BY_PIXEL + this->pos.x, SIZE_BY_PIXEL * y + this->pos.y);
			glVertex2i(SIZE_BY_PIXEL * x + SIZE_BY_PIXEL + this->pos.x, SIZE_BY_PIXEL * y + SIZE_BY_PIXEL + this->pos.y);
			glVertex2i(SIZE_BY_PIXEL * x + this->pos.x,					SIZE_BY_PIXEL * y + SIZE_BY_PIXEL + this->pos.y);
			glEnd();
		}
	}
	this->frame = (this->frame + 1) % 20;
}

bool BouleDeFeu::collide(CorpsRepetition CORs[16])
{
	bool collide = false, r_u, r_d, r_l, r_r;
	for (int i = 0; i < 2; i++) {
		r_d = CORs[i].pos.y + CORs[i].size.y * 2 >= this->pos.y + this->imp.y / 10.0;
		r_u = CORs[i].pos.y <= this->pos.y + this->size.y * 2 + this->imp.y / 10.0;
		r_l = CORs[i].pos.x + CORs[i].size.x * 2 >= this->pos.x + this->imp.x / 10.0;
		r_r = CORs[i].pos.x <= this->pos.x + this->size.x * 2 + this->imp.x / 10.0;

		if (r_d && r_u && r_l && r_r) {
			if (this->imp.x > 0 && (this->pos.x + this->size.x - CORs[i].pos.x) < 0) {
				this->imp.x *= -0.9;
				std::cout << "\nFFF" << this->imp.x;
			}
			if (this->imp.x < 0 && (this->pos.x - CORs[i].pos.x - CORs[i].size.x) > 0) {
				this->imp.x *= -0.9;
				std::cout << "\nFF" << this->imp.x;
			}
			if (this->imp.y > 0 && (this->pos.y + this->size.y - CORs[i].pos.y) < 0)
				this->imp.y *= -0.8;
			if (this->imp.y < 0 && (this->pos.y - CORs[i].pos.y - CORs[i].size.y) > 0)
				this->imp.y *= -0.8;
		}
		//collide |= (r_u && r_d && r_l && r_r);
	}
	return collide;
}

