#include "GameplayState.h"

// Creates a new instance of Board and OutputPanel and loads the requisite
// resources for the Gameplay State.
void GameplayState::Init(WindowManager* w) 
{
	
	SDL_Renderer* wRend = w->getRenderer(); 
	cout << "|-->GameplayState::Init() Invoked" << endl;

	SDL_Init(SDL_INIT_AUDIO);
	if (SDL_Init(SDL_INIT_AUDIO) < 0) 
	{ 
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); 
		success_ = false; 
	}
	//Initialize SDL_mixer 
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) 
	{ 
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() ); 
		success_ = false; 
	}

	//Load music 
	gMusic = Mix_LoadMUS( "_sounds\\beat.wav" );
	if( gMusic == NULL ) 
	{ 
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() ); 
		success_ = false; 
	} 

	//Load sound effects 
	gScratch = Mix_LoadWAV( "_sounds\\left_hook.wav" ); 
	if( gScratch == NULL ) 
	{ 
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() ); 
		success_ = false; 
	}

	//gHigh = Mix_LoadWAV( "21_sound_effects_and_music/high.wav" ); 
	//if( gHigh == NULL ) 
	//{ 
	//	printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() ); 
	//	success_ = false; 
	//} 
	//
	//gMedium = Mix_LoadWAV( "21_sound_effects_and_music/medium.wav" ); 
	//if( gMedium == NULL ) 
	//{ 
	//	printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	//	success_ = false; 
	//} 
	//
	//gLow = Mix_LoadWAV( "21_sound_effects_and_music/low.wav" ); 
	//if( gLow == NULL ) 
	//{ 
	//	printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() ); 
	//	success_ = false; 
	//} 

	//ptr_background_texture_ = RenderingEngine::LoadTexture(wRend, "_resources\\map.png");
	level_.Init(wRend);
	player_.Init(wRend);
	enemy_.Init(wRend);
	Healthbarin_.Init(wRend);
	Healthbarout_.Init(wRend);
	katana_.Init(wRend);
	
}

void GameplayState::Clean() 
{
	cout << "|-->GameplayState::Clean() Invoked" << endl;

	//RenderingEngine::DestroyTexture(ptr_background_texture_);
	is_winner_ = false;

	//Free the sound effects 
	Mix_FreeChunk( gScratch ); 
	Mix_FreeChunk( gHigh ); 
	Mix_FreeChunk( gMedium ); 
	Mix_FreeChunk( gLow ); 
	gScratch = NULL; 
	gHigh = NULL; 
	gMedium = NULL; 
	gLow = NULL; 
	//Free the music 
	Mix_FreeMusic( gMusic ); 
	gMusic = NULL; 
	//Quit SDL subsystems 
	Mix_Quit(); 
	SDL_Quit();
}

// Handles all gameplay events
void GameplayState::HandleEvents(SDL_Event* event)
{

	player_.HandleEvents(event); //Player events
	//enemy_.HandleEvents(event);

	switch (event->type)
	{
	//Play high sound effect
	case SDL_KEYDOWN:
		if (event->key.keysym.sym == SDLK_p)
		{
			Mix_PlayChannel(-1, gScratch, 0);
			cout << "P pressed" << endl;
		}	
	}
}


// From turn five onwards, checks if there has been a winner.
void GameplayState::Update(WindowManager* w)
{
	player_.Update(w);
	enemy_.Update(w);
	katana_.Update(w);

	if (collide(&player_, &enemy_)) {
		enemy_.Moving(false);
	}
	else {
		enemy_.Moving(true);
	}
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

bool GameplayState::collide(Player* a, Enemy* b) {
	//The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a->getXPos();
    rightA = a->getXPos() + a->getWidth();
    topA = a->getYPos();
    bottomA = a->getYPos() + a->getHeight();

    //Calculate the sides of rect B
    leftB = b->getXPos();
    rightB = b->getXPos() + b->getWidth();
    topB = b->getYPos();
    bottomB = b->getYPos() + b->getHeight();//If any of the sides from A are outside of B

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }
	return true;
}