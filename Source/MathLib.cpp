/*
Copyright © 2016 Jonathan Shirlaw

File: MathLib.cpp
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Central Hub for MathLib
*/
#include "MathLib.h"

namespace Math
{

#pragma region Cross Type Operator Overloads
	
	// Vector2 * Matrix2
	Vector2 operator*(const Vector2& refVector, const Matrix2& refMatrix)
	{
		return Vector2 {
			(refVector.X * refMatrix._11) + (refVector.Y * refMatrix._21),
			(refVector.X * refMatrix._12) + (refVector.Y * refMatrix._22)
		};
	}

	// Matrix2 * Vector2
	Vector2 operator*(const Matrix2& refMatrix, const Vector2& refVector)
	{
		Matrix2 mat = refMatrix.GetTranspose();

		return Vector2 {
			(mat._11 * refVector.X) + (mat._12 * refVector.Y),
			(mat._21 * refVector.X) + (mat._22 * refVector.Y)
		};
	}

	// Vector3 * Matrix3
	Vector3 operator*(const Vector3& refVector, const Matrix3& refMatrix)
	{
		Vector3 vec;

		for (int col = 0; col < refMatrix.DIM; col++)
		{
			float res = 0.0f;

			for (int i = 0; i < refMatrix.DIM; i++)
			{
				res += (refVector.v[i] * refMatrix.m[i][col]);
			}

			vec.v[col] = res;
		}

		return vec;
	}

	// Matrix3 * Vector3
	Vector3 operator*(const Matrix3& refMatrix, const Vector3& refVector)
	{
		// Need to get a transposed version of the matrix first
		Matrix3 mat = refMatrix.GetTranspose();

		return Vector3 {
			(mat._11 * refVector.X) + (mat._12 * refVector.Y) + (mat._13 * refVector.Z),
			(mat._21 * refVector.X) + (mat._22 * refVector.Y) + (mat._23 * refVector.Z),
			(mat._31 * refVector.X) + (mat._32 * refVector.Y) + (mat._33 * refVector.Z)
		};
	}

	// Vector4 * Matrix4
	Vector4 operator*(const Vector4& refVector, const Matrix4& refMatrix)
	{
		return Vector4 {
			(refVector.X * refMatrix._11) + (refVector.Y * refMatrix._21) + (refVector.Z * refMatrix._31) + (refVector.W * refMatrix._41),
			(refVector.X * refMatrix._12) + (refVector.Y * refMatrix._22) + (refVector.Z * refMatrix._32) + (refVector.W * refMatrix._42),
			(refVector.X * refMatrix._13) + (refVector.Y * refMatrix._23) + (refVector.Z * refMatrix._33) + (refVector.W * refMatrix._43),
			(refVector.X * refMatrix._14) + (refVector.Y * refMatrix._24) + (refVector.Z * refMatrix._34) + (refVector.W * refMatrix._44)
		};
	}

	// Matrix4 * Vector4
	Vector4 operator*(const Matrix4& refMatrix, const Vector4& refVector)
	{
		// Need to get a transposed version of the matrix first
		Matrix4 mat = refMatrix.GetTranspose();

		return Vector4 {
			(mat._11 * refVector.X) + (mat._12 * refVector.Y) + (mat._13 * refVector.Z) + (mat._14 * refVector.W),
			(mat._21 * refVector.X) + (mat._22 * refVector.Y) + (mat._23 * refVector.Z) + (mat._24 * refVector.W),
			(mat._31 * refVector.X) + (mat._32 * refVector.Y) + (mat._33 * refVector.Z) + (mat._34 * refVector.W),
			(mat._41 * refVector.X) + (mat._42 * refVector.Y) + (mat._43 * refVector.Z) + (mat._44 * refVector.W)
		};
	}



	Vector2& operator*=(Vector2& refVector, const Matrix2& refMatrix)
	{
		return (refVector = refVector * refMatrix);
	}

	Vector2& operator*=(const Matrix2& refMatrix, Vector2& refVector)
	{
		return (refVector = refMatrix * refVector);
	}


	Vector3& operator*=(Vector3& refVector, const Matrix3& refMatrix)
	{
		return (refVector = refVector * refMatrix);
	}

	Vector3& operator*=(const Matrix3& refMatrix, Vector3& refVector)
	{
		return (refVector = refMatrix * refVector);
	}


	Vector4& operator*=(Vector4& refVector, const Matrix4& refMatrix)
	{
		return (refVector = refVector * refMatrix);
	}

	Vector4& operator*=(const Matrix4& refMatrix, Vector4& refVector)
	{
		return (refVector = refMatrix * refVector);
	}

#pragma endregion
}