#include "Game.h"

Game::Game(unsigned int width, unsigned int height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
	this->Perso = Personnage("Perso", Couple());
}

Game::~Game()
{

}

void Game::Init()
{

	this->Perso.draw();

	/*
	for (int i = 0; i < 10; i++) {
		n_world.addCorpsSt(*(new CorpsStatique("brique", SDL_LoadBMP("E:\\Downloads\\03_event_driven_programming\\brick.bmp"), i * 40, 440)));
	}

	for (int i = 0; i < 10; i++) {
		n_world.addCorpsSt(*(new CorpsStatique("brique", SDL_LoadBMP("E:\\Downloads\\03_event_driven_programming\\brick.bmp"), 400, 440 - i * 40)));
	}*/

}

void Game::Update(float dt)
{
	this->Perso.update();
}

void Game::ProcessInput(float dt)
{
	this->Perso.time_fireball++;
	if (this->Keys[GLFW_KEY_A])
		this->Perso.impulse(-10, 0);
	if (this->Keys[GLFW_KEY_D])
		this->Perso.impulse(10, 0);
	if (!(this->Keys[GLFW_KEY_D] or this->Keys[GLFW_KEY_A]))
		this->Perso.imp.x = 0;
	if (this->Keys[GLFW_KEY_SPACE] and !this->Perso.isJumping) {
		this->Perso.impulse(0, -60);
		this->Perso.isJumping = true;
	}
	if (this->Keys[GLFW_KEY_W] and this->Perso.time_fireball > 10)
		this->Perso.lancerBDF();
}

void Game::Render()
{


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	this->Perso.draw();

	/*
	glColor3f(0.0f, 1.0f, 1.0f); //blue color
	glBegin(GL_QUADS);//start drawing a line loop
	glVertex2i(0, 0);//left of window
	glVertex2i(100, 0);//right of window
	glVertex2i(100, 100);//top of window
	glVertex2i(0, 100);//bottom of window
	glEnd();//end drawing of line loop
	*/

}