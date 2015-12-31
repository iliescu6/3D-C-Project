/* 
OpenGL Template for IN3026
City University London, School of Informatics
Source code drawn from a number of sources and examples, including contributions from
 - Ben Humphrey (gametutorials.com), Christy Quinn, Sam Kellett, and others

 For educational use by School of Informatics, City University London UK.

 This template contains a skybox, simple terrain, camera, lighting, mesh loader, sipmle physics, texturing, audio

 Potential ways to modify the code:  Add new geometry types, change the terrain, load new meshes, set up lighting, 
 add in additional music / sound FX, modify camera control, put in a startup screen, collision detection, etc.
 
 Template version 3.0a 25/08/2014
 Dr. Greg Slabaugh (gregory.slabaugh.1@city.ac.uk) 
*/


#include "Game.h"


// Constructor.  
Game::Game()  
{
	m_introScreen = true;
	m_dt = 0.0f;

}

// Destructor.  Technically we could delete all resources, but when the game ends the OS will free memory for us.
Game::~Game() 
{ 
}

// Initialise the game by loading assets and setting up the scene.  Note, it's best to make OpenGL calls here since we know the rendering context is available.
void Game::Initialise() 
{

	
	score = 0;
	// Initialise the camera (position, view point, upvector, and speed)
	m_camera.Set(CVector3f(0, 90, -20), CVector3f(0, 10, -3), CVector3f(0, 1, 0), 20.0f);

	// Create the terrain and skybox
	m_terrain.Initialise();
	m_skybox.Create("", 0.0f);

	// Create a class for rendering text
	m_score.Create(m_GameWindow.GetHdc(), "Arial", 18);

	//glClearColor(1, 1, 1, 1);

	// Load some meshes
	m_tree.Load("Resources\\Meshes\\elm.3ds");
	m_cow.Load("Resources\\Meshes\\cow4.3ds"); 
	m_jeep.Load("Resources\\Meshes\\jeep1.obj");

	//Intro screen
	CTexture texture;
	texture.Load("Resources\\Textures\\Menu.bmp", false);
	m_introScreenID = texture.m_textureID;
	//Win screen
	CTexture win_texture;
	win_texture.Load("Resources\\Textures\\win.bmp", false);
	m_winScreenID = win_texture.m_textureID;
	//Lose screen
	CTexture lose_texture;
	lose_texture.Load("Resources\\Textures\\lose.bmp", false);
	m_loseScreenID = lose_texture.m_textureID;

	// Initialise audio and play background music
	m_audio.Initialise();
	m_audio.LoadEventSound("Resources\\Audio\\pickup_score.wav");					// Royalty free sound from freesound.org
	m_audio2.Initialise();
	m_audio2.LoadEventSound("Resources\\Audio\\pickup_time.wav");					// Royalty free sound from freesound.org
	m_audio.LoadMusicStream("Resources\\Audio\\class.mp3");	            // Royalty free music from http://www.nosoapradio.us/
	m_audio2.LoadMusicStream("Resources\\Audio\\ballad.mp3");	            // Royalty free music from http://www.nosoapradio.us/
	m_audio.PlayMusicStream();
	

	// Load an animated character -- free to use from http://www.gamers.org/pub/idgames2/quake2/graphics/md2/ 
	//m_yohko.Load("Resources\\Meshes\\Yohko.md2", "Resources\\Meshes\\Yohko.bmp", "Resources\\Meshes\\YohkoWeapon.md2", "Resources\\Meshes\\YohkoWeapon.bmp");

	/*
	// If you plan to load a number of enemies and store them on an std::vector, it is best to use pointers, like this:
	for (unsigned int i = 0; i < 5; i++) {
	   m_enemies.push_back(new CMD2Model);
	   m_enemies[i]->Load(...);
	}
	*/

	   //Score pick positions
		m_pickup[0].Initialise(CVector3f(13.0f, 7.5f, 30.0f));
		m_pickup[1].Initialise(CVector3f(-13.0f, 7.5f, 30.0f));
		m_pickup[2].Initialise(CVector3f(8.0f, 7.5f, -31.0f));

		//Time picks positions
		//Error if the array has only 3 elements for some unknown reason
		m_timepick[0].Initialise(CVector3f(13.0f, 7.5f, 1.0f));
		m_timepick[1].Initialise(CVector3f(-14.0f, 7.5f, 1.0f));
		m_timepick[2].Initialise(CVector3f(-8.0f, 7.5f, -30.0f));


		m_level.Initialise(CVector3f(0.0f,5.5f,0.0f));
		m_player.Initialise();

		m_lighting.Initialise();
		//Primitives
		m_crystal.Initialise();
		m_bridge.Initialise();
		m_ramp.Initialise();

		x[0] = 0;
		x[1] = 0;
		x[2] = 0;

		y[0] = 0;
		y[1] = 0;
		y[2] = 0;

		m_timePasseed.Start();
		lose_Screen = false;
		m_time = 1000;
	
		change = false;
}

// Update game objects using a timer
void Game::Update() 
{
	CVector3f prevPos;
	prevPos = m_player.GetPosition();
	if (m_introScreen == false && change == false){
		m_audio.StopMusic();
		m_audio2.PlayMusicStream();
		change = true;
	}
	fade.Update(m_dt);
		// Comment out to inspect objects
		//m_camera.Update(m_dt);

		//CHECK INTRO BOOL
		if (GetKeyState('1') & 0x80 && m_introScreen==true) {
			m_introScreen = false;	
			easy = true;
			m_time = 300;
		}
		else if (GetKeyState('2') & 0x80 && m_introScreen==true){
			m_introScreen = false;
			easy = false;
			m_time=180;
			m_fx.ActivateFog(0.01, 0.5, 0.5, 0.5);
		}

		//PLayer mesh
		m_player.Update(m_dt);


		//Pickups
		//Score

		for (int i = 0; i < 3; i++){
			m_pickup[i].Update(m_player.GetPosition(), score);
			if (m_pickup[i].Picked() == true && x[i] == 0){
				score += m_pickup[i].GetScore();
				picked[i] = m_pickup[i].Picked();
				x[i] = 1;
				m_audio.PlayEventSound();
				fade.Activate();
			}
		}


		 
		//Add time
		for (int i = 0; i < 3; i++){
			m_timepick[i].Update(m_player.GetPosition(), score);
			if (m_timepick[i].Picked() == true && y[i] == 0){
				m_time += m_timepick[i].GetTime();
				picked[i+3] = m_timepick[i].Picked();
				y[i] = 1;
				m_audio2.PlayEventSound();
				fade.Activate();
			}
		}
		

		//Primitives
		m_crystal.Update(m_dt);


		//BOunding boxes collisions

		

		for (int i = 0; i < 18; i++){
			if (m_level.GetBoundingBox(i).Collision(m_player.GetBoundingBox()))
			{
				m_player.SetPosition(prevPos);
			}
		}

		//m_camera.Set(m_camera.GetPosition(),m_camera.GetViewPoint(),m_camera.GetUpVector(),5.0f);
		// Often it will be useful to perform collision detection and response in Update()

		// Update the physical simulation

		// Periodically update audio being played back by FMOD
		m_audio.Update();

		m_GameWindow.UpdateFrameRate(m_dt);

		if (picked[0] == true && picked[3] == true){
			m_lighting.ChangeColor(0, 0.0f, 1.0f);
		}

		if (picked[1] == true && picked[4] == true){
			m_lighting.ChangeColor(1,0.0f,1.0f);
		}

		if (picked[2] == true) {
			m_lighting.ChangeColor(2, 0.0f, 1.0f);
		}
	
		if (picked[5] == true) {
			m_lighting.ChangeColor(3, 0.0f, 1.0f);
		}

		if (picked[0] == true && picked[1]==true && picked[2]==true && picked[3]==true && picked[4]==true && picked[5]==true) {
			win_screen = true;
		}
		if (m_time <= 0){
			m_time = 0;
			lose_Screen = true;
		}

		if (m_time <= 0){ lose_Screen = true; }

			
}

// Render the scene
void Game::Render() 
{

	//CTexture texture;
	//texture.Load("Resources\\Textures\\stone.bmp", false);
	//UINT m_textureID = texture.m_textureID;

	// GLuint errCode = glGetError(); // Can check for OpenGL errors with this -- should be zero if no error

	// Clear the buffers and load the identity matrix into the modelview matrix
	

	
	if (m_introScreen == true && win_screen == false)
	{
		screen.MakeScreen(m_introScreenID);
	}
	else if (m_introScreen == false && win_screen == false && lose_Screen==false){
		glPushMatrix();
		
		glPopMatrix();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		// Calling look will put the viewing matrix onto the modelview matrix stack
		m_camera.Look();

		// Get the camera position and view vector
		CVector3f vPos = m_camera.GetPosition();
		CVector3f vView = m_camera.GetViewPoint();

		fade.Render(1, 0, 0);
		CVector3f p = CVector3f(0, 0, 30);
		CVector3f c = m_camera.GetPosition();

		CVector3f vresult;
		float theta;
		vresult = c - p;
		theta = atan2(vresult.x, vresult.z)*(180.0f / M_PI);
		// Render skybox with no lighting
		glDisable(GL_LIGHTING);
		m_skybox.Render(vPos.x, vPos.y, vPos.z, 250, 500, 250);  // Render the skybox with lighting off

		char buf[13];		
		sprintf_s(buf, "%d", (int)m_time);
		m_score.Render("Time:",345,25,0,0,1);
		m_score.Render(buf, 395, 25, 0, 0, 1);  // Draw some text -- useful for debugging and head's up displays
		m_score.Render("Score:", 15, 25, 0, 0, 1);
		sprintf_s(buf, "%d", score);
		m_score.Render(buf, 85, 25, 0, 0, 1);


		glEnable(GL_LIGHTING);

		//Render score
			m_pickup[0].Render();
			m_pickup[1].Render();
			m_pickup[2].Render();


			
			/*m_boundingBox.Set(CVector3f(m_level.GetPosition().x - 40.0f, m_level.GetPosition().y, m_level.GetPosition().z + 40.0f), CVector3f(m_level.GetPosition().x + 40.0f, m_level.GetPosition().y + 10.0f, m_level.GetPosition().z + 34.0f));
			if (m_boundingBox.Collision(m_player.GetBoundingBox()))
			{
				m_player.SetPosition(CVector3f(0,10,0));
			}*/
			//Render time picks
			m_timepick[0].Render();
			m_timepick[1].Render();
			m_timepick[2].Render();

		// Render the terrain
		m_terrain.Render();


		m_level.Render();
		m_player.Render();


		//Primitives

		//1st primitive 
		glPushMatrix();
		glTranslatef(-7,2.75,24);		
		m_crystal.Render(1.0f, 1.0f, 1.0f, 0.1f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(7, 2.75, 24);
		m_crystal.Render(1.0f, 1.0f, 1.0f, 0.1f);
		glPopMatrix();

		//2nd primitive
		glPushMatrix();
		glTranslatef(5, -5, 0);		
		m_bridge.Render(1.0f, 1.0f, 1.0f, 1.0f);
		glPopMatrix();


		//3rd primitive
		glPushMatrix();
		glTranslatef(5, -5, -7);
		m_ramp.Render(0,1.0f, 1.0f, 1.0f, 1.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-5, -5, 2);	
		m_ramp.Render(180,1.0f, 1.0f, 1.0f, 1.0f);
		glPopMatrix();

		//Set lights
		glPushMatrix();
		m_material.SetDefaultMaterial();
		m_lighting.SetLights(CVector3f(m_player.GetPosition().x, m_player.GetPosition().y + 1, m_player.GetPosition().z), CVector3f(30.0f, 10.0f, 14.5f),
			CVector3f(-30.0f, 10.0f, 14.5f), CVector3f(30.0f, 10.0f, -17.5f), CVector3f(-30.0f,10.0f,-17.5f));
		glPopMatrix();

	}
	else  if (m_introScreen == false && win_screen==true && lose_Screen==false){
		screen.MakeScreen(m_winScreenID);
	}
	else if (m_introScreen == false && win_screen == false && lose_Screen==true){
		screen.MakeScreen(m_loseScreenID);
	}
	
	SwapBuffers(m_GameWindow.GetHdc());		
}

void Game::GameLoop()
{
	

	float frame_duration=1.0f/60.0f;
	// This code implements a fixed timer
	m_dt = m_highResolutionTimer.Elapsed();
	
	if (m_timePasseed.Elapsed() >= 1.0f && m_introScreen==false){
		m_time -= 1;
		m_timePasseed.Start();
	}


	if (m_dt > frame_duration) {
		m_highResolutionTimer.Start();

		Update();
		Render();
	}
	
	/*
	// This code implements a variable timer
	m_highResolutionTimer.Start();
	Update();
	Render();
	m_dt = m_highResolutionTimer.Elapsed();
	*/		

}

WPARAM Game::Execute() 
{
	m_GameWindow.Init(m_hinstance);

	if(!m_GameWindow.GetHdc()) {
		return 1;
	}

	Initialise();

	m_highResolutionTimer.Start();

	

	MSG msg;

	while(1) {													
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { 
			if(msg.message == WM_QUIT) {
				break;
			}

			TranslateMessage(&msg);	
			DispatchMessage(&msg);
		}else{
			GameLoop();
		} 
	}

	m_GameWindow.Deinit();

	return(msg.wParam);
}



LRESULT Game::ProcessEvents(HWND window,UINT message, WPARAM w_param, LPARAM l_param) 
{
	LRESULT result = 0;

	switch (message) {
	case WM_SIZE:
		if (!m_GameWindow.GetFullScreen()) {
			m_GameWindow.SizeOpenGLScreen(LOWORD(l_param), HIWORD(l_param));

			RECT dimensions;
			GetClientRect(window, &dimensions);
			m_GameWindow.SetDimensions(dimensions);
		}
		break;
	case WM_PAINT:
		PAINTSTRUCT ps;
		BeginPaint(window, &ps);
		EndPaint(window, &ps);
		break;

	case WM_KEYDOWN:
		switch(w_param) {
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		/*case VK_UP:
			//m_animation++;
			m_player.SetAnimation(1);
			break;*/
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		result = DefWindowProc(window, message, w_param, l_param);
		break;
	}

	return result;
}

Game& Game::GetInstance() 
{
	static Game instance;

	return instance;
}

void Game::SetHinstance(HINSTANCE hinstance) 
{
	m_hinstance = hinstance;
}


LRESULT CALLBACK WinProc(HWND window, UINT message, WPARAM w_param, LPARAM l_param)
{
	return Game::GetInstance().ProcessEvents(window, message, w_param, l_param);
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, PSTR, int) 
{
	Game &game = Game::GetInstance();
	game.SetHinstance(hinstance);

	return game.Execute();
}

bool Game::Distance(CVector3f v,CVector3f v1){
	CVector3f d;
	d = v - v1;
	if (d.Length() < 5){
		return true;
	}
	else
		return false; 
}