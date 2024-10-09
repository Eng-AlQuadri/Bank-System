#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;


class clsAddNewClientScreen : protected clsScreen
{

private:
	static void readClientInfo(clsBankClient& client) {

		cout << "\n Enter First Name: ";
		client.setFirstName(clsInputValidate::readString());

		cout << "\n Enter Last Name: ";
		client.setLastName(clsInputValidate::readString());

		cout << "\n Enter Email: ";
		client.setEmail(clsInputValidate::readString());

		cout << "\n Enter Phone: ";
		client.setPhone(clsInputValidate::readString());

		cout << "\n Enter Password: ";
		client.setPinCode(clsInputValidate::readString());

		cout << "\n Enter Balance: ";
		client.setAccountBalance(clsInputValidate::readfloat());
	}

public:

	static void addNewClient() {

		clsScreen::_DrawScreenHeader("\t Add New Client Screen");

		string accountNumber = "";

		cout << "\n Enter Account Number: ";
		accountNumber = clsInputValidate::readString();

		while (clsBankClient::isClientExsist(accountNumber)) {
			cout << "\n Account Is Exist, Try Another One: ";
			accountNumber = clsInputValidate::readString();
		}

		clsBankClient newClient = clsBankClient::addNewClientObject(accountNumber);

		readClientInfo(newClient);

		clsBankClient::enSaveResults saveResults;

		saveResults = newClient.save();

		switch (saveResults) {
		case clsBankClient::enSaveResults::svSuccess: {
			cout << "\n Account Added Successfully :-) \n";
			newClient.print();
			break;
		}
		case clsBankClient::enSaveResults::svFalidEmptyObject: {
			cout << "\n Error, Account Was Not Save Because It's Empty :-( \n";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExist: {
			cout << "\n Error account was not saved because account number is used! \n";
			break;
		}

		}
	}

};

