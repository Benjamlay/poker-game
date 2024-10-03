#ifndef CARD_H
#define CARD_H
#include "enum hands.h"

class Card
{
public:

	Suit suit_;
	Value value_;

public:
	Card() = default;
	Card(Value v, Suit s) : value_(v), suit_(s)
	{
	}

	bool operator==(Card& other) const;
	

	bool operator>(Card& other) const;
	

	int PlayerValueCards(Card& other);
	

	std::string to_string() const;
	

};
#endif // CARD_H
