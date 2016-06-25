/*
Copyright © 2016 Jonathan Shirlaw

File: Matrix4.h
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 4x4 Matrix
*/
#pragma once
#include "Vector4.h"

namespace Math
{
	typedef struct
	{
		union
		{
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
		};
	} MATRIX4X4;

	class Matrix4 : public MATRIX4X4
	{
	public:
		// Dimensions of this matrix
		static const int DIM = 4;

	public:
		// Default constructor
		Matrix4();
		// Float Pointer Constructor
		Matrix4(const float*);
		// Value Constructor
		Matrix4(float m11, float m12, float m13, float m14,
				float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34,
				float m41, float m42, float m43, float m44);

		// Copy Constructor
		Matrix4(const Matrix4& refMatrix);
		// Copy Assignment Operator
		Matrix4& operator=(const Matrix4& refMatrix);

		// Returns a null-terminated char array
		const char* ToString() const;

		// Load the Identity Matrix
		void LoadIdentity();

		// Transpose the matrix in place
		Matrix4& Transpose();

		// Creates a new matrix which is the transpose of this one
		Matrix4 GetTranspose() const;

		// Rotation
		Matrix4& SetRotateX(float fAngle);
		Matrix4& SetRotateY(float fAngle);
		Matrix4& SetRotateZ(float fAngle);

		// Static Matrix builders
		static Matrix4 Scale(const Vector4& refVector);
		static Matrix4 Translation(const Vector4& refVector);
		static Matrix4 RotationX(float fAngle);
		static Matrix4 RotationY(float fAngle);
		static Matrix4 RotationZ(float fAngle);

		// Operator Overloads
		Matrix4 operator*(const Matrix4& refMatrix) const;
		Matrix4& operator*=(const Matrix4& refMatrix);

		// Cast to Float Operator
		operator float*();

		// Required by unittest
		Matrix4& setRotateX(float fAngle) { return SetRotateX(fAngle); }
		Matrix4& setRotateY(float fAngle) { return SetRotateY(fAngle); }
		Matrix4& setRotateZ(float fAngle) { return SetRotateZ(fAngle); }
	};
}