#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsClientListScreen : protected clsScreen
{
private:

	static void PrintClientRecordLine(clsBankClient client) {

		cout << "| " << setw(15) << left << client.getAccountNumber();
		cout << "| " << setw(20) << left << client.fullname();
		cout << "| " << setw(12) << left << client.getPhone();
		cout << "| " << setw(20) << left << client.getEmail();
		cout << "| " << setw(10) << left << client.getPinCode();
		cout << "| " << setw(12) << left << client.getAccountBalance();
	}

public:

	static void showClientsList() {

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string title = "\t  Clients Screen";
		string subtitle = "\t    (" + to_string(vClients.size()) + ") clients";

		clsScreen::_DrawScreenHeader(title, subtitle);

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0) {
			cout << "\t\t\t\tNo Clients Available In The System\n";
		}
		else {

			for (clsBankClient client : vClients) {

				PrintClientRecordLine(client);
				cout << endl;
			}
		}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

	
};

