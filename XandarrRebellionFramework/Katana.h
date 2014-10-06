#ifndef KATANA_H
#define KATANA_H

#include "Melee.h"

class Katana : public Melee
{
private:
	//const string KATANA_LOCATION;
	//Texture katana_;

public:
	Katana() /*KATANA_LOCATION("_resouces\\katana.png")*/ { setName("Katana"), setAgility(50), setAttackPower(25), setAttackRate(50), setDescription("An old asian sword."), setIsOneHanded(false), setWeight(10), setWorth(250); }
	Katana::~Katana() {}

	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
	//void printInfo();
};

#endif