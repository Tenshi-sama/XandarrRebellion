#include "Enemy.h"

#define SCREEN_WIDTH 600
#define ENEMY_WIDTH 200 
#define STEP 10

Enemy::Enemy()
{
	setBaseHealth(100);
	setBaseAttack(25);
}

void Enemy::Init(SDL_Renderer* r)
{
	//sprite_.name("Player");
	sprite_.LoadTexture(r, SPRITE_LOCATION);
	sprite_.x(400);
	sprite_.y(600);
}

// Handles all gameplay events


void Enemy::MoveLeft(Texture *theSprite) {
	theSprite->x(theSprite->x() - STEP);
}


void Enemy::MoveRight(Texture *theSprite) {
	theSprite->x(theSprite->x() + STEP);
}

// From turn five onwards, checks if there has been a winner.
void Enemy::Update(WindowManager* w)
{
	static bool movingLeft = true;

	//cout << "Update! ... MovingLeft is: " << movingLeft << endl;
	if (movingLeft)
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
}





void Enemy::Render(WindowManager* w) 
{

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	//sprite_.Draw(w->getRenderer());
}