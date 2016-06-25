/*
Copyright © 2016 Jonathan Shirlaw

File: Vector3.cpp
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 3D Vector
*/
#include "Vector3.h"

#include <string>

namespace Math
{
#pragma region Constructors
	// Default Constructor
	Vector3::Vector3() : X(0.0f), Y(0.0f), Z(0.0f) {}

	// Destructor
	Vector3::~Vector3() {}

	// Copy Constructor
	Vector3::Vector3(const Vector3& refVector)
		: X(refVector.X), Y(refVector.Y), Z(refVector.Z) {}

	// Copy Assignment Operator
	Vector3 Vector3::operator=(const Vector3& refVector)
	{
		X = refVector.X;
		Y = refVector.Y;
		Z = refVector.Z;

		return (*this);
	}

	// Value Constructor
	Vector3::Vector3(float fX, float fY, float fZ) : X(fX), Y(fY), Z(fZ) {}
#pragma endregion


	// Dot Product
	float Vector3::DotProduct(const Vector3& refVector) const
	{
		return ((X * refVector.X) + (Y * refVector.Y) + (Z * refVector.Z));
	}

	// Cross Product
	Vector3 Vector3::CrossProduct(const Vector3& refVector) const
	{
		return Vector3 {
			(Y * refVector.Z) - (Z * refVector.Y),
			(Z * refVector.X) - (X * refVector.Z),
			(X * refVector.Y) - (Y * refVector.X)
		};
	}

	// Magnitude(Length)
	float Vector3::Magnitude() const
	{
		return sqrtf((X * X) + (Y * Y) + (Z * Z));
	}

	// Normalise the vector in-place
	Vector3& Vector3::Normalise()
	{
		float mag = Magnitude();

		X = X / mag;
		Y = Y / mag;
		Z = Z / mag;

		return (*this);
	}

	// Returns a null-terminated char array
	const char* Vector3::ToString() const
	{
		static std::string output;

		output = "{X=" + std::to_string(X) + ",Y=" + std::to_string(Y) + ",Z=" + std::to_string(Z) + "}";

		return output.c_str();
	}

#pragma region Operator Overloads
	// Operator Overloads
	Vector3 Vector3::operator+(const Vector3& refVector) const
	{
		return Vector3(X + refVector.X, Y + refVector.Y, Z + refVector.Z);
	}

	Vector3 Vector3::operator-(const Vector3& refVector) const
	{
		return Vector3(X - refVector.X, Y - refVector.Y, Z - refVector.Z);
	}

	Vector3 Vector3::operator*(float fScalar) const
	{
		return Vector3(X * fScalar, Y * fScalar, Z * fScalar);
	}

	Vector3& Vector3::operator+=(const Vector3& refVector)
	{
		(*this) = (*this) + refVector;
		return (*this);
	}

	Vector3& Vector3::operator-=(const Vector3& refVector)
	{
		(*this) = (*this) - refVector;
		return (*this);
	}

	Vector3& Vector3::operator*=(float fScalar)
	{
		(*this) = (*this) * fScalar;
		return (*this);
	}

	Vector3::operator float*()
	{
		return v;
	}
#pragma endregion

	// Global Operator Overloads
	Math::Vector3 operator*(float fScalar, const Math::Vector3& refVector)
	{
		return Math::Vector3(fScalar * refVector.X, fScalar * refVector.Y, fScalar * refVector.Z);
	}
}