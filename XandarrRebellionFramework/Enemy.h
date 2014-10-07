#ifndef SRC_ENEMY_H
#define SRC_ENEMY_H

#include "Texture.h"
#include "Window.h"


class Enemy 
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	Texture sprite_;
	int width; 
	int height;

public:
	// Ctor and Dtor
	Enemy() : SPRITE_LOCATION("_resources\\enemy.png") {};
	~Enemy(){};

	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	//void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
	void MoveLeft(Texture *theSprite);
	void MoveRight(Texture *theSprite);
};

#endif