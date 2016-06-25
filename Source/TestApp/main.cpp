/*
Copyright © 2016 Jonathan Shirlaw

File: main.cpp
Author: Jonathan Shirlaw
Date: 02/06/2016

Purpose: Entry point to the test application
*/

// Project Includes
#include "MathLib.h"

// Declare we are using these from the Math Library
using Math::byte;
using Math::Vector2;
using Math::Matrix3;

// Standard Includes
#include <iostream>

// Declare that we are using these from the STL
using std::cout;
using std::endl;
using std::cin;

// Definition of OnExit
void OnExit();


// Main Entrypoint
int main()
{
	atexit(&OnExit);


	return 0;
}


#pragma region Utility Functions
// Declaration of our OnExit Function
void OnExit()
{
	cin.get();
}
#pragma endregion