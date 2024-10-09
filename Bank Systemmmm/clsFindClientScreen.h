#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
{

public :

	static void showFindClientScreen() {

		_DrawScreenHeader("\t Find Client Screen");

		string accountNumber = "";
		cout << "\n Enter Account Number: ";

		accountNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExsist(accountNumber)) {
			cout << "\n Not Found, Try Another One: ";
			accountNumber = clsInputValidate::readString();
		}

		clsBankClient client1 = clsBankClient::find(accountNumber);

		if (!client1.isEmpty()) {

			cout << "\n Client Found \n";

			client1.print();
		}
	}

};

