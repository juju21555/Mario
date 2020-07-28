#include <Personnage.h>

Personnage::Personnage(std::string s, Couple pos, Sprite sp) {
	this->name = s;
	this->pos = pos;
	this->pos_abs = pos;
	this->infos = 0x02;

	switch (sp) {
	case Mario:
		{
		this->size = iCouple{ 16, 16 };
		}
		break;
	case Koopa:
		{
		this->size = iCouple{ 16, 25 };
		}
		break;
	default:
		this->size = iCouple{ 0, 0 };
		break;
	}

	this->sprite = sp;

	this->imp = Couple();
	this->maxImp = Couple(60, 60);

	this->idx_item = 0;
	this->timer = 0;
}

void Personnage::draw()
{
	float r, g, b, a;
	int i=0;
	for (int x = 0; x < this->size.x; x++) {
		for (int y = 0; y < this->size.y; y++) {
			switch (this->sprite) {
			case Mario:
				if (this->infos & 0x01)
					i = mario_sprite[y][x];
				else
					i = mario_sprite[y][15-x];
				break;
			case Koopa:
				if (this->infos & 0x01)
					i = koopa_sprite[y][x];
				else
					i = koopa_sprite[y][15-x];
				break;
			default:
				break;
			}
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

void Personnage::update(CorpsRepetition CORs[16]) 
{
	bool collide = false, r_x, r_y, r_u, r_d, r_l, r_r;
	for (int i = 0; i < 2; i++) {
		r_d = CORs[i].pos.y + CORs[i].size.y * 2 >= this->pos.y + this->imp.y / 10.0;
		r_u = CORs[i].pos.y <= this->pos.y + this->size.y * 2 + this->imp.y / 10.0;
		r_l = CORs[i].pos.x + CORs[i].size.x * 2 >= this->pos.x + this->imp.x / 10.0;
		r_r = CORs[i].pos.x <= this->pos.x + this->size.x * 2 + this->imp.x / 10.0;

		if (r_d && r_u && r_l && r_r) {
			if (this->imp.x > 0 && (this->pos.x + this->size.x - CORs[i].pos.x) < 0) {
				this->imp.x = 0;
				this->infos |= 0x04;
			}
			if (this->imp.x < 0 && (this->pos.x - CORs[i].pos.x - CORs[i].size.x) > 0) {
				this->imp.x = 0;
				this->infos |= 0x08;
			}
			if (this->imp.y > 0 && (this->pos.y + this->size.y - CORs[i].pos.y) < 0) {
				this->imp.y = 0;
				this->infos |= 0x02;
			}
			if (this->imp.y < 0 && (this->pos.y - CORs[i].pos.y - CORs[i].size.y) > 0) {
				this->imp.y = 0;
			}
		}

		collide |= (r_u && r_d && r_l && r_r);
	}

	this->pos.x += this->imp.x / 10.0;
	this->pos_abs.x += this->imp.x / 10.0;
	this->pos.y += this->imp.y / 10.0;
	this->pos_abs.y += this->imp.y / 10.0;



	if ((this->pos.x < SCREEN_WIDTH * 0.2 and this->pos_abs.x > SCREEN_WIDTH * 0.2)) {
		this->imp.x = 0;
	}

	if (this->pos.y + this->size.y * SIZE_BY_PIXEL < SCREEN_HEIGHT) {
		this->imp.y += 1;
	}
	else {
		this->imp.y = 0;
		this->infos = this->infos | 0x02;
	}

}

void Personnage::update(BouleDeFeu BDFs[16])
{
	if (this->name[0] != 'M') {
		bool collide = false, r_x, r_y, r_u, r_d, r_l, r_r;
		for (int i = 0; i < 16; i++) {
			r_d = BDFs[i].pos.y + BDFs[i].size.y * 2 >= this->pos.y;
			r_u = BDFs[i].pos.y <= this->pos.y + this->size.y * 2;
			r_l = BDFs[i].pos.x + BDFs[i].size.x * 2 >= this->pos.x;
			r_r = BDFs[i].pos.x <= this->pos.x + this->size.x * 2;
			collide |= (r_u && r_d && r_l && r_r);
		}

		if (collide) {
			this->impulse(0, -60);
		}
	}
}

void Personnage::deplacementAuto()
{
	if (this->timer < 100) {
		this->infos = this->infos | 0x01;
		this->imp.x = 10;

	}
	else if (this->timer < 200) {
		this->infos = this->infos & 0xFE;
		this->imp.x = -10;
	}
	else
		this->timer = 0;
	
}

BouleDeFeu Personnage::lancerBDF()
{
	BouleDeFeu bdf("bdf", this->pos);
	if (this->infos & 0x01) {
		bdf.pos.x += 40;
		bdf.impulse(this->imp.x + 80, this->imp.y + 40);
	}
	else {
		bdf.pos.x -= 40;
		bdf.impulse(this->imp.x - 80, this->imp.y + 40);
	}
	this->timer = 0;
	return bdf;
}