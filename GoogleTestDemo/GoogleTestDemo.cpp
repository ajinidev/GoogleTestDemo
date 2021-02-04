#include "pch.h"
#include <gtest/gtest.h>

TEST(TestName, SubTestName_1) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(false);		// Assertion Failed. But execution will continue.

	ASSERT_FALSE(1 == 1);	// This will stop the execution [fatal assertion]

	std::cout << "this will not be printed";

	/*
		Other macros

		Equal				EXPECT_EX	ASSERT_EX
		NotEqual			EXPECT_NE	ASSERT_NE
		Less Than			EXPECT_LT	ASSERT_LT
		Less than Equal		EXPECT_LE	ASSERT_LE
		Greater Than		EXPECT_GT	ASSERT_GT
		Greater Than Equal	EXPECT_GE	ASSERT_GE

		Best practice : Keep single assersion in a test case even though multiple assersions can be added in one TC
	*/
}
