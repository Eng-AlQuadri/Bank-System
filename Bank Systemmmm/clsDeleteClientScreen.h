#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;


class clsDeleteClientScreen : protected clsScreen
{

public:

	static void showDeleteClientScreen() {

		_DrawScreenHeader("\t Delete Client Screen");

		string accountNumber;
		cout << "\n Enter Account Number: ";
		accountNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExsist(accountNumber)) {
			cout << "\n Account Number Not Found, Try Another One \n";
			accountNumber = clsInputValidate::readString();
		}

		clsBankClient client1 = clsBankClient::find(accountNumber);

		client1.print();

		cout << "\n Are You Sure You Want To Delete This Account y/n: ";
		char answer = 'n';
		cin >> answer;

		if (answer == 'y' || answer == 'Y') {

			if (client1.Delete()) {

				cout << "\n Client Deleted Successfully :-) \n";
				client1.print();
			}
			else {
				cout << "\n Error, Client Was Not Deleted \n";
			}
		}
	}
};

