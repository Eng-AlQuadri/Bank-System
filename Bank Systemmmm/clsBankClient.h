#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsBankClient : public clsPerson {

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode Mode;

	string accountNumber;
	string pinCode;
	float accountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#") {

		vector <string> vClientData;
		vClientData = clsString::Split(line, seperator);

		return clsBankClient(vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]), enMode::UpdateMode);
	}

	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient("", "", "", "", "", "", 0, enMode::EmptyMode);
	}

	static string _ConvertClientObjectToLine(clsBankClient client, string seperator = "#//#") {
		string stClientRecord;
		stClientRecord += client.getFirstName() + seperator;
		stClientRecord += client.getLastName() + seperator;
		stClientRecord += client.getEmail() + seperator;
		stClientRecord += client.getPhone() + seperator;
		stClientRecord += client.getAccountNumber() + seperator;
		stClientRecord += client.getPinCode() + seperator;
		stClientRecord += to_string(client.getAccountBalance()) + seperator;

		return stClientRecord;
	}

	static vector <clsBankClient> _LoadClientsDataFromFile() {

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {

				clsBankClient client1 = _ConvertLineToClientObject(line);

				vClients.emplace_back(client1);
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string dataLine;

		if (MyFile.is_open()) {

			for (clsBankClient& c : vClients) {

				if (c._MarkedForDelete == true)
					continue;

				dataLine = _ConvertClientObjectToLine(c);
				MyFile << dataLine << endl;
			}
		}
		MyFile.close();  ////check that
	}

	void _AddDataLineToFile(string stDataLine) {

		fstream MyFile;
		MyFile.open("Clients.txt",ios::app);

		if (MyFile.is_open()) {

			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	void _Update() {

		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& c : _vClients) {

			if (c.accountNumber == accountNumber) {

				c = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

public:
	clsBankClient(string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float accountBalance, enMode Mode) : clsPerson(firstName, lastName, email, phone) {

		this->accountNumber = accountNumber;
		this->pinCode = pinCode;
		this->accountBalance = accountBalance;
		this->Mode = Mode;
	}

	bool isEmpty() {
		return (this->Mode == enMode::EmptyMode);
	}

	string getAccountNumber() {
		return this->accountNumber;
	}

	void setPinCode(string pinCode) {
		this->pinCode = pinCode;
	}

	string getPinCode() {
		return this->pinCode;
	}

	void setAccountBalance(float accountBalance) {
		this->accountBalance = accountBalance;
	}

	float getAccountBalance() {
		return this->accountBalance;
	}

	void print() {
		cout << "\n Client Card";
		cout << "\n____________________________________";
		cout << "\n First Name      : " << this->getFirstName();
		cout << "\n Last Name       : " << this->getLastName();
		cout << "\n Full Name       : " << this->fullname();
		cout << "\n Email           : " << this->getEmail();
		cout << "\n Phone           : " << this->getPhone();
		cout << "\n Account Number  : " << this->getAccountNumber();
		cout << "\n Password        : " << this->getPinCode();
		cout << "\n Balance         : " << this->getAccountBalance();
		cout << "\n____________________________________" << endl;
	}

	static clsBankClient find(string accountNumber) {

		fstream myFile;
		myFile.open("Clients.txt", ios::in);

		if (myFile.is_open()) {

			string line;

			while (getline(myFile, line)) {

				clsBankClient client = _ConvertLineToClientObject(line);

				if (client.accountNumber == accountNumber) {
					myFile.close();
					return client;
				}
			}
			myFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool isClientExsist(string accountNumber) {

		clsBankClient client1 = clsBankClient::find(accountNumber);

		return (!client1.isEmpty());
	}

	enum enSaveResults { svFalidEmptyObject = 0, svSuccess = 1, svFaildAccountNumberExist = 2 };

	enSaveResults save() {

		switch (Mode) {
		case enMode::EmptyMode:
		{
			return enSaveResults::svFalidEmptyObject;
			break;
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSuccess;
			break;
		}

		case enMode::AddNewMode: {
			if (clsBankClient::isClientExsist(accountNumber)) {
				return enSaveResults::svFaildAccountNumberExist;
			}

			_AddNew();

			Mode = enMode::UpdateMode;
			return enSaveResults::svSuccess;

			break;
		}

		}
		return enSaveResults::svSuccess;
	}

	static clsBankClient addNewClientObject(string accountNumber) {
		return clsBankClient("", "", "", "", accountNumber, "", 0, enMode::AddNewMode);
	}

	bool Delete() {
		vector <clsBankClient> _vClients;

		_vClients = _LoadClientsDataFromFile();


		for (clsBankClient& c : _vClients) {

			if (c.getAccountNumber() == this->accountNumber) { ////Check For That

				c._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList() {

		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances() {

		vector <clsBankClient> vClients = GetClientsList();

		double totalBalances = 0;

		for (clsBankClient& Client : vClients) {

			totalBalances += Client.getAccountBalance();
		}

		return totalBalances;
	}
};