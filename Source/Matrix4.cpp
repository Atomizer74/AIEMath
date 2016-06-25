/*
Copyright © 2016 Jonathan Shirlaw

File: Matrix4.cpp
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 4x4 Matrix
*/
#include "Matrix3.h"
#include "Matrix4.h"
#include "Utility.h"

#include <string>


namespace Math
{

#pragma region Constructors
	// Default constructor
	Matrix4::Matrix4()
	{
		// Always be sure to initialize variables
		LoadIdentity();
	}

	// Float Pointer Constructor
	Matrix4::Matrix4(const float* pMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = pMatrix[(row * DIM) + col];
	}

	// Value Constructor
	Matrix4::Matrix4(float m11, float m12, float m13, float m14,
					 float m21, float m22, float m23, float m24,
					 float m31, float m32, float m33, float m34,
					 float m41, float m42, float m43, float m44)
	{
		_11 = m11;	_12 = m12;	_13 = m13; _14 = m14;
		_21 = m21;	_22 = m22;	_23 = m23; _24 = m24;
		_31 = m31;	_32 = m32;	_33 = m33; _34 = m34;
		_41 = m41;	_42 = m42;	_43 = m43; _44 = m44;
	}

	// Copy Constructor
	Matrix4::Matrix4(const Matrix4& refMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = refMatrix.m[row][col];
	}

	// Copy Assignment Operator
	Matrix4& Matrix4::operator=(const Matrix4& refMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = refMatrix.m[row][col];

		return (*this);
	}
#pragma endregion

	// Returns a null-terminated char array
	const char* Matrix4::ToString() const
	{
		static std::string output;
		output = "";

		for (int row = 0; row < DIM; row++)
		{
			for (int col = 0; col < DIM; col++)
				output += "[" + std::to_string(m[row][col]) + "] ";
			
			output += "\n";
		}

		return output.c_str();
	}

	// Load the Identity Matrix
	void Matrix4::LoadIdentity()
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = (row == col) ? 1.0f : 0.0f;
	}

	// Transpose the matrix in place
	Matrix4& Matrix4::Transpose()
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
			{
				if (row >= col) // We want to skip redundant swaps like _11 or _21(it already swaps at _12)
					continue;
				swap(m[row][col], m[col][row]);
			}

		return (*this);
	}

	// Creates a new matrix which is the transpose of this one
	Matrix4 Matrix4::GetTranspose() const
	{
		Matrix4 transposeMatrix;

		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				transposeMatrix.m[col][row] = m[row][col];

		return transposeMatrix;
	}


	// Rotation
	Matrix4& Matrix4::SetRotateX(float fAngle)
	{
		float cosine = cosf(fAngle);
		float sine = sinf(fAngle);

		_22 = cosine;	_23 = sine;
		_32 = -sine;	_33 = cosine;

		return (*this);
	}

	Matrix4& Matrix4::SetRotateY(float fAngle)
	{
		float cosine = cosf(fAngle);
		float sine = sinf(fAngle);

		_11 = cosine;	_13 = -sine;
		_31 = sine;		_33 = cosine;

		return (*this);
	}

	Matrix4& Matrix4::SetRotateZ(float fAngle)
	{
		float cosine = cosf(fAngle);
		float sine = sinf(fAngle);

		_11 = cosine;	_12 = sine;
		_21 = -sine;	_22 = cosine;

		return (*this);
	}

#pragma region Static Methods
	// Static Matrix builders
	Matrix4 Matrix4::Scale(const Vector4& refVector)
	{
		Matrix4 mat;

		mat._11 = refVector.X;
		mat._22 = refVector.Y;
		mat._33 = refVector.Z;
		mat._44 = refVector.W;

		return mat;
	}

	Matrix4 Matrix4::Translation(const Vector4& refVector)
	{
		Matrix4 mat;
		mat._41 = refVector.X;
		mat._42 = refVector.Y;
		mat._43 = refVector.Z;
		mat._44 = refVector.W;
		return mat;
	}

	Matrix4 Matrix4::RotationX(float fAngle)
	{
		Matrix4 mat;
		float cosine = cos(fAngle);
		float sine = sin(fAngle);

		mat._22 = cosine;	mat._23 = sine;
		mat._32 = -sine;	mat._33 = cosine;

		return mat;
	}

	Matrix4 Matrix4::RotationY(float fAngle)
	{
		Matrix4 mat;
		float cosine = cos(fAngle);
		float sine = sin(fAngle);

		mat._11 = cosine;	mat._13 = -sine;
		mat._31 = sine;		mat._33 = cosine;

		return mat;
	}

	Matrix4 Matrix4::RotationZ(float fAngle)
	{
		Matrix4 mat;
		float cosine = cos(fAngle);
		float sine = sin(fAngle);

		mat._11 = cosine;	mat._12 = sine;
		mat._21 = -sine;	mat._22 = cosine;

		return mat;
	}
#pragma endregion

#pragma region Operator Overloads
	Matrix4 Matrix4::operator*(const Matrix4& refMatrix) const
	{
		Matrix4 mat;

		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
			{
				float res = 0.0f;

				for (int i = 0; i < DIM; i++)
				{
					res += (m[row][i] * refMatrix.m[i][col]);
				}

				mat.m[row][col] = res;
			}
		return mat;
	}

	Matrix4& Matrix4::operator*=(const Matrix4& refMatrix)
	{
		return ((*this) = (*this) * refMatrix);
	}
#pragma endregion

	// Cast to Float Operator
	Matrix4::operator float*()
	{
		return (float*)m;
	}
}