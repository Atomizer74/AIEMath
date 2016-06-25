/*
Copyright © 2016 Jonathan Shirlaw

File: Matrix2.cpp
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 2x2 Matrix
*/
#include "Matrix2.h"
#include "Utility.h"

#include <string>


namespace Math
{

#pragma region Constructors
	// Default constructor
	Matrix2::Matrix2()
	{
		// Always be sure to initialize variables
		LoadIdentity();
	}

	// Float Pointer Constructor
	Matrix2::Matrix2(const float* pMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = pMatrix[(row * DIM) + col];
	}

	// Value Constructor
	Matrix2::Matrix2(float m11, float m12,
					 float m21, float m22)
	{
		_11 = m11;	_12 = m12;
		_21 = m21;	_22 = m22;
	}

	// Copy Constructor
	Matrix2::Matrix2(const Matrix2& refMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = refMatrix.m[row][col];
	}

	// Copy Assignment Operator
	Matrix2& Matrix2::operator=(const Matrix2& refMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = refMatrix.m[row][col];

		return (*this);
	}
#pragma endregion

	// Returns a null-terminated char array
	const char* Matrix2::ToString() const
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
	void Matrix2::LoadIdentity()
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = (row == col) ? 1.0f : 0.0f;
	}

	// Transpose the matrix in place
	Matrix2& Matrix2::Transpose()
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
	Matrix2 Matrix2::GetTranspose() const
	{
		Matrix2 transposeMatrix;

		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				transposeMatrix.m[col][row] = m[row][col];

		return transposeMatrix;
	}

	// Rotation
	Matrix2& Matrix2::SetRotateZ(float fAngle)
	{
		_11 = cosf(fAngle); _12 = sin(fAngle);
		_21 = -sinf(fAngle); _22 = cosf(fAngle);

		return (*this);
	}

	// Calculates the matrices determinate
	float Matrix2::Determinate() const
	{
		float plus = 1.0f;
		float minus = 1.0f;
		for (int row = 0, col = 0; row < DIM; row++, col++)
		{
			plus *= m[row][col];
			minus *= m[(DIM - 1) - row][col];
		}

		return (plus - minus);
	}

#pragma region Static Methods
	// Static Matrix builders
	Matrix2 Matrix2::Scale(const Vector2& refVector)
	{
		Matrix2 mat;
		mat._11 = refVector.X;
		mat._22 = refVector.Y;
		return mat;
	}

	Matrix2 Matrix2::Translation(const Vector2& refVector)
	{
		Matrix2 mat;
		mat._21 = refVector.X;
		mat._22 = refVector.Y;
		return mat;
	}

	Matrix2 Matrix2::RotationZ(float fAngle)
	{
		Matrix2 mat;
		float cosine = cos(fAngle);
		float sine = sin(fAngle);

		mat._11 = cosine;	mat._12 = sine;
		mat._21 = -sine;	mat._22 = cosine;

		return mat;
	}

	float Matrix2::Determinate(const Matrix2& refMatrix)
	{
		float plus = 1.0f;
		float minus = 1.0f;
		for (int row = 0, col = 0; row < DIM; row++, col++)
		{
			plus *= refMatrix.m[row][col];
			minus *= refMatrix.m[(DIM - 1) - row][col];
		}

		return (plus - minus);
	}
#pragma endregion

#pragma region Operator Overloads
	Matrix2 Matrix2::operator*(const Matrix2& refMatrix) const
	{
		Matrix2 mat;

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

	Matrix2& Matrix2::operator*=(const Matrix2& refMatrix)
	{
		return ((*this) = (*this) * refMatrix);
	}
#pragma endregion

	// Cast to Float Operator
	Matrix2::operator float*()
	{
		return (float*)m;
	}
}