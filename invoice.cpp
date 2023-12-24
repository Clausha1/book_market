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
  return income.empty();
}

bool Invoice::IsOutcomeEmpty()
{
  return outcome.empty();
}

vector<Book> Invoice::GetIncome()
{
  return income;
}

vector<Book> Invoice::GetOutcome()
{
  return outcome;
}
