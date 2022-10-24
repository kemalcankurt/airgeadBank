using namespace std;

#include "BalanceCalculator.h"
#include <iostream>
#include <iomanip>


BalanceCalculator::BalanceCalculator(int years, float openingAmount, float monthlyDeposit, float interestRate)
{
	// set initial values 
	this->years = years;
	this->openingAmount = openingAmount;
	this->monthlyDeposit = monthlyDeposit;
	this->interestRate = interestRate;
}

BalanceCalculator::~BalanceCalculator()
{
	cout << "Calculation completed!" << endl;
}


// calculating interesting amount based on given values
float BalanceCalculator::CalculateInterestAmount(float openingAmount, float monthlyDeposit, float interestRate)
{
	return ((openingAmount + monthlyDeposit) * ((interestRate / 100) / 12));
}

// monthlyBalances getter
vector<MonthlyBalance> BalanceCalculator::GetMonthlyBalances()
{
	return this->monthlyBalances;
}

// monthlyBalancesWithoutDeposits getter
vector<MonthlyBalance> BalanceCalculator::GetMonthlyBalancesWithoutDeposits() {
	return this->monthlyBalancesWithoutDeposits;
}


// calculates monthly balance based on given values
MonthlyBalance BalanceCalculator::CalculateMonthlyBalance(float openingAmount, float monthlyDeposit, float interestRate, int month)
{
	float interestAmount = CalculateInterestAmount(openingAmount, monthlyDeposit, interestRate);

	float closingBalance = openingAmount + monthlyDeposit + interestAmount;

	MonthlyBalance monthlyBalance(closingBalance, interestAmount, month);

	return monthlyBalance;
}


// calculates balances and stores for every month
void BalanceCalculator::Calculate() {
	const int totalMonth = years * 12;

	// looping through every month to calculate closing amounts and earned interest
	for (int i = 0; i < totalMonth; i++)
	{
		// getting previous closing balance to include for interest calculation
		// if it is first month then there is no previous closing amount, so it should be assigned with
		// the initial amount
		float previousClosingBalance = (i == 0) ? openingAmount : this->monthlyBalances.at(i - 1).GetClosingBalance();

		// calculate monthly balance with deposit
		MonthlyBalance monthlyBalance = CalculateMonthlyBalance(previousClosingBalance, monthlyDeposit, interestRate, (i + 1));

		// save the monthly balance with deposit
		this->monthlyBalances.push_back(monthlyBalance);

		// getting previous monthly balance without deposit
		float previousClosingBalanceWithoutDeposit = (i == 0) ? openingAmount : this->monthlyBalancesWithoutDeposits.at(i - 1).GetClosingBalance();

		// calculate monthly balance without deposit
		MonthlyBalance monthlyBalanceWithoutDeposit = CalculateMonthlyBalance(previousClosingBalanceWithoutDeposit, 0, interestRate, (i + 1));

		// save the monthly balance without deposit
		this->monthlyBalancesWithoutDeposits.push_back(monthlyBalanceWithoutDeposit);
	}
}

// print given char value and repeat n times
string nCharString(int n, char c)
{
	string charResponse;

	// loop until size is reached and add given input to the response
	for (int i = 0; i < n; i++)
	{
		charResponse += c;
	}

	return charResponse;
}

// print the balance table with or without deposit
void BalanceCalculator::Print(vector<MonthlyBalance> monthlyBalances, bool withDeposit)
{
	// set the header value which printed before the table
	string header = withDeposit ? "Balance and Interest With Additional Monthly Deposits" : "Balance and Interest Without Additional Monthly Deposits";
	cout << "\n\t" << header << endl;

	// print = sign for header
	cout << nCharString(70, '=') << endl;

	// print balance table's header row
	cout << setw(10) << right << "Year" << setw(30) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest" << endl;

	// print - sign after header to seperate
	cout << nCharString(70, '-') << endl;

	// set total interest to 0 for further calculation
	float totalInterest = 0;


	// loop through given monthly balances to print yearly balance and earned interest
	for (int i = 0; i < monthlyBalances.size(); i++)
	{
		// get the earned interest per month
		totalInterest += monthlyBalances.at(i).GetInterestAmount();

		// if the current month can be divided with 12 without any remain value then it refers to a year
		if (monthlyBalances.at(i).GetMonth() % 12 == 0)
		{
			// print year, total balance, and earned interest per year based on the required format
			// setting custom width values based on the given table format
			cout
				<< setw(10)
				<< right
				<< (monthlyBalances.at(i).GetMonth() / 12)
				<< setw(23)
				<< right
				<< "$" << fixed << setprecision(2)
				<< monthlyBalances.at(i).GetClosingBalance()
				<< setw(24)
				<< right
				<< "$"
				<< totalInterest
				<< endl
				<< endl;
		}
	}
}

