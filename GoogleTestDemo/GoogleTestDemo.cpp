#include "pch.h"
#include <iostream>
#include <gtest/gtest.h>


TEST(TestCaseName, SubTestName_1) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, SubTestName_2) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}