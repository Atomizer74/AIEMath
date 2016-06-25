#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

#include "CircleObject.h"

Application2D::Application2D()
{

}

Application2D::~Application2D()
{

}

bool Application2D::startup()
{
	createWindow("Math Class", 1280, 720);

	m_spriteBatch = new SpriteBatch();
	m_texture = new Texture("./bin/textures/crate.png");
	m_font = new Font("./bin/font/consolas.ttf", 32);

	// Init our scene
	m_pScene = new Math::Scene();

	// Set up our planets
	CircleObject* basePlanet = new CircleObject(100.0f, 10, 20);
	basePlanet->SetLocalTransform(Math::Matrix3::Translation({ 640, 360 }));
	m_objects.push_back(basePlanet);
	m_pScene->SetRoot(basePlanet);

	CircleObject* moon = new CircleObject(50.0f, -20, 10);
	moon->SetLocalTransform(Math::Matrix3::Translation({ 200, 0 }));
	m_objects.push_back(moon);
	basePlanet->AddChild(moon);

	CircleObject* asteroid1 = new CircleObject(10, 30, 5);
	asteroid1->SetLocalTransform(Math::Matrix3::Translation({ 50, 50 }));
	m_objects.push_back(asteroid1);
	moon->AddChild(asteroid1);

	CircleObject* moon2 = new CircleObject(40.0f, 40, 8);
	moon2->SetLocalTransform(Math::Matrix3::Translation({ -200, -200 }));
	m_objects.push_back(moon2);
	basePlanet->AddChild(moon2);

	CircleObject* asteroid2 = new CircleObject(10, -60, 6);
	asteroid2->SetLocalTransform(Math::Matrix3::Translation({ -60, 60 }));
	m_objects.push_back(asteroid2);
	moon2->AddChild(asteroid2);

	CircleObject* asteroid3 = new CircleObject(5, -20, 3);
	asteroid3->SetLocalTransform(Math::Matrix3::Translation({ 40, -20 }));
	m_objects.push_back(asteroid3);
	moon2->AddChild(asteroid3);

	// Setup chrono
	this->m_lastFrame = std::chrono::high_resolution_clock::now();
	this->m_timeSinceStart = 0.0f;

	return true;
}

void Application2D::shutdown()
{
	m_objects.clear();
	delete m_pScene;
	delete m_font;
	delete m_texture;
	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime)
{
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	// Oops, apparently not needed
	// Calculate delta time
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - this->m_lastFrame);
	float dt = ((float)(duration.count()) / 1000000000.0f);
	m_timeSinceStart += deltaTime;
	this->m_lastFrame = currentTime;

	// Update our scenes transforms
	m_pScene->UpdateTransform();
	
	// Update our game objects
	for each (IGameObject* obj in m_objects)
	{
		obj->Update(deltaTime);
	}

	// the applciation closes if we return false
	return true;
}

void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	// Draw our game objects
	for each (IGameObject* obj in m_objects)
	{
		obj->Draw(m_spriteBatch);
	}

	// done drawing sprites
	m_spriteBatch->end();	
}