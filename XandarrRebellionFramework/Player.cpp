#include "Player.h"

Player::Player()
{
	setBaseHealth(200);
	setBaseAttack(10);
	setAgility(5);
	setStrength(5);
	setIntelligence(5);
	setConstitution(5);
	setIsWeaponEquipped(false);
}

void Player::Init(SDL_Renderer* r)
{
	//sprite_.name("Player");
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
				sprite_.y(sprite_.y() - 10);
				Katana* Update();
			}
			if (event->key.keysym.sym == SDLK_s) 
			{
				// move functionality for down
				sprite_.y(sprite_.y() + 10);
			}
			if (event->key.keysym.sym == SDLK_a) 
			{
				// move functionality for left strafe
				sprite_.x(sprite_.x() - 10);
			}
			if (event->key.keysym.sym == SDLK_d) 
			{
				// move functionality for right strafe
				sprite_.x(sprite_.x() + 10);
			}
			if (event->key.keysym.sym == SDLK_SPACE)
			{
				cout << "Space pressed" << endl;
				if (is_weapon_equipped_ == false)
				{
					base_attack_;
				}

				if ((is_weapon_equipped_ == true) && current_weapon_)
				{
					current_weapon_->getAttackPower();
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