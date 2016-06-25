/*
Copyright © 2016 Jonathan Shirlaw

File: MathLib.h
Author: Jonathan Shirlaw
Date: 17/06/2016

Purpose: Central Hub for MathLib
*/
#pragma once

// Includes
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

#include "Bezier.h"

#include "SceneGraph.h"
#include "Utility.h"

namespace Math
{
	// Typedefs
	typedef Vector2 vec2;
	typedef Vector3 vec3;
	typedef Vector4 vec4;

	typedef Matrix2 mat2;
	typedef Matrix3 mat3;
	typedef Matrix4 mat4;

	typedef Bezier<Vector2> Bezier2;
	typedef Bezier<Vector3> Bezier3;
	typedef Bezier<Vector4> Bezier4;

	// Cross Type Operator Overloads
	Vector2 operator*(const Vector2& refVector, const Matrix2& refMatrix);
	Vector2 operator*(const Matrix2& refMatrix, const Vector2& refVector);

	Vector3 operator*(const Vector3& refVector, const Matrix3& refMatrix);
	Vector3 operator*(const Matrix3& refMatrix, const Vector3& refVector);

	Vector4 operator*(const Vector4& refVector, const Matrix4& refMatrix);
	Vector4 operator*(const Matrix4& refMatrix, const Vector4& refVector);

	Vector2& operator*=(Vector2& refVector, const Matrix2& refMatrix);
	Vector2& operator*=(const Matrix2& refMatrix, Vector2& refVector);
	
	Vector3& operator*=(Vector3& refVector, const Matrix3& refMatrix);
	Vector3& operator*=(const Matrix3& refMatrix, Vector3& refVector);

	Vector4& operator*=(Vector4& refVector, const Matrix4& refMatrix);
	Vector4& operator*=(const Matrix4& refMatrix, Vector4& refVector);
}