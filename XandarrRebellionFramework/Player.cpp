#include "Player.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800
#define SPRITE_WIDTH 200
#define SPRITE_HEIGHT 200

void Player::Init(SDL_Renderer* r)
{
	sprite_.name("Player");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(0);
	sprite_.y(0);
}

// Handles all gameplay events
void Player::HandleEvents(SDL_Event* event) 
{
	switch (event->type) 
	{
		case SDL_KEYDOWN:
			// Change States when Escape is pressed
			if (event->key.keysym.sym == SDLK_w) 
			{
				// move functionality for up
				//position_y--;
				if (sprite_.y() >= SCREEN_HEIGHT - SCREEN_HEIGHT) {
					sprite_.y(sprite_.y() - vel);
				}
			}
			if (event->key.keysym.sym == SDLK_s) 
			{
				// move functionality for down
				if (sprite_.y() <= SCREEN_HEIGHT - SPRITE_HEIGHT) {
					sprite_.y(sprite_.y() + vel);
				}
			}
			if (event->key.keysym.sym == SDLK_a) 
			{
				// move functionality for left strafe
				if (sprite_.x() >= SCREEN_WIDTH - SCREEN_WIDTH) {
					sprite_.x(sprite_.x() - vel);
				}
			}
			if (event->key.keysym.sym == SDLK_d) 
			{
				// move functionality for right strafe
				if (sprite_.x() <= SCREEN_WIDTH - SPRITE_WIDTH) {
					sprite_.x(sprite_.x() + vel);
				}
			}
			break;
	}
}

// From turn five onwards, checks if there has been a winner.
void Player::Update(WindowManager* w) 
{

}

void Player::Render(WindowManager* w) 
{

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}