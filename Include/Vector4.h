/*
Copyright © 2016 Jonathan Shirlaw

File: Vector3.h
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 3D Vector
*/
#pragma once

namespace Math
{

	class Vector4
	{
	public:
		// Anonymous Union and Struct to combine values
		// Apparently this is non-standard? But is supported by Visual Studio
		union
		{
			struct
			{
				float X, Y, Z, W;
			};
			float v[4];
		};

	public:
		// Default Constructor
		Vector4();
		// Destructor
		~Vector4();

		// Value Constructor
		Vector4(float fX, float fY, float fZ, float fW = 1.0f);

		// Copy Constructor
		Vector4(const Vector4& refVector);
		// Copy Assignment Operator
		Vector4 operator=(const Vector4& refVector);

		// Dot Product
		float DotProduct(const Vector4& refVector) const;
		// Cross Product
		Vector4 CrossProduct(const Vector4& refVector) const;
		// Magnitude(Length)
		float Magnitude() const;
		// Normalise the vector in-place
		Vector4& Normalise();

		// Returns a null-terminated char array
		const char* ToString() const;

		// Operator Overloads
		Vector4 operator+(const Vector4& refVector) const;
		Vector4 operator-(const Vector4& refVector) const;
		Vector4 operator*(float fScalar) const;

		Vector4& operator+=(const Vector4& refVector);
		Vector4& operator-=(const Vector4& refVector);
		Vector4& operator*=(float fScalar);

		// Cast to Float Operator
		operator float*();

		// Required for the unittest
		float dot(const Vector4& refVector) const { return DotProduct(refVector); }
		float magnitude() const { return Magnitude(); }
		Vector4& normalise() { return Normalise(); }
		Vector4 cross(const Vector4& refVector) { return CrossProduct(refVector); }
	};

	// Global Operator Overloads
	Math::Vector4 operator*(float fScalar, const Math::Vector4& refVector);
}
