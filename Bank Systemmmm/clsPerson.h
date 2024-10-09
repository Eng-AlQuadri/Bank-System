#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson {

private:

	string firstName;
	string lastName;
	string email;
	string phone;

public:

	clsPerson(string firstName, string lastName, string email, string phone) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->phone = phone;
	}

	void setFirstName(string firstName) {
		this->firstName = firstName;
	}

	string getFirstName() {
		return this->firstName;
	}

	void setLastName(string lastName) {
		this->lastName = lastName;
	}

	string getLastName() {
		return this->lastName;
	}

	void setEmail(string email) {
		this->email = email;
	}

	string getEmail() {
		return this->email;
	}

	void setPhone(string phone) {
		this->phone = phone;
	}

	string getPhone() {
		return this->phone;
	}

	//return full name
	string fullname() {
		return this->firstName + " " + this->lastName;
	}

};
