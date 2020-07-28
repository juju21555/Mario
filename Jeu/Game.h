#ifndef GAME_H
#define GAME_H

#include <properties.h>
#include <Personnage.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game
{
public:
    GameState               State;
    Personnage              Perso, Mechant;
    bool                    Keys[1024];
    unsigned int            Width, Height;
    Game(unsigned int width, unsigned int height);
    ~Game();

    void Init();
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};

#endif