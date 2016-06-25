#pragma once
#include "SpriteBatch.h"
#include <MathLib.h>

class IGameObject : public Math::SceneNode
{
public:
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(SpriteBatch* spriteBatch) = 0;
};