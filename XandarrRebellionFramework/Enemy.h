#ifndef SRC_ENEMY_H
#define SRC_ENEMY_H

#include "Texture.h"
#include "Window.h"


class Enemy 
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	Texture sprite_;
	int width; 
	int height;
	unsigned short base_health_;
	unsigned short base_attack_;

public:
	// Ctor and Dtor
	Enemy();
	~Enemy(){};

	inline unsigned short getBaseHealth() const { return base_health_; }
	inline unsigned short getBaseAttack() const { return base_attack_; }

	inline void setBaseHealth(const unsigned short newValue) { base_health_ = newValue; }
	inline void setBaseAttack(const unsigned short newValue) { base_attack_ = newValue; }

	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	//void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
	void MoveLeft(Texture *theSprite);
	void MoveRight(Texture *theSprite);

	bool Moving(bool);

	inline int getXPos() { return sprite_.x(); }
	inline int getYPos() { return sprite_.y(); }
	inline int getWidth() { return sprite_.width(); }
	inline int getHeight() { return sprite_.height(); }

	inline void setXPos() { sprite_.x(); }
	inline void setYPos() { sprite_.y(); }
	inline void setWidth() { sprite_.width(); }
	inline void setHeight() { sprite_.height(); }
};

#endif