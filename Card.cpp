#include "Card.h"

Card::Card(const pay_systems& pay_system)
{
	set_pay_system(pay_system);
}

string Card::get_currency() const
{
	if (my_account_ != nullptr)
		return my_account_->get_currency();
	else
		return "";
}

string Card::get_pay_system() const
{
	switch (pay_system_)
	{
	case 'L': return "Lisa";
	case 'M': return "MasterBard";
	case 'H': return "HoMir";
	}
	return "";
}
