/*
Copyright © 2016 Jonathan Shirlaw

File: Vector4.cpp
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 4D Vector
*/
#include "Vector4.h"

#include <string>

namespace Math
{
#pragma region Constructors
	// Default Constructor
	Vector4::Vector4() : X(0.0f), Y(0.0f), Z(0.0f), W(0.0f) {}

	// Destructor
	Vector4::~Vector4() {}

	// Copy Constructor
	Vector4::Vector4(const Vector4& refVector)
		: X(refVector.X), Y(refVector.Y), Z(refVector.Z), W(refVector.W)
	{
	}

	// Copy Assignment Operator
	Vector4 Vector4::operator=(const Vector4& refVector)
	{
		X = refVector.X;
		Y = refVector.Y;
		Z = refVector.Z;
		W = refVector.W;

		return (*this);
	}

	// Value Constructor
	Vector4::Vector4(float fX, float fY, float fZ, float fW) : X(fX), Y(fY), Z(fZ), W(fW) {}
#pragma endregion


	// Dot Product
	float Vector4::DotProduct(const Vector4& refVector) const
	{
		return ((X * refVector.X) + (Y * refVector.Y) + (Z * refVector.Z));
	}

	// Cross Product
	Vector4 Vector4::CrossProduct(const Vector4& refVector) const
	{
		return Vector4 {
			(Y * refVector.Z) - (Z * refVector.Y),
			(Z * refVector.X) - (X * refVector.Z),
			(X * refVector.Y) - (Y * refVector.X),
			W
		};
	}

	// Magnitude(Length)
	float Vector4::Magnitude() const
	{
		return sqrtf((X * X) + (Y * Y) + (Z * Z));
	}

	// Normalise the vector in-place
	Vector4& Vector4::Normalise()
	{
		float mag = Magnitude();

		X = X / mag;
		Y = Y / mag;
		Z = Z / mag;

		return (*this);
	}

	// Returns a null-terminated char array
	const char* Vector4::ToString() const
	{
		static std::string output;

		output = "{X=" + std::to_string(X) + ",Y=" + std::to_string(Y) + ",Z=" + std::to_string(Z) + ",W=" + std::to_string(W) + "}";

		return output.c_str();
	}

#pragma region Operator Overloads
	// Operator Overloads
	Vector4 Vector4::operator+(const Vector4& refVector) const
	{
		return Vector4(X + refVector.X, Y + refVector.Y, Z + refVector.Z, W + refVector.W);
	}

	Vector4 Vector4::operator-(const Vector4& refVector) const
	{
		return Vector4(X - refVector.X, Y - refVector.Y, Z - refVector.Z, W - refVector.W);
	}

	Vector4 Vector4::operator*(float fScalar) const
	{
		return Vector4(X * fScalar, Y * fScalar, Z * fScalar, W * fScalar);
	}

	Vector4& Vector4::operator+=(const Vector4& refVector)
	{
		(*this) = (*this) + refVector;
		return (*this);
	}

	Vector4& Vector4::operator-=(const Vector4& refVector)
	{
		(*this) = (*this) - refVector;
		return (*this);
	}

	Vector4& Vector4::operator*=(float fScalar)
	{
		(*this) = (*this) * fScalar;
		return (*this);
	}

	Vector4::operator float*()
	{
		return v;
	}
#pragma endregion

	// Global Operator Overloads
	Math::Vector4 operator*(float fScalar, const Math::Vector4& refVector)
	{
		return Math::Vector4(fScalar * refVector.X, fScalar * refVector.Y, fScalar * refVector.Z, fScalar * refVector.W);
	}
}