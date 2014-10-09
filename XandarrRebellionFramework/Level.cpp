#include "Level.h"

Level::Level()
{

}

void Level::Init(SDL_Renderer* r)
{
	level_.LoadTexture(r, LEVEL_LOCATION);
	level_.x(0);
	level_.y(0);
}

// From turn five onwards, checks if there has been a winner.
void Level::Update(WindowManager* w)
{
	//if (Player* SPRITE_LOCATION)
}

void Level::Render(WindowManager* w)
{
	level_.Draw(w->getRenderer());
}