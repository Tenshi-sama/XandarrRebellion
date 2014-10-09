#include "GameplayState.h"

// Creates a new instance of Board and OutputPanel and loads the requisite
// resources for the Gameplay State.
void GameplayState::Init(WindowManager* w) 
{
	
	SDL_Renderer* wRend = w->getRenderer(); 
	cout << "|-->GameplayState::Init() Invoked" << endl;

	//ptr_background_texture_ = RenderingEngine::LoadTexture(wRend, "_resources\\map.png");
	level_.Init(wRend);
	player_.Init(wRend);
	enemy_.Init(wRend);
	Healthbarin_.Init(wRend);
	Healthbarout_.Init(wRend);
	katana_.Init(wRend);
	katana_.getWorth();
	katana_.getAttackRate();

}

void GameplayState::Clean() 
{
	cout << "|-->GameplayState::Clean() Invoked" << endl;

	//RenderingEngine::DestroyTexture(ptr_background_texture_);
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
	player_.Update(w);
	enemy_.Update(w);
	katana_.Update(w);
}

void GameplayState::Render(WindowManager* w) 
{
	
	//NOTE:
	// The order in which call draw is the order the objects are rendered.
	// Your player was being drawn first than the background, meaning the
	// the background was being drawn on top of it. Be careful of your
	// draw order!

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	//RenderingEngine::DrawTexture(w->getRenderer(), ptr_background_texture_, 0, 0);

	// Player
	level_.Render(w);
	enemy_.Render(w);
	Healthbarin_.Render(w);
	
	katana_.Render(w);
	Healthbarout_.Render(w);
	player_.Render(w);
	
}

//
void GameplayState::Reset(WindowManager* w) 
{
	cout << "|-->GameplayState::Reset() Invoked" << endl;
}