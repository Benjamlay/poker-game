#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"

class player
{
private:

	std::vector<Card> cards;


public:

	player(Card card1, Card card2)
	{
		cards.push_back(card1);
		cards.push_back(card2);
	}

	const Card& getCard1();
	const Card& getCard2();

	void Display();
	//int CardValues();
};


#endif // PLAYER_H
