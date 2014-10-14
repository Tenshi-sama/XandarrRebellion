#ifndef SRC_GAMEPLAYSTATE_H
#define SRC_GAMEPLAYSTATE_H

#include "GameState.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
//#include "GameStateManager.h"
#include "Button.h"
#include "Player.h"
#include "Enemy.h"
#include "HUD.h"
#include "Katana.h"
#include "Melee.h"
#include "Level.h"


// Fourth and final GameState of the applicatoin
class GameplayState : public GameState 
{
private:
	//======================//
	//		Properties		//
	//======================//
	Player player_;
	Enemy enemy_;
	Katana katana_;
	Level level_;
	Healthbarout Healthbarout_;
	Healthbarin Healthbarin_;
	
	//The music that will be played
	Mix_Music *gMusic = NULL;
	//The sound effects that will be used 
	Mix_Chunk *gScratch = NULL;
	Mix_Chunk *gHigh = NULL;
	Mix_Chunk *gMedium = NULL;
	Mix_Chunk *gLow = NULL;

	// TODO:
	// REPLACE THIS PROPETY WITH A TEXTURE OBJECT
	//SDL_Texture * ptr_background_texture_;

	// Tracks if a player has met a victory condition.
	bool is_winner_;
	bool success_;
	//======================//
	//		Behaviours		//
	//======================//
	// Reintializes the object (New Game)
	void Reset (WindowManager* w);

public:

	GameplayState() : is_winner_(false) {};

	// Gameplay state initialization method
	virtual void Init(WindowManager* w);

	// Gameplay state event handler method
	virtual void Clean();

	// Gameplay state event handler method
	virtual void HandleEvents(SDL_Event* event);

	// Gameplay state logic update method
	virtual void Update(WindowManager* w);

	// Gameplay state render method
	virtual void Render(WindowManager* w);

	bool collide(Player* a, Enemy* b);
};
 
#endif