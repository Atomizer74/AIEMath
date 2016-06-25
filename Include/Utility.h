/*
Copyright © 2016 Jonathan Shirlaw

File: Utility.h
Author: Jonathan Shirlaw
Date: 02/06/2016

Purpose: This contains various standalone functions and constants that do not long in its own class.
*/
#pragma once


namespace Math
{
	/************************
	*	    Constants       *
	************************/
	const float PI = 3.14159265359f;


	/************************
	*	    Typedefs        *
	************************/
	typedef unsigned char byte;


	/************************
	*	Utility Functions   *
	************************/

	// Returns true if the nth bit is 1, starting from the 0th position
	template <typename T>
	bool IsBitSet(const T value, const byte checkBit)
	{
		byte bitCount = sizeof(T) * 8;

		// Make sure the checkBit falls within the values range of bits
		if (checkBit >= bitCount)
			return false;

		// Check the specified bit within the value
		bool isBitSet = (value & (0x1LL << checkBit)) != 0;

		return isBitSet;
	}

	// Returns a null terminated char array of the binary
	template <typename T>
	const char* BinaryToString(const T value)
	{
		// Our static storage of the string so we don't lose the memory
		// or force the client application to have to clean up the memory
		// Might not be the best solution but it...works?
		static char outputString[(sizeof(T) * 8) + 1];

		// Cap the end of the string with a null terminator
		outputString[sizeof(T) * 8] = '\0';

		// Our iterative variable
		unsigned long long bitPos = 0x1;
		for (byte i = (sizeof(T) * 8); i > 0; i--, bitPos <<= 1)
		{
			// Calculate a '1' or a '0'
			outputString[i - 1] = (((value & bitPos) != 0) ? '1' : '0');
		}

		return outputString;
	}

	// Swap Template Function
	template <typename T>
	void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}


	// Converter functions between Degrees and Radians
	float Deg2Rad(const float fDegrees);
	float Rad2Deg(const float fRadians);

	// Linear Interpolation
	float Lerp(float fP1, float fP2, float fAmount);

	// Clamp a value between a min and a max
	float Clamp(float fValue, float fMin, float fMax);
}
