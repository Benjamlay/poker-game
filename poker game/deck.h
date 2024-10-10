#ifndef DECK_H
#define DECK_H
#include "card.h"
#include "enum hands.h"

class deck
{
public:

	std::vector<Card> deck_;

public:

	deck();

	void shuffle();

	bool isEmpty();

	Card picka_card();

	void displayAllDeck();



};

#endif DECK_H
