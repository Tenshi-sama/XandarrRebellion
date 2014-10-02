#include "GameplayState.h"

// Creates a new instance of Board and OutputPanel and loads the requisite
// resources for the Gameplay State.
void GameplayState::Init(WindowManager* w) {
	cout << "|-->GameplayState::Init() Invoked" << endl;

	ptr_background_texture_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\map.png");

	string str = "New Game!";
	string str2 = "Main Menu";

	SDL_Color buttonColor = {0, 255, 0, 255};

	// Create Buttons
	new_game_btn_ = new Button(w->getRenderer(), str, buttonColor, 28);
	exit_game_btn_ = new Button(w->getRenderer(), str2, buttonColor, 28);

	// Sets the x & y properties of Buttons
	new_game_btn_->setPosition(25, 550);
	exit_game_btn_->setPosition(425, 550);
}

void GameplayState::Clean() {
	cout << "|-->GameplayState::Clean() Invoked" << endl;

	RenderingEngine::DestroyTexture(ptr_background_texture_);
	
	delete new_game_btn_;
	delete exit_game_btn_;

	is_winner_ = false;
	current_player_ = PLAYER_TYPE_X;
}

// Handles all gameplay events
void GameplayState::HandleEvents(SDL_Event* event) {
	new_game_btn_->HandleEvents(event);
	exit_game_btn_->HandleEvents(event);

	switch (event->type) {
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.button == SDL_BUTTON_LEFT) {
				cout << "|--> Mouse Click(" << event->button.x << ", " << event->button.y << ") | Current State: GameplayState" << endl;

				OnLeftBtnDown(event->button.x, event->button.y);
			}
			break;
/*
		case SDL_KEYDOWN:
			// Change States when Escape is pressed
			if (event->key.keysym.sym == SDLK_ESCAPE) {
				//GameStateManager::setCurrentState(GAMESTATE_PAUSE);
				//PauseState::PauseState();
			}
			break;*/
	}
}

// From turn five onwards, checks if there has been a winner.
void GameplayState::Update(WindowManager* w) {

	// If there is a winner
	if (is_winner_) {
		// If the New Game Button is in CLICKED state
		if (new_game_btn_->getState() == CLICKED) {
			// Reset this object (New Game)
			Reset(w);
			return;
		}

		if (exit_game_btn_->getState() == CLICKED) {
			GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
		}
	}
}

void GameplayState::Render(WindowManager* w) {

	// Buttons
	if (is_winner_) {
		//
		RenderingEngine::DrawTexture(w->getRenderer(), new_game_btn_->getTexture(), new_game_btn_->getBoundingBox().x, new_game_btn_->getBoundingBox().y);

		//
		RenderingEngine::DrawTexture(w->getRenderer(), exit_game_btn_->getTexture(), exit_game_btn_->getBoundingBox().x, exit_game_btn_->getBoundingBox().y);
	}

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	RenderingEngine::DrawTexture(w->getRenderer(), ptr_background_texture_, 0, 0);
}

void GameplayState::OnLeftBtnDown(int mX, int mY) {
	// Convert mouse click coordinates to a grid_ element
	int ID = int (((mX/200) + (mY/200) * 3));

	if (current_player_ == PLAYER_TYPE_X) {
		current_player_ = PLAYER_TYPE_O;
	} else {
		current_player_ = PLAYER_TYPE_X;
	}
}

//
void GameplayState::Reset(WindowManager* w) {
	cout << "|-->GameplayState::Reset() Invoked" << endl;

	is_winner_ = false;
	current_player_ = PLAYER_TYPE_X;
}