#include "pch.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>


class DatabaseConnector {

public:
	virtual bool login(std::string username, std::string password) { return true; }
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
	DatabaseConnector actualConnector;

	// here, we can invoke a single function inside the actual implementation as well.
	// ON_CALL(dbc, login(testing::_, testing::_)).WillByDefault(testing::Invoke(&actualConnector, &DatabaseConnector::login));

	EXPECT_CALL(dbc, login(testing::_, testing::_)).Times(1).WillOnce(testing::Invoke(&actualConnector, &DatabaseConnector::login));

	//Act
	auto ret = db.init("USerName", "Password");

	// Assert
	EXPECT_EQ(ret, 1);
}