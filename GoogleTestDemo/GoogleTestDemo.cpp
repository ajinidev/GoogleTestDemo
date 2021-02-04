#include "pch.h"
#include <gtest/gtest.h>
#include <string>

/*
	Writing Unit test have 3 parts.
	- Arrange
	- Act
	- Assert

	Run extreamly fast, Independent and shall be self contained.

*/

TEST(MathTest, Addition) {
	// Arrangement
	int x = 10; int y = 15;

	// Act
	x += 5;

	// Validate
	EXPECT_EQ(x, y);
}

TEST(MathTest, Subtraction) {
	// Arrangement
	int x = 10; int y = 5;

	// Act
	x -= 5;

	// Validate
	EXPECT_EQ(x, y);
}
