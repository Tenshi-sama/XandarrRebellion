#ifndef SRC_GAMEPLAYSTATE_H
#define SRC_GAMEPLAYSTATE_H

#include "GameState.h"
//#include "GameStateManager.h"
#include "Button.h"
#include "Player.h"






// Fourth and final GameState of the applicatoin
class GameplayState : public GameState {
private:
	//======================//
	//		Properties		//
	//======================//
	Player player_;

	// TODO:
	// REPLACE THIS PROPETY WITH A TEXTURE OBJECT
	SDL_Texture * ptr_background_texture_;

	// Tracks if a player has met a victory condition.
	bool is_winner_;

	//======================//
	//		Behaviours		//
	//======================//
	// Reintializes the object (New Game)
	void Reset (WindowManager* w);

public:

	GameplayState() : ptr_background_texture_(nullptr), is_winner_(false) {}

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
};
 
#endif