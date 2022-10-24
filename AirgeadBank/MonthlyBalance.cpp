#include "MonthlyBalance.h"

using namespace std;

MonthlyBalance::MonthlyBalance(float closingBalance, float interestAmount, int month)
{
    this->closingBalance = closingBalance;
    this->interestAmount = interestAmount;
    this->month = month;
}

MonthlyBalance::~MonthlyBalance()
{
}

float MonthlyBalance::GetClosingBalance()
{
    return this->closingBalance;
}
float MonthlyBalance::GetInterestAmount()
{
    return this->interestAmount;
}

int MonthlyBalance::GetMonth()
{
    return this->month;
}