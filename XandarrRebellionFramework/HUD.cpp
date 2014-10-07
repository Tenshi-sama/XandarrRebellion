#include "HUD.h"

void Barout::Init(SDL_Renderer* r)
{
	sprite_.name("Bars_Outer");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(BarsLocaleX);
	sprite_.y(BarsLocaleY);
}

// Handles all gameplay events
void Barout::HandleEvents(SDL_Event* event)
{
	
	
}

// From turn five onwards, checks if there has been a winner.
void Barout::Update(WindowManager* w)
{

}

void Barout::Render(WindowManager* w)
{

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}

void Healthbarin::Init(SDL_Renderer* r)
{
	sprite_.name("Health_Inner");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(-20);
	sprite_.y(BarsLocaleY);
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

void Item_Box::Init(SDL_Renderer* r)
{
	sprite_.name("Item_Box");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(700);
	sprite_.y(700);
}

// Handles all gameplay events
void Item_Box::HandleEvents(SDL_Event* event)
{


}

// From turn five onwards, checks if there has been a winner.
void Item_Box::Update(WindowManager* w)
{

}

void Item_Box::Render(WindowManager* w)
{

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}

