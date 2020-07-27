
// Alp Bla Whi Red Gre Blu BBr DBr Bei OrF OrC OrJ
//  0   1   2   3   4   5   6   7   8   9   10  11

float COLORS_R[32] = { 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.57f, 0.14f, 0.95f, 0.98f, 0.98f, 0.98f };
float COLORS_G[32] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.3f,  0.11f, 0.95f, 0.08f, 0.5f,  0.75f };
float COLORS_B[32] = { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.16f, 0.07f, 0.85f, 0.05f, 0.05f, 0.05f };
float COLORS_A[32] = { 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f  };

int mario_sprite[16][16] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,1,3,3,3,3,3,3,1,1,0,0,0,0,0},
	{0,1,3,3,3,3,3,3,3,3,3,1,0,0,0,0},
	{0,1,1,1,8,8,1,8,1,1,1,0,0,0,0,0},
	{1,8,8,1,1,8,1,8,8,8,8,1,0,0,0,0},
	{1,8,8,1,1,8,8,1,8,8,8,1,0,0,0,0},
	{0,1,1,8,8,8,1,1,1,1,1,0,0,0,0,0},
	{0,0,1,8,8,8,8,8,8,1,0,0,0,0,0,0},
	{0,1,3,3,1,1,3,3,1,0,0,0,0,0,0,0},
	{1,3,3,3,3,1,1,3,3,1,0,0,0,0,0,0},
	{1,3,3,3,3,1,1,1,1,1,0,0,0,0,0,0},
	{0,1,8,8,8,1,1,8,1,1,0,0,0,0,0,0},
	{0,1,8,8,3,3,3,1,1,1,0,0,0,0,0,0},
	{0,0,1,3,3,3,3,3,1,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
};

int bdf_sprite_1[8][8] = {
		{0,  0,  3,  3,  9,  9,  0, 0},
		{0,  3,  9,  9,  10, 9,  9, 0},
		{3,  9,  10, 11, 10, 10, 9, 0},
		{10, 9,  11, 11, 11, 10, 9, 0},
		{10, 10, 10, 11,  9,  9, 0, 9},
		{10, 11, 10, 10, 10, 10, 0, 0},
		{0,  10, 10, 10, 10, 9,  0, 0},
		{0,  0,  10, 10, 10, 9, 10, 0},
};

int bdf_sprite_2[8][8] = {
		{0, 0,  0,  0,  0,  9,  0, 0},
		{0, 9,  9,  3,  0,  0,  0, 3},
		{9, 9,  9,  9,  3,  0,  3, 10},
		{9, 9,  9,  9,  3,  0,  0, 9},
		{9, 10, 11, 10, 9,  9,  9, 9},
		{9, 11, 11, 11, 10, 10, 9, 0},
		{0, 9,  11, 10, 10, 9,  9, 0},
		{0, 0,  9,  9,  9,  9,  0, 0},
};