#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsDate.h"
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsMainScreen.h"

using namespace std;

void PrintClientRecordBalanceLine(clsBankClient client)
{

	cout << "| " << setw(15) << left << client.getAccountNumber();
	cout << "| " << setw(40) << left << client.fullname();
	cout << "| " << setw(12) << left << client.getAccountBalance();

}

void ShowTotalBalances()
{

	vector <clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double TotalBalances = clsBankClient::GetTotalBalances();

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsBankClient Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t\t\t   ( " << clsString::NumberToText(TotalBalances) << ")";
}


int main() {

	clsMainScreen::ShowMainMenu();

	return 0;
}