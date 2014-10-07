#include "HUD.h"

void Healthbarout::Init(SDL_Renderer* r)
{
	sprite_.name("Health_Outer");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(5);
	sprite_.y(5);
}

// Handles all gameplay events
void Healthbarout::HandleEvents(SDL_Event* event)
{
	
	
}

// From turn five onwards, checks if there has been a winner.
void Healthbarout::Update(WindowManager* w)
{

}

void Healthbarout::Render(WindowManager* w)
{

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}

void Healthbarin::Init(SDL_Renderer* r)
{
	sprite_.name("Health_Inner");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(5);
	sprite_.y(5);
}

// Handles all gameplay events
void Healthbarin::HandleEvents(SDL_Event* event)
{

	switch (event->type)
	{
	case SDL_KEYDOWN:
		
		
		if (event->key.keysym.sym == SDLK_g)
		{
			// lower health
			sprite_.x(sprite_.x() - 10);
		}
		if (event->key.keysym.sym == SDLK_h)
		{
			// raise health
			sprite_.x(sprite_.x() + 10);
		}
		break;
	}

}

// From turn five onwards, checks if there has been a winner.
void Healthbarin::Update(WindowManager* w)
{

}

void Healthbarin::Render(WindowManager* w)
{

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}
