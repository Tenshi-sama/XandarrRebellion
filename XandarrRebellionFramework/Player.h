#ifndef SRC_PLAYER_H
#define SRC_PLAYER_H

#include "Texture.h"
#include "Window.h"


class Player 
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	Texture sprite_;

public:
	// Ctor and Dtor
	Player() : SPRITE_LOCATION("_resources\\_Player\\PlayerE.png") {};
	~Player(){};

	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
};



#endif