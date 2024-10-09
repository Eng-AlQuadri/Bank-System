#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

private:

	static void updateClientData(clsBankClient& client) {

		cout << "\n What Do You Want To Update??" << endl;
		cout << "[1] For First Name \n"
			<< "[2] For Last Name \n"
			<< "[3] For Email \n"
			<< "[4] For Phone \n"
			<< "[5] For Password \n"
			<< "[6] For Balance \n"
			<< "[7] For All \n";

		short choose;
		cin >> choose;

		switch (choose) {
		case 1:
		{
			cout << "\n Enter First Name: ";
			client.setFirstName(clsInputValidate::readString());
			break;
		}
		case 2:
		{
			cout << "\n Enter Last Name: ";
			client.setLastName(clsInputValidate::readString());
			break;
		}
		case 3:
		{
			cout << "\n Enter Email: ";
			client.setEmail(clsInputValidate::readString());
			break;
		}
		case 4:
		{
			cout << "\n Enter Phone: ";
			client.setPhone(clsInputValidate::readString());
			break;
		}
		case 5:
		{
			cout << "\n Enter Password: ";
			client.setPinCode(clsInputValidate::readString());
			break;
		}
		case 6:
		{
			cout << "\n Enter Balance: ";
			client.setAccountBalance(clsInputValidate::readfloat());
			break;
		}
		case 7:
		{
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

			break;
		}

		}
	}

public:

	static void updateClient() {

		_DrawScreenHeader("\t Update Client");

		string accountNumber = "";

		cout << "\n Please Enter Client Account Number: ";
		accountNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExsist(accountNumber)) {
			cout << "\n Account Number Is Not Fount, Choose Another One: ";
			accountNumber = clsInputValidate::readString();
		}

		clsBankClient client1 = clsBankClient::find(accountNumber);
		client1.print();

		cout << "\n\n Update Client Info";
		cout << "\n______________________\n";

		updateClientData(client1);

		clsBankClient::enSaveResults saveResults;

		saveResults = client1.save();

		switch (saveResults) {
		case clsBankClient::enSaveResults::svSuccess: {
			cout << "\n Account Updated Successfully :-) \n";
			client1.print();
			break;
		}
		case clsBankClient::enSaveResults::svFalidEmptyObject: {
			cout << "\n Error Account Was Not Saved Because It's Empty \n";
			break;
		}

		}

	}

};

