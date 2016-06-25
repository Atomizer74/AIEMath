/*
Copyright © 2016 Jonathan Shirlaw

File: Utility.cpp
Author: Jonathan Shirlaw
Date: 02/06/2016

Purpose: This contains various standalone functions and constants that do not long in its own class.
*/
#include "Utility.h"

namespace Math
{
	// Converts from Degrees to Radians
	// (DEG / 180) * PI
	float Deg2Rad(const float fDegrees)
	{
		return (fDegrees / 180.0f) * PI;
	}

	// Converts from Radians to Degrees
	// (RAD / PI) * 180
	float Rad2Deg(const float fRadians)
	{
		return (fRadians / PI) * 180.0f;
	}

	// Linear Interpolation
	float Lerp(float fP1, float fP2, float fAmount)
	{
		float t = Clamp(fAmount, 0.0f, 1.0f);
		return fP1 + t * (fP2 - fP1);
	}

	// Clamp a value between a min and a max
	float Clamp(float fValue, float fMin, float fMax)
	{
		return ((fValue > fMax) ? fMax : ((fValue < fMin) ? fMin : fValue));
	}
}