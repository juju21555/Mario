#pragma once

#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <chrono>
#include <string>

#define SCREEN_WIDTH		640
#define SCREEN_HEIGHT		480
#define SIZE_BY_PIXEL		2
#define MAX_FIREBALLS		16

extern float COLORS_R[32];
extern float COLORS_G[32];
extern float COLORS_B[32];
extern float COLORS_A[32];

extern int bdf_sprite_1[8][8];
extern int brick_sprite[8][8];
extern int mario_sprite[16][16];
extern int koopa_sprite[25][16];

extern unsigned char idxSprite;

enum Sprite {
	None,
	Mario,
	Koopa
};

struct iCouple {
	int x, y;
};

struct fCouple {
	float x, y;
};

