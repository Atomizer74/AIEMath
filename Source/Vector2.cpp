/*
Copyright © 2016 Jonathan Shirlaw

File: Vector2.cpp
Author: Jonathan Shirlaw
Date: 02/06/2016

Purpose: Class that contains a 2D Vector
*/
#include "Vector2.h"

#include <string>

namespace Math
{
#pragma region Constructors
	// Default Constructor
	Vector2::Vector2() : X(0.0f), Y(0.0f) {}

	// Destructor
	Vector2::~Vector2() {}

	// Copy Constructor
	Vector2::Vector2(const Vector2& refVector) : X(refVector.X), Y(refVector.Y) {}

	// Copy Assignment Operator
	Vector2 Vector2::operator=(const Vector2& refVector)
	{
		X = refVector.X;
		Y = refVector.Y;

		return (*this);
	}

	// Value Constructor
	Vector2::Vector2(float fX, float fY) : X(fX), Y(fY) {}
#pragma endregion


	// Dot Product
	float Vector2::DotProduct(const Vector2& refVector) const
	{
		return ((X * refVector.X) + (Y * refVector.Y));
	}

	// Magnitude(Length)
	float Vector2::Magnitude() const
	{
		return sqrtf((X * X) + (Y * Y));
	}

	// Normalise the vector in-place
	Vector2& Vector2::Normalise()
	{
		float mag = Magnitude();

		X = X / mag;
		Y = Y / mag;

		return (*this);
	}

	// Returns a null-terminated char array
	const char* Vector2::ToString() const
	{
		static std::string output;

		output = "{X=" + std::to_string(X) + ",Y=" + std::to_string(Y) + "}";

		return output.c_str();
	}

#pragma region Operator Overloads
	// Operator Overloads
	Vector2 Vector2::operator+(const Vector2& refVector) const
	{
		return Vector2(X + refVector.X, Y + refVector.Y);
	}

	Vector2 Vector2::operator-(const Vector2& refVector) const
	{
		return Vector2(X - refVector.X, Y - refVector.Y);
	}

	Vector2 Vector2::operator*(float fScalar) const
	{
		return Vector2(X * fScalar, Y * fScalar);
	}

	Vector2& Vector2::operator+=(const Vector2& refVector)
	{
		(*this) = (*this) + refVector;
		return (*this);
	}

	Vector2& Vector2::operator-=(const Vector2& refVector)
	{
		(*this) = (*this) - refVector;
		return (*this);
	}

	Vector2& Vector2::operator*=(float fScalar)
	{
		(*this) = (*this) * fScalar;
		return (*this);
	}

	Vector2::operator float*()
	{
		return v;
	}
#pragma endregion

	// Global Operator Overloads
	Math::Vector2 operator*(float fScalar, const Math::Vector2& refVector)
	{
		return Math::Vector2(fScalar * refVector.X, fScalar * refVector.Y);
	}
}

