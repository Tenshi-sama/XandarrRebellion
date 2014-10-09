#ifndef SRC_HUD_H
#define SRC_HUD_H


#include "Texture.h"
#include "Window.h"

class Healthbarout
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	Texture sprite_;

public:
	// Ctor and Dtor
	//HUD() : SPRITE_LOCATION("_resources\\Health_Outer.png") {};
	Healthbarout() : SPRITE_LOCATION("_resources\\_HUD\\Health_Outer.png") {};
	~Healthbarout(){};

	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
};

class Healthbarin
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	Texture sprite_;

public:
	// Ctor and Dtor
	//HUD() : SPRITE_LOCATION("_resources\\Health_Outer.png") {};
	Healthbarin() : SPRITE_LOCATION("_resources\\_HUD\\Health_Inner.png") {};
	~Healthbarin(){};

	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
};


#endif