#include "pch.h"
#include <gtest/gtest.h>
#include <string>

class MyClass {
	int num;
public:
	MyClass(int n) {
		num = n;
	}

	void add(int x) {
		num += x;
	}

	int getNum() { return num; }
};

//TEST(Object, FirstTest) {
//	// Arrangement
//	MyClass m(100);			// The problem is here. everytime we are creating instances.. or similary some piece of code is duplicated everytime..
//
//	// Act
//	m.add(1);
//
//	// Validate
//	EXPECT_EQ(m.getNum(), 101); // works fine.
//}
//
//TEST(Object, SecondTest) {
//	// Arrangement
//	MyClass m(100);
//
//	// Act
//	m.add(2);
//
//	// Validate
//	EXPECT_EQ(m.getNum(), 102); // works fine.
//}
//
//TEST(Object, ThirdTest) {
//	// Arrangement
//	MyClass m(100);
//
//	// Act
//	m.add(3);
//
//	// Validate
//	EXPECT_EQ(m.getNum(), 103); // works fine.
//}


/*
	The Solution for code duplication.
*/


struct MyClassTest : public testing::Test {
	MyClass *obj;

public:
	void SetUp() override {
		obj = new MyClass(100);
	}
	void TearDown() override {
		delete obj;
	}
};

TEST_F(MyClassTest, FirstTest) {

	// Act
	obj->add(1);

	// Validate
	EXPECT_EQ(obj->getNum(), 101); // works fine.
}

TEST_F(MyClassTest, SecondTest) {

	// Act
	obj->add(2);

	// Validate
	EXPECT_EQ(obj->getNum(), 102); // works fine.
}

TEST_F(MyClassTest, ThirdTest) {

	// Act
	obj->add(3);

	// Validate
	EXPECT_EQ(obj->getNum(), 103); // works fine.
}