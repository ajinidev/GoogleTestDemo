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


class MyClass {
	std::string id;
public:
	MyClass(std::string z) {
		id = z;
	}

	std::string getId() { return id; }
};

TEST(Object, FirstTest) {
	// Arrangement
	MyClass m("test");

	// Act
	auto id = m.getId();

	// Validate
	EXPECT_EQ(id, "test"); // works fine.
	EXPECT_STREQ(id.c_str(), "test"); // works fine.
	//EXPECT_EQ(id.c_str(), "test"); // fails.



	/*
		Types of string asserssions.
		Equal			EXPECT_STREQ		ASSERT_STREQ
		Not Equal		EXPECT_STRNE		ASSERT_STRNE
		Case Equal		EXPECT_STRCASEEQ	ASSERT_STRCASEEQ
		Case Not Equal	EXPECT_STRCASENE	ASSERT_STRCASENE
	*/
}