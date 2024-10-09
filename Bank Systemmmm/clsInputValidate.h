#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	static string readString() {

		string s1 = "";
		getline(cin >> ws, s1);
		return s1;
	}

	static float readfloat() {

		float number;
		cin >> number;
		return number;
	}

	static short readShort() {

		short number;
		cin >> number;
		return number;
	}

	static bool isNumberBetween(double number, double from, double to) {
		if (number > to || number < from)
			return false;
		return true;
	}

	static short readShortNumber(short from, short to, string errorMessage) {
		
		short number = readShort();

		while (!isNumberBetween(number, from, to)) {
			cout << errorMessage;
			number = readShort();
		}
		return number;
	}
};
