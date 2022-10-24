#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

#include "KemalCankurt.h"
#include "MonthlyBalance.h"
#include "BalanceCalculator.h"

using namespace std;

int main()
{
	// setting initial user command value to 'Y' so loop may continue for the initial call
	char userCommand = 'Y';

	// user may continue as long as they want
	while (userCommand == 'Y' || userCommand == 'y')
	{
		//declare all the required fields here
		int years = 0;
		float openingAmount = 0;
		float monthlyDeposit = 0;
		float interestRate = 0;

		//Show the form to the user
		cout << "**********************************************************************\n";
		cout << "*************************** Data Input *******************************\n";
		cout << "Initial Investment Amount: \n";
		cout << "Monthly Deposit: \n";
		cout << "Annual Interest: \n";
		cout << "Number of years: \n";

		//Wait until the user wants to continue
		system("PAUSE");

		//Get inputs from the user
		cout << "**********************************************************************\n";
		cout << "*************************** Data Input *******************************\n";
		cout << "Initial Investment Amount: $";
		cin >> openingAmount;
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << "Annual Interest: %";
		cin >> interestRate;
		cout << "Number of years: ";
		cin >> years;

		//Wait for input from user
		system("PAUSE");

		// generate the calculator here based on the given inputs
		BalanceCalculator balanceCalculator(years, openingAmount, monthlyDeposit, interestRate);

		// run the calculation to populate monthly balance lists
		balanceCalculator.Calculate();

		// print monthly balances without any deposit
		balanceCalculator.Print(balanceCalculator.GetMonthlyBalancesWithoutDeposits(), false);

		// print monthly balances with any deposit
		balanceCalculator.Print(balanceCalculator.GetMonthlyBalances(), true);

		//Wait for input from user
		system("PAUSE");

		// ask whether the user wants to continue or not
		cout << "Would you like to try with different input (Y/N) ? ";
		// get the user command
		cin >> userCommand;
	}

	return 0;
}