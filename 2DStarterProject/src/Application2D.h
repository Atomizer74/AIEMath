#pragma once
#include "BaseApplication.h"
#include "IGameObject.h"
#include "CircleObject.h"
#include <MathLib.h>
#include <chrono>
#include <vector>

class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication
{
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

protected:
	Math::Scene* m_pScene;
	std::vector<IGameObject*> m_objects;

	// Time variables
	std::chrono::high_resolution_clock::time_point m_lastFrame;
	float m_timeSinceStart;

	SpriteBatch*	m_spriteBatch;
	Texture*		m_texture;
	Font*			m_font;
};