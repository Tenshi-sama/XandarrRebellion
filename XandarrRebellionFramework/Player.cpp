#include "Player.h"

#define ENEMY_WIDTH 100
#define ENEMY_HEIGHT 100
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800
#define SPRITE_WIDTH 200
#define SPRITE_HEIGHT 200
#define STEP 10

Player::Player() : SPRITE_LOCATION("_resources\\Player2.png"), velX(10), velY(10), MoveRight(false), MoveLeft(false), MoveUp(false), MoveDown(false)
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
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(150);
	sprite_.y(700);
}

// Handles all gameplay events
void Player::HandleEvents(SDL_Event* event) 
{
	static bool movingLeft = true;
	static bool movingUp = true;

	//cout << "Update! ... MovingLeft is: " << movingLeft << endl;
	/*if (movingLeft)
	{
		if (sprite_.x() >= SCREEN_WIDTH - SCREEN_WIDTH)
		{
			MoveLeft(&sprite_);
		}
		else
		{
			movingLeft = false;
		}
	}
	else
	{
		if (sprite_.x() <= SCREEN_WIDTH - ENEMY_WIDTH)
		{
			MoveRight(&sprite_);
		}
		else
		{
			movingLeft = true;
		}
	}
	if (movingUp)
	{
		if (sprite_.x() >= SCREEN_HEIGHT - SCREEN_HEIGHT)
		{
			MoveUp(&sprite_);
		}
		else
		{
			movingUp = false;
		}
	}
	else
	{
		if (sprite_.x() <= SCREEN_HEIGHT - ENEMY_HEIGHT)
		{
			MoveDown(&sprite_);
		}
		else
		{
			movingUp = true;
		}
	}*/
	switch (event->type) 
	{
		case SDL_KEYDOWN:
			// Change States when Escape is pressed
			if (event->key.keysym.sym == SDLK_w) 
			{
				// move functionality for up
				//position_y--;
				MoveUp = true;
			}
			if (event->key.keysym.sym == SDLK_s) 
			{
				// move functionality for down
				MoveDown = true;
			}
			if (event->key.keysym.sym == SDLK_a) 
			{
				// move functionality for left strafe
				MoveLeft = true;
			}
			if (event->key.keysym.sym == SDLK_d) 
			{
				// move functionality for right strafe
				MoveRight = true;
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
			
		case SDL_KEYUP:
			// Change States when Escape is pressed
			if (event->key.keysym.sym == SDLK_w) 
			{
				// move functionality for up
				//position_y--;
				MoveUp = false;
			}
			if (event->key.keysym.sym == SDLK_s) 
			{
				// move functionality for down
				MoveDown = false;
			}
			if (event->key.keysym.sym == SDLK_a) 
			{
				// move functionality for left strafe
				MoveLeft = false;
			}
			if (event->key.keysym.sym == SDLK_d) 
			{
				// move functionality for right strafe
				MoveRight = false;
			}
			break;
	}

	if (MoveRight) {
		if (sprite_.x() <= SCREEN_WIDTH - SPRITE_WIDTH) {
			sprite_.x(sprite_.x() + velX);
			setSpriteLocation("_resources\\PlayerRight");
		}
	} 
	if (MoveLeft) {
		if (sprite_.x() >= SCREEN_WIDTH - SCREEN_WIDTH) {
			sprite_.x(sprite_.x() - velX);
			setSpriteLocation("_resources\\PlayerLeft");
		}
	}
	if (MoveDown) {
		if (sprite_.y() <= SCREEN_HEIGHT - SPRITE_HEIGHT) {
			sprite_.y(sprite_.y() + velY);
			setSpriteLocation("_resources\\PlayerDown");
		}
	}
	if (MoveUp) {
		if (sprite_.y() >= SCREEN_HEIGHT - SCREEN_HEIGHT) {
			sprite_.y(sprite_.y() - velY);
			setSpriteLocation("_resources\\PlayerForward");
		}
	}
}

// From turn five onwards, checks if there has been a winner.
void Player::Update(WindowManager* w) 
{
	SPRITE_LOCATION;
}

void Player::Render(WindowManager* w) 
{

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	sprite_.Draw(w->getRenderer());
}