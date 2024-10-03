

#include "card.h"

bool Card::operator==(Card& other) const
{
	return(this->suit_ == other.suit_ && this->value_ == other.value_);
}

bool Card::operator>(Card& other) const
{

	return(this->value_ > other.value_);
}

int Card::PlayerValueCards(Card& other)
{
	return(static_cast<int>(this->value_) + static_cast<int>(other.value_));
}

std::string Card::to_string() const
{
	return ValueToString(value_) + " of " + SuitToString(suit_);
}