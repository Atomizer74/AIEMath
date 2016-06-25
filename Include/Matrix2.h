/*
Copyright © 2016 Jonathan Shirlaw

File: Matrix2.h
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 2x2 Matrix
*/
#pragma once
#include "Vector2.h"

namespace Math
{

	typedef struct
	{
		union
		{
			struct
			{
				float _11, _12;
				float _21, _22;
			};
			float m[2][2];
		};
	} MATRIX2X2;

	class Matrix2 : public MATRIX2X2
	{
	public:
		// Dimensions of this matrix
		static const int DIM = 2;

	public:
		// Default constructor
		Matrix2();
		// Float Pointer Constructor
		Matrix2(const float*);
		// Value Constructor
		Matrix2(float m11, float m12,
				float m21, float m22);

		// Copy Constructor
		Matrix2(const Matrix2& refMatrix);
		// Copy Assignment Operator
		Matrix2& operator=(const Matrix2& refMatrix);

		// Returns a null-terminated char array
		const char* ToString() const;

		// Load the Identity Matrix
		void LoadIdentity();

		// Transpose the matrix in place
		Matrix2& Transpose();

		// Creates a new matrix which is the transpose of this one
		Matrix2 GetTranspose() const;

		// Rotation
		Matrix2& SetRotateZ(float fAngle);

		// Calculates the matrices determinate
		float Determinate() const;

		// Static Matrix builders
		static Matrix2 Scale(const Vector2& refVector);
		static Matrix2 Translation(const Vector2& refVector);
		static Matrix2 RotationZ(float fAngle);

		static float Determinate(const Matrix2& refMatrix);

		// Operator Overloads
		Matrix2 operator*(const Matrix2& refMatrix) const;
		Matrix2& operator*=(const Matrix2& refMatrix);

		// Cast to Float Operator
		operator float*();

		// Required by unittest
		Matrix2& setRotateZ(float fAngle) { return SetRotateZ(fAngle); }
	};
}