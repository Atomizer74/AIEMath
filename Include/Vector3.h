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

	class Vector3
	{
	public:
		// Anonymous Union and Struct to combine values
		// Apparently this is non-standard? But is supported by Visual Studio
		union
		{
			struct
			{
				float X, Y, Z;
			};
			float v[3];
		};

	public:
		// Default Constructor
		Vector3();
		// Destructor
		~Vector3();

		// Value Constructor
		Vector3(float fX, float fY, float fZ);

		// Copy Constructor
		Vector3(const Vector3& refVector);
		// Copy Assignment Operator
		Vector3 operator=(const Vector3& refVector);

		// Dot Product
		float DotProduct(const Vector3& refVector) const;
		// Cross Product
		Vector3 CrossProduct(const Vector3& refVector) const;
		// Magnitude(Length)
		float Magnitude() const;
		// Normalise the vector in-place
		Vector3& Normalise();

		// Returns a null-terminated char array
		const char* ToString() const;

		// Operator Overloads
		Vector3 operator+(const Vector3& refVector) const;
		Vector3 operator-(const Vector3& refVector) const;
		Vector3 operator*(float fScalar) const;

		Vector3& operator+=(const Vector3& refVector);
		Vector3& operator-=(const Vector3& refVector);
		Vector3& operator*=(float fScalar);

		// Cast to Float Operator
		operator float*();

		// Required for the unittest
		float dot(const Vector3& refVector) const { return DotProduct(refVector); }
		float magnitude() const { return Magnitude(); }
		Vector3& normalise() { return Normalise(); }
		Vector3 cross(const Vector3& refVector) { return CrossProduct(refVector); }
	};

	// Global Operator Overloads
	Math::Vector3 operator*(float fScalar, const Math::Vector3& refVector);
}

