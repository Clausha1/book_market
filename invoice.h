#ifndef _INVOICE_H_
#define _INVOICE_H_
#include <vector>
#include "book.h"
using namespace std;
class Invoice
{
private:
    vector<Book> income;
    vector<Book> outcome;
public:
    void SetIncome(Book b);
    bool IsIncomeEmpty();
    void SetOutcome(Book b);
    bool IsOutcomeEmpty();
    vector<Book> GetIncome();
    vector<Book> GetOutcome();
};

#endif // INVOICE

