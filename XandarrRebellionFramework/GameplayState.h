#ifndef SRC_GAMEPLAYSTATE_H
#define SRC_GAMEPLAYSTATE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Button.h"
//#include "PauseState.h"

// Simple way to tell players apart
enum PlayerType {
	// Player 1 (X)
	PLAYER_TYPE_X = 0,

	// Player 2 (O)
	PLAYER_TYPE_O
};

// Fourth and final GameState of the applicatoin
class GameplayState : public GameState {
private:
	//======================//
	//		Properties		//
	//======================//

	// Loading screen image
	SDL_Texture * ptr_background_texture_;

	// New Game Button
	Button* new_game_btn_;

	// Exit Game Button
	Button* exit_game_btn_;

	// Tracks if a player has met a victory condition.
	bool is_winner_;

	// Tracks whose turn it is (O or X)
	PlayerType current_player_;

	// Method for handleing mouse clicks
	void OnLeftBtnDown(int mX, int mY);

	// Reintializes the object (New Game)
	void Reset (WindowManager* w);

public:
	//======================//
	//		Behaviours		//
	//======================//

	GameplayState() : ptr_background_texture_(nullptr), new_game_btn_(nullptr), exit_game_btn_(nullptr), is_winner_(false), current_player_(PLAYER_TYPE_X) {}

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