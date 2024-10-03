#include "deck.h"

#include <iostream>

deck::deck()
{
	for (Value v = Value::two; v <= Value::Ace; v = static_cast<Value>(static_cast<int>(v) + 1))
	{
		for (Suit s = Suit::club; s <= Suit::spade; s = static_cast<Suit>(static_cast<int>(s) + 1))
		{
			deck_.emplace_back(static_cast<Value>(v), static_cast<Suit>(s));
			//deck_.push_back({ v, s });
		}
	}

}

void deck::shuffle()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(deck_.begin(), deck_.end(), std::default_random_engine(seed));
}
void deck::displayAllDeck()
{
	for (const Card& card : deck_)
		std::cout << card.to_string() << std::endl;

}

bool deck::isEmpty()
{
	return deck_.empty();
}

Card deck::picka_card()
{
	Card TopCard = deck_.back();
	deck_.pop_back();
	return TopCard;
}





