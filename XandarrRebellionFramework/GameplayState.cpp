#include "GameplayState.h"

// Creates a new instance of Board and OutputPanel and loads the requisite
// resources for the Gameplay State.
void GameplayState::Init(WindowManager* w) 
{
	
	cout << "|-->GameplayState::Init() Invoked" << endl;

	ptr_background_texture_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\map.png");
	
	player_.Init(w->getRenderer());
	enemy_.Init(w->getRenderer());
	Healthbarin_.Init(w->getRenderer());
	Healthbarout_.Init(w->getRenderer());

}

void GameplayState::Clean() 
{
	cout << "|-->GameplayState::Clean() Invoked" << endl;

	RenderingEngine::DestroyTexture(ptr_background_texture_);
	is_winner_ = false;

}

// Handles all gameplay events
void GameplayState::HandleEvents(SDL_Event* event) 
{
	
	player_.HandleEvents(event); //Player events
	//enemy_.HandleEvents(event);

	switch (event->type) 
	{
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.button == SDL_BUTTON_LEFT) 
			{
				cout << "|--> Mouse Click(" << event->button.x << ", " << event->button.y << ") | Current State: GameplayState" << endl;

			}
			break;
	}
}

// From turn five onwards, checks if there has been a winner.
void GameplayState::Update(WindowManager* w) 
{
	//player_.Update(w);
	enemy_.Update(w);
}

void GameplayState::Render(WindowManager* w) 
{
	
	//NOTE:
	// The order in which call draw is the order the objects are rendered.
	// Your player was being drawn first than the background, meaning the
	// the background was being drawn on top of it. Be careful of your
	// draw order!

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	RenderingEngine::DrawTexture(w->getRenderer(), ptr_background_texture_, 0, 0);

	// Player
	player_.Render(w);
	enemy_.Render(w);
	Healthbarin_.Render(w);
	Healthbarout_.Render(w);
}

//
void GameplayState::Reset(WindowManager* w) 
{
	cout << "|-->GameplayState::Reset() Invoked" << endl;

	// Removed TIC_TAC_TOE Code
}