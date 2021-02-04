#include "pch.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>


class DatabaseConnector {

public:
	virtual bool login(std::string username, std::string password) { return false; }
	virtual bool logout(std::string username) { return true; }
	virtual int fetchRecord() { return -1; }
};

class MyDatabase {
	DatabaseConnector& dbc;

public:
	MyDatabase(DatabaseConnector& dbc) : dbc(dbc) {

	}

	int init(std::string username, std::string password) {
		if (dbc.login(username, password)) {
			std::cout << "[CONNECTION SUCCESS]\n";
			return 1;
		}
		std::cout << "[CONNECTION FAILURE]\n";
		return 1;
	}
};

/*
	Mock for database connector class

*/

class MockDBC : public DatabaseConnector {
public:
	// means, function which returns int and takes no argument. MOCK_METHOD0 0 in this means, this is not taking any input arguments.
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool(std::string username));
	MOCK_METHOD2(login, bool(std::string username, std::string password));

};

TEST(MyDBTest, LoginTest) {
	// Arrange
	MockDBC dbc;
	MyDatabase db(dbc);
	EXPECT_CALL(dbc, login("USerName", "Password"))	// telling that here, if this is the input for the function,,			// in this case, if the parameters are not correct, then it will fail. inorder to ignore the parameter values, use _ instead.
		// EXPECT_CALL(dbc, login(_,_))
		.Times(testing::AtLeast(1))					// and the function is being called atleast once (in this case),		// so here, the function is not called atleast once, then it will fail.
		.WillOnce(testing::Return(true));			// then return true once.

	//Act
	auto ret = db.init("USerName", "Password");

	// Assert
	EXPECT_EQ(ret, 1);
}


TEST(MyDBTest, LoginTest) {
	// Arrange
	MockDBC dbc;
	MyDatabase db(dbc);
	EXPECT_CALL(dbc, login("USerName", "Password"))	// telling that here, if this is the input for the function
		// EXPECT_CALL(dbc, login(_,_))
		.Times(testing::AtLeast(1))					// and the function is being called atleast once (in this case),
		.WillOnce(testing::Return(true));			// then return true once.

	//Act
	auto ret = db.init("USerName", "Password");

	// Assert
	EXPECT_EQ(ret, 1);
}