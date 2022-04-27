#include "Account.h"

Account::Account(const decimal<2>& first_amount, const currencies& currency,
	const string& account_id, const decimal<2>& limit)
{
	set_limit(limit);
	set_balance(first_amount);
	set_currency(currency);
	set_id(account_id);
}

string Account::get_currency() const
{
	switch (currency_)
	{
	case 'R': return "Ruble";
	case 'D': return "DollarUSA";
	case 'E': return "Euro";
	}
	return "";
}
