#ifndef MONTHLY_BALANCE_H
#define MONTHLY_BALANCE_H

using namespace std;

class MonthlyBalance
{
private:
    float closingBalance;
    float interestAmount;
    int month;

public:
    MonthlyBalance(float closingBalance, float interestAmount, int month);
    ~MonthlyBalance();
    float GetClosingBalance();
    float GetInterestAmount();
    int GetMonth();
};

#endif
