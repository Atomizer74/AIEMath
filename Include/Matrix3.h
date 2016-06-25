/*
Copyright © 2016 Jonathan Shirlaw

File: Matrix3.h
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 3x3 Matrix
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
				float _11, _12, _13;
				float _21, _22, _23;
				float _31, _32, _33;
			};
			float m[3][3];
		};
	} MATRIX3X3;

	class Matrix3 : public MATRIX3X3
	{
	public:
		// Dimensions of this matrix
		static const int DIM = 3;

	public:
		// Default constructor
		Matrix3();
		// Float Pointer Constructor
		Matrix3(const float*);
		// Value Constructor
		Matrix3(float m11, float m12, float m13,
				float m21, float m22, float m23,
				float m31, float m32, float m33);

		// Copy Constructor
		Matrix3(const Matrix3& refMatrix);
		// Copy Assignment Operator
		Matrix3& operator=(const Matrix3& refMatrix);

		// Returns a null-terminated char array
		const char* ToString() const;

		// Load the Identity Matrix
		void LoadIdentity();

		// Transpose the matrix in place
		Matrix3& Transpose();

		// Creates a new matrix which is the transpose of this one
		Matrix3 GetTranspose() const;

		// Rotation
		Matrix3& SetRotateX(float fAngle);
		Matrix3& SetRotateY(float fAngle);
		Matrix3& SetRotateZ(float fAngle);

		// Calculates the matrices determinate
		float Determinate() const;

		// Static Matrix builders
		static Matrix3 Scale(const Vector2& refVector);
		static Matrix3 Translation(const Vector2& refVector);
		static Matrix3 RotationX(float fAngle);
		static Matrix3 RotationY(float fAngle);
		static Matrix3 RotationZ(float fAngle);

		// Calculates the matrices determinate
		static float Determinate(const Matrix3& refMatrix);

		// Operator Overloads
		Matrix3 operator*(const Matrix3& refMatrix) const;
		Matrix3& operator*=(const Matrix3& refMatrix);

		// Inversion Operator
		Matrix3 operator-() const;

		// Cast to Float Operator
		operator float*();

		// Required by unittest
		Matrix3& setRotateX(float fAngle) { return SetRotateX(fAngle); }
		Matrix3& setRotateY(float fAngle) { return SetRotateY(fAngle); }
		Matrix3& setRotateZ(float fAngle) { return SetRotateZ(fAngle); }
	};
}