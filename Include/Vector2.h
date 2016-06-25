/*
Copyright © 2016 Jonathan Shirlaw

File: Vector2.h
Author: Jonathan Shirlaw
Date: 02/06/2016

Purpose: Class that contains a 2D Vector
*/
#pragma once

namespace Math
{

	class Vector2
	{
	public:
		// Anonymous Union and Struct to combine values
		// Apparently this is non-standard? But is supported by Visual Studio
		union
		{
			struct
			{
				float X, Y;
			};
			float v[2];
		};

	public:
		// Default Constructor
		Vector2();
		// Destructor
		~Vector2();

		// Value Constructor
		Vector2(float fX, float fY);

		// Copy Constructor
		Vector2(const Vector2& refVector);
		// Copy Assignment Operator
		Vector2 operator=(const Vector2& refVector);

		// Dot Product
		float DotProduct(const Vector2& refVector) const;
		
		// Magnitude(Length)
		float Magnitude() const;
		// Normalise the vector in-place
		Vector2& Normalise();

		// Rotate X

		// Returns a null-terminated char array
		const char* ToString() const;

		// Operator Overloads
		Vector2 operator+(const Vector2& refVector) const;
		Vector2 operator-(const Vector2& refVector) const;
		Vector2 operator*(float fScalar) const;

		Vector2& operator+=(const Vector2& refVector);
		Vector2& operator-=(const Vector2& refVector);
		Vector2& operator*=(float fScalar);

		// Cast to Float Operator
		operator float*();

		// Required for the unittest
		float dot(const Vector2& refVector) const { return DotProduct(refVector); }
		float magnitude() const { return Magnitude(); }
		Vector2& normalise() { return Normalise(); }
	};


	// Global Operator Overloads
	Math::Vector2 operator*(float fScalar, const Math::Vector2& refVector);
}

