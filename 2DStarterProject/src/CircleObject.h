#pragma once

#include "IGameObject.h"


class CircleObject : public IGameObject
{
	float _radius;
	float _rotSpeed;
	int _segments;

public:
	CircleObject(float fRadius, float fRotationSpeed = 20.0f, int segments = 10) : _radius(fRadius), _rotSpeed(fRotationSpeed), _segments(segments)
	{

	}

	virtual ~CircleObject() {}

	virtual void Update(float deltaTime)
	{
		// Apply a rotation
		Math::Matrix3 mR = Math::Matrix3::RotationZ(Math::Deg2Rad(_rotSpeed * deltaTime));
		m_localTransform = mR * m_localTransform;
	}

	virtual void Draw(SpriteBatch* spriteBatch)
	{
		float segmentDistance = 360.0f / (float)_segments;

		Math::Vector3 lastPoint { _radius, 0, 1 };
		for (int i = 0; i < _segments; i++)
		{
			Math::Matrix3 rotMat = Math::Matrix3::RotationZ(Math::Deg2Rad(segmentDistance));
			Math::Vector3 point = lastPoint * rotMat;

			// Offset the points by the global Transform
			Math::Vector3 p1 = lastPoint * m_globalTransform;
			Math::Vector3 p2 = point * m_globalTransform;
			Math::Vector3 origin = Math::Vector3 { 0, 0, 1 } * m_globalTransform;

			// Draw the line
			spriteBatch->drawLine(p1.X, p1.Y, p2.X, p2.Y);
			// Draw line from origin to the last point
			//spriteBatch->drawLine(origin.X, origin.Y, p1.X, p1.Y);

			lastPoint = point;
		}
	}
};