#include "pch.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>


class DatabaseConnector {

public:
	virtual bool login(std::string username, std::string password) { return false; }
	virtual bool login2(std::string username, std::string password) { return false; }
	virtual bool logout(std::string username) { return true; }
	virtual int fetchRecord() { return -1; }
};

class MyDatabase {
	DatabaseConnector& dbc;

public:
	MyDatabase(DatabaseConnector& dbc) : dbc(dbc) {

	}

	int init(std::string username, std::string password) {
		if (rand() % 2) {
			if (dbc.login(username, password)) {
				std::cout << "[CONNECTION SUCCESS]\n";
				return 1;
			}
		}
		else {
			if (dbc.login2(username, password)) {
				std::cout << "[CONNECTION SUCCESS]\n";
				return 1;
			}
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
	MOCK_METHOD2(login2, bool(std::string username, std::string password));

};


TEST(MyDBTest, LoginTest) {
	// Arrange
	MockDBC dbc;
	MyDatabase db(dbc);
	// Here there is no expectation that this call has to be made and the number of times of call is also not monitored.
	// Instead, this will be invoked if the call (login) is invoked once or more, then it will return true by default.

	// This can be used when one function out of two is being called to do something.
	ON_CALL(dbc, login(testing::_, testing::_)).WillByDefault(testing::Return(true));
	ON_CALL(dbc, login2(testing::_, testing::_)).WillByDefault(testing::Return(true));

	//Act
	auto ret = db.init("USerName", "Password");

	// Assert
	EXPECT_EQ(ret, 1);
}