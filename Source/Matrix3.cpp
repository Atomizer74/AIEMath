/*
Copyright © 2016 Jonathan Shirlaw

File: Matrix2.cpp
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Class that contains a 3x3 Matrix
*/
#include "Matrix2.h"
#include "Matrix3.h"
#include "Utility.h"

#include <string>


namespace Math
{

#pragma region Constructors
	// Default constructor
	Matrix3::Matrix3()
	{
		// Always be sure to initialize variables
		LoadIdentity();
	}

	// Float Pointer Constructor
	Matrix3::Matrix3(const float* pMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = pMatrix[(row * DIM) + col];
	}

	// Value Constructor
	Matrix3::Matrix3(float m11, float m12, float m13,
					 float m21, float m22, float m23,
					 float m31, float m32, float m33)
	{
		_11 = m11;	_12 = m12;	_13 = m13;
		_21 = m21;	_22 = m22;	_23 = m23;
		_31 = m31;	_32 = m32;	_33 = m33;
	}

	// Copy Constructor
	Matrix3::Matrix3(const Matrix3& refMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = refMatrix.m[row][col];
	}

	// Copy Assignment Operator
	Matrix3& Matrix3::operator=(const Matrix3& refMatrix)
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = refMatrix.m[row][col];

		return (*this);
	}
#pragma endregion

	// Returns a null-terminated char array
	const char* Matrix3::ToString() const
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
	void Matrix3::LoadIdentity()
	{
		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				m[row][col] = (row == col) ? 1.0f : 0.0f;
	}

	// Transpose the matrix in place
	Matrix3& Matrix3::Transpose()
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
	Matrix3 Matrix3::GetTranspose() const
	{
		Matrix3 transposeMatrix;

		for (int row = 0; row < DIM; row++)
			for (int col = 0; col < DIM; col++)
				transposeMatrix.m[col][row] = m[row][col];

		return transposeMatrix;
	}

	// Rotation
	Matrix3& Matrix3::SetRotateX(float fAngle)
	{
		_22 = cosf(fAngle);		_23 = sin(fAngle);
		_32 = -sinf(fAngle);	_33 = cosf(fAngle);

		return (*this);
	}

	Matrix3& Matrix3::SetRotateY(float fAngle)
	{
		_11 = cosf(fAngle);	_13 = -sin(fAngle);
		_31 = sinf(fAngle);	_33 = cosf(fAngle);

		return (*this);
	}

	Matrix3& Matrix3::SetRotateZ(float fAngle)
	{
		_11 = cosf(fAngle);		_12 = sin(fAngle);
		_21 = -sinf(fAngle);	_22 = cosf(fAngle);

		return (*this);
	}

	// Calculates the matrices determinate
	float Matrix3::Determinate() const
	{
		float determinate = 0.0f;
		for (int offset = 0; offset < DIM; offset++)
		{
			float plus = 1.0f;
			float minus = 1.0f;
			for (int row = 0, col = offset; row < DIM; row++, (col = (row + offset) % DIM))
			{
				plus *= m[row][col];
				minus *= m[(DIM - 1) - row][col];
			}
			determinate += plus - minus;
		}

		return determinate;
	}

#pragma region Static Methods
	// Static Matrix builders
	Matrix3 Matrix3::Scale(const Vector2& refVector)
	{
		Matrix3 mat;

		mat._11 = refVector.X;
		mat._22 = refVector.Y;

		return mat;
	}

	Matrix3 Matrix3::Translation(const Vector2& refVector)
	{
		Matrix3 mat;
		mat._31 = refVector.X;
		mat._32 = refVector.Y;
		return mat;
	}

	Matrix3 Matrix3::RotationX(float fAngle)
	{
		Matrix3 mat;
		float cosine = cos(fAngle);
		float sine = sin(fAngle);

		mat._22 = cosine;	mat._23 = sine;
		mat._32 = -sine;	mat._33 = cosine;

		return mat;
	}

	Matrix3 Matrix3::RotationY(float fAngle)
	{
		Matrix3 mat;
		float cosine = cos(fAngle);
		float sine = sin(fAngle);

		mat._11 = cosine;	mat._13 = -sine;
		mat._31 = sine;		mat._33 = cosine;

		return mat;
	}

	Matrix3 Matrix3::RotationZ(float fAngle)
	{
		Matrix3 mat;
		float cosine = cos(fAngle);
		float sine = sin(fAngle);

		mat._11 = cosine;	mat._12 = sine;
		mat._21 = -sine;	mat._22 = cosine;

		return mat;
	}

	// Calculates the matrices determinate
	float Matrix3::Determinate(const Matrix3& refMatrix)
	{
		float determinate = 0.0f;
		for (int offset = 0; offset < DIM; offset++)
		{
			float plus = 1.0f;
			float minus = 1.0f;
			for (int row = 0, col = offset; row < DIM; row++, (col = (row + offset) % DIM))
			{
				plus *= refMatrix.m[row][col];
				minus *= refMatrix.m[(DIM - 1) - row][col];
			}
			determinate += plus - minus;
		}

		return determinate;
	}
#pragma endregion

#pragma region Operator Overloads
	Matrix3 Matrix3::operator*(const Matrix3& refMatrix) const
	{
		Matrix3 mat;

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

	Matrix3& Matrix3::operator*=(const Matrix3& refMatrix)
	{
		return ((*this) = (*this) * refMatrix);
	}

	// Inversion Operator - What a pain in the ass this one is
	Matrix3 Matrix3::operator-() const
	{
		float determinate = Determinate();

		Matrix3 mat {
			Matrix2::Determinate({_22, _23, _32, _33}) / determinate,
			-Matrix2::Determinate({_21, _23, _31, _33}) / determinate,
			Matrix2::Determinate({_21, _22, _31, _32}) / determinate,

			-Matrix2::Determinate({_12, _13, _32, _33}) / determinate,
			Matrix2::Determinate({_11, _13, _31, _33}) / determinate,
			-Matrix2::Determinate({_11, _12, _31, _32}) / determinate,

			Matrix2::Determinate({_12, _13, _22, _23}) / determinate,
			-Matrix2::Determinate({_11, _13, _21, _23}) / determinate,
			Matrix2::Determinate({_11, _12, _21, _22}) / determinate
		};
		mat.Transpose();

		return mat;
	}

	// Cast to Float Operator
	Matrix3::operator float*()
	{
		return (float*)m;
	}
#pragma endregion

}