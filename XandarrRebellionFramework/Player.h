#ifndef SRC_PLAYER_H
#define SRC_PLAYER_H

#include "Texture.h"
#include "Window.h"
#include "Katana.h"
#include "Melee.h"


class Player 
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION = "_resources\\PlayerForward.png";
	Texture sprite_;

	unsigned short base_health_;
	unsigned short base_attack_;
	unsigned short agility_;
	unsigned short strength_;
	unsigned short intelligence_;
	unsigned short constitution_;
	bool is_weapon_equipped_;
	Melee* current_weapon_;

public:
	// Ctor and Dtor
	Player();
	~Player(){};

	inline unsigned short getBaseHealth() const { return base_health_; }
	inline unsigned short getBaseAttack() const { return base_attack_; }
	inline unsigned short getAgility() const { return agility_; }
	inline unsigned short getStrength() const { return strength_; }
	inline unsigned short getIntelligence() const { return intelligence_; }
	inline unsigned short getConstitution() const { return constitution_; }
	inline bool getIsWeaponEquipped() const { return is_weapon_equipped_; }
	inline Melee* getCurrentWeapon() const { return current_weapon_; }
	inline string getSpriteLocation() const { return SPRITE_LOCATION; }

	inline void setBaseHealth(const unsigned short newValue) { base_health_ = newValue; }
	inline void setBaseAttack(const unsigned short newValue) { base_attack_ = newValue; }
	inline void setAgility(const unsigned short newValue) { agility_ = newValue; }
	inline void setStrength(const unsigned short newValue) { strength_ = newValue; }
	inline void setIntelligence(const unsigned short newValue) { intelligence_ = newValue; }
	inline void setConstitution(const unsigned short newValue) { constitution_ = newValue; }
	inline void setIsWeaponEquipped(const bool newValue) { is_weapon_equipped_ = newValue; }
	inline void setCurrentWeapon(Melee* newValue) { current_weapon_ = newValue; }
	inline void setSpriteLocation(const string newValue) { SPRITE_LOCATION == newValue; }


	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
	void MoveLeft(Texture *theSprite);
	void MoveRight(Texture *theSprite);
	void MoveUp(Texture *theSprite);
	void MoveDown(Texture *theSprite);
};

#endif