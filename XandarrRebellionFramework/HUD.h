#ifndef SRC_HUD_H
#define SRC_HUD_H


#include "Texture.h"
#include "Window.h"

const int BarsLocaleY = 70;
const int BarsLocaleX = 5;


class Barout
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
	Barout() : SPRITE_LOCATION("_resources\\_HUD\\Bars_Outer.png") {};
	~Barout(){};

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

class Item_Box
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
	Item_Box() : SPRITE_LOCATION("_resources\\_HUD\\itembox.png") {};
	~Item_Box(){};

	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
};


#endif