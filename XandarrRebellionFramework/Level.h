#ifndef SRC_LEVEL_H
#define SRC_LEVEL_H

#include "Texture.h"
#include "Window.h"
#include "Katana.h"
#include "Melee.h"
#include "Player.h"


class Level
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string LEVEL_LOCATION = "_resources\\Winhill_6.png";
	Texture level_;

public:
	Level();
	~Level(){};

	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
};

#endif