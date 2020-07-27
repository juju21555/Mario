/*
#include <Corps.h>
#include <CorpsStatique.h>
#include <CorpsSprite.h>
#include <Camera.h>
#include <Monde.h>*/

#include <Game.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int argc, char* argcv[])
{	
	glfwInit();
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_RESIZABLE, false);
	*/
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	Breakout.Init();

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	Breakout.State = GAME_MENU;

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		Breakout.ProcessInput(deltaTime);

		Breakout.Update(deltaTime);

		glClearColor(0.57f, 0.30f, 0.16f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Breakout.Render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			Breakout.Keys[key] = true;
		else if (action == GLFW_RELEASE)
			Breakout.Keys[key] = false;
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
/*
//Screen dimension constants

int c_x;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

void game();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gXOut = SDL_LoadBMP( "E:\\Downloads\\03_event_driven_programming\\x.bmp" );
	if( gXOut == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gXOut );
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void game()
{

	Personnage perso("Perso", SDL_LoadBMP("E:\\Downloads\\03_event_driven_programming\\mario.bmp"), 0, 140, 0);
	Camera camera(SCREEN_WIDTH, SCREEN_HEIGHT, perso, gScreenSurface);

	Monde n_world;

	for (int i = 0; i < 10; i++) {
		n_world.addCorpsSt(*(new CorpsStatique("brique", SDL_LoadBMP("E:\\Downloads\\03_event_driven_programming\\brick.bmp"), i * 40, 440)));
	}

	for (int i = 0; i < 10; i++) {
		n_world.addCorpsSt(*(new CorpsStatique("brique", SDL_LoadBMP("E:\\Downloads\\03_event_driven_programming\\brick.bmp"), 400, 440-i*40)));
	}
	auto t1 = high_resolution_clock::now();

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	char key;

	//While application is running
	while (!quit){

		auto t2 = high_resolution_clock::now();

		if (duration_cast<milliseconds>(t2-t1).count() > 1) {

			t1 = high_resolution_clock::now();

			while (SDL_PollEvent(&e)) {
				switch (e.type) {
				case SDL_KEYUP:
					switch ((unsigned int)e.key.keysym.sym) {
					case 113: // Q
						printf("Q");
						perso.imp.x = 0;
						break;
					case 100: // D
						printf("D");
						perso.imp.x = 0;
						break;
					default:
						break;
					}
					break;

				case SDL_KEYDOWN:
					switch ((unsigned int)e.key.keysym.sym) {
					case 113: // Q
						printf("Q");
						perso.impulse(-20.0, 0);
						break;
					case 122: // Z
						printf("Z");
						n_world.addCorpsSp(perso.lancerBDF());
						break;
					case 100: // D
						printf("D");
						perso.impulse(20.0, 0);
						break;
					case 115: // S
						printf("S");
						break;
					case 32: // SPACE
						printf("SPACE");
						if (!perso.isJumping) {
							perso.impulse(0, -60.0);
							perso.isJumping = true;
						}
						break;
					default:
						break;
					}
					break;

				case SDL_QUIT:
					printf("\nQ");
					quit = true;
					break;

				default:
					break;
				}
			}

			camera.draw(n_world);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
		}
	}
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			game();
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}*/