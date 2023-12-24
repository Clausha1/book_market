#include "invoice.h"

void Invoice::SetIncome(Book b)
{
  income.push_back(b);
}

void Invoice::SetOutcome(Book b)
{
  outcome.push_back(b);
}

bool Invoice::IsIncomeEmpty()
{
  return !income.empty();
}

bool Invoice::IsOutcomeEmpty()
{
  return !outcome.empty();
}

vector<Book> Invoice::GetIncome()
{
  return income;
}

vector<Book> Invoice::GetOutcome()
{
  return outcome;
}

Invoice::~Invoice()
{
    for (vector<Book>::iterator it=income.begin(); it!=income.end(); it++)
    {
        delete &(*it);
    }

    for (vector<Book>::iterator it=outcome.begin(); it!=outcome.end(); it++)
    {
        delete &(*it);
    }
}
