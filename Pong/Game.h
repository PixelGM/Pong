#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include <string>
#include <fstream>
#include <iostream>	

struct Vector2
{
	float x;
	float y;
};

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
	void RenderText(int, int, int);
	void saveText(int number, const std::string& filename);
	int loadText(const std::string& filename);
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	int score;
	int higherScore;
	TTF_Font* mFont;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	
	bool mIsRunning;
	int mPaddleDir;
	Vector2 mPaddlePos;
	Vector2 mBallPos;
	Vector2 mBallVel;
};