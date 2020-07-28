#include <Game.h>

BouleDeFeu BDFs[16]{ BouleDeFeu() };
extern BouleDeFeu BDFs[16];

Personnage PERs[16]{ Personnage() };
extern Personnage PERs[16];

CorpsRepetition CORs[16]{ CorpsRepetition() };
extern CorpsRepetition CORs[16];

Game::Game(unsigned int width, unsigned int height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
}

Game::~Game()
{

} 

void Game::Init()
{

	PERs[(idxSprite & 0x0F)] = Personnage("Mario", Couple(), Mario);
	idxSprite += 0x01;
	PERs[(idxSprite & 0x0F)] = Personnage("Koopa", Couple(300, 50), Koopa);
	idxSprite += 0x01;

	CORs[0] = CorpsRepetition("brick", Couple(0, 448), 640, 16);
	CORs[1] = CorpsRepetition("brick", Couple(608, 0), 16, 160 );

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
	for (int i = 0; i < 16; i++) { // (idxSprite & 0x0F); i++) {
		PERs[i].update(CORs);
	}
	for (int i = 0; i < 16; i++) { // (idxSprite & 0x0F); i++) {
		PERs[i].update(BDFs);
	}
	for (int i = 0; i < 16; i++) {// (idxSprite >> 4); i++) {
		BDFs[i].update();
		if (BDFs[i].collide(CORs))
			BDFs[i] = BouleDeFeu();
	}
}

void Game::ProcessInput(float dt)
{
	PERs[0].timer++;
	PERs[1].timer++;
	PERs[1].deplacementAuto();
	if (this->Keys[GLFW_KEY_A]) {
		PERs[0].infos = PERs[0].infos & 0xFE;
		PERs[0].impulse(-60, 0);  
	}
	if (this->Keys[GLFW_KEY_D]) {
		PERs[0].infos = PERs[0].infos | 0x01;
		PERs[0].impulse(60, 0);
	}
	if (!(this->Keys[GLFW_KEY_D] ^ this->Keys[GLFW_KEY_A]))  
		PERs[0].imp.x = 0;
	if (this->Keys[GLFW_KEY_SPACE]){
		if (PERs[0].infos & 0x02) {
			PERs[0].impulse(0, -60);
			PERs[0].infos = PERs[0].infos & 0xFD;
		}
		else if (PERs[0].infos & 0x04) {
			PERs[0].imp.x = -60;
			PERs[0].imp.y = -60;
			PERs[0].infos = PERs[0].infos & 0xFB;
		}
		else if (PERs[0].infos & 0x08) {
			PERs[0].imp.x = 60;
			PERs[0].imp.y = -60;
			PERs[0].infos = PERs[0].infos & 0xF7;
		}
	}
	if (this->Keys[GLFW_KEY_W] and PERs[0].timer > 10){ 
		std::cout << "\n" << int(idxSprite >> 4);
		BDFs[(idxSprite >> 4)] = PERs[0].lancerBDF();
		idxSprite = (idxSprite + 0x10);
	}
}

void Game::Render()
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for (int i = 0; i < 16; i++) {//(idxSprite & 0x0F); i++) {
		PERs[i].draw();
	}
	for (int i = 0; i < 16; i++){// (idxSprite >> 4); i++) {
		BDFs[i].draw();
	} 
	CORs[0].draw();
	CORs[1].draw();

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