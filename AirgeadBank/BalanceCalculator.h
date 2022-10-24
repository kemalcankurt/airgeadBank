#ifndef BALANCE_CALCULATOR_H
#define BALANCE_CALCULATOR_H

using namespace std;

#include <vector>;
#include "MonthlyBalance.h"

class BalanceCalculator
{
private:
    vector<MonthlyBalance> monthlyBalances;
    vector<MonthlyBalance> monthlyBalancesWithoutDeposits;

    int years;
    float openingAmount;
    float monthlyDeposit;
    float interestRate;

    float CalculateInterestAmount(float openingAmount, float monthlyDeposit, float interestRate);
    MonthlyBalance CalculateMonthlyBalance(float openingAmount, float monthlyDeposit, float interestRate, int month);

public:
    BalanceCalculator(int years, float openingAmount, float monthlyDeposit, float interestRate);
    ~BalanceCalculator();

    vector<MonthlyBalance> GetMonthlyBalances();
    vector<MonthlyBalance> GetMonthlyBalancesWithoutDeposits();

    void Calculate();
    
    void Print(vector<MonthlyBalance> monthlyBalances, bool withDeposit);
};



#endif