#pragma once

#define _USE_MATH_DEFINES								// Will allow certain constants (like M_PI) to be availabe from <math.h>

#include <windows.h>									// Header File For the Windows Library
#include <stdio.h>										// Header File For the Standard Input/Output Functions
#include <stdlib.h>										// Header File For the Standard Library
#include <math.h>										// Header File For the Math header file
#include ".\include\glew.h"								// Header File For the GLEW Library
#include ".\include\gl.h"								// Header File For the OpenGL32 Library
#include ".\include\glu.h"								// Header File For the GLu32 Library


// Includes for game objects
#include "Camera.h"
#include "Gamewindow.h"
#include "HighResolutionTimer.h"
#include "Terrain.h"
#include "SkyBox.h"
#include "OpenAssetImporterMesh.h"
#include "Audio.h"
#include "Text.h"
#include "Lighting.h"
#include "Material.h"
#include "Md2Animation.h"
#include "SpecialFX.h"
#include "CollisionDetection.h"
#include "BoundingBox.h"
#include "Screen.h"
#include "CrossFade.h"

//Meshes
#include "Pickup.h"
#include "TimePick.h"
#include "Level1.h"
#include "Player.h"

//Primitives
#include "Crystal.h"
#include "Bridge.h"
#include "Ramp.h"


class Game {
public:

private:
	void Initialise();		// Initialises the games (load assets, etc.)
	void Update();			// Update the simulation at each time step
	void Render();			// Render the scene
	void GameLoop();		// The game loop
	bool Distance(CVector3f v,CVector3f v1);

	// Game objects
	Camera m_camera;								// The camera
	CHighResolutionTimer m_highResolutionTimer;		// A timer for measuring the time between frames
	CHighResolutionTimer m_timePasseed;
	CTerrain m_terrain;								// The terrain (planar)
	CSkybox m_skybox;								// A skybox surrounding the scene
	CAudio m_audio;									// Audio using FMOD
	CAudio m_audio2;
	CText m_score;									// Text for the head's up display
	CLighting m_lighting;							// Lighting 
	CMaterial m_material;							// Material
	CVector3f prevPos;
	CBoundingBox m_boundingBox[18];
	CVector3f m_position;
	Screen screen;

	CCrossFade fade;

	UINT m_introScreenID;
	UINT m_winScreenID;
	UINT m_loseScreenID;

	CCollisionDetection detect;

	COpenAssetImporterMesh m_cow;					// A 3D mesh model 
	COpenAssetImporterMesh m_tree;					// Another 3D mesh model
	COpenAssetImporterMesh m_jeep;

	//Pick ups
	CPickup m_pickup[3];
	CTimePick m_timepick[3];


	CSpecialFX m_fx;
	CLevel1 m_level;
	CPlayer m_player;


	//Primitives
	Crystal m_crystal;
	CBridge m_bridge;
	CRamp m_ramp;

	//Pickups
	int x[3]; 
	int y[3];

	bool picked[6];

	//Screens
	bool win_screen;
	bool lose_Screen;
	bool m_introScreen;								// A boolean flag indicating if the intro screen is on
	double m_dt;									// A variable to measure the amount of time elasped between frames
	bool col;
	//HUD
	double m_time;                                  //Time
	int score;

	bool easy;
	bool change;

public:
	~Game();
	static Game& GetInstance();
	WPARAM Execute();
	void SetHinstance(HINSTANCE hinstance);
	LRESULT ProcessEvents(HWND window,UINT message, WPARAM w_param, LPARAM l_param);
	

private:
	Game::Game();
	Game::Game(const Game&);
	void Game::operator=(const Game&);

	GameWindow m_GameWindow;
	HINSTANCE m_hinstance;


};