#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"

class player
{
public:

	std::vector<Card> cards;
	int currentBet_;
	int coinsLeft_;

public:

	player(Card card1, Card card2)
	{
		cards.push_back(card1);
		cards.push_back(card2);
	}
	player(int currentBet, int coinleft) : currentBet_(currentBet), coinsLeft_(coinleft) {}

	const Card& getCard1();
	const Card& getCard2();
	void Display();
	void PlaceBet();
	void Fold();
	void Call(int& lastBet, int& pot);
	void Raise(int& lastBet, int& pot);
	void AllIn(int& lastBet, int& pot);

};
int Respond_To_Bet(player& player, int& LastBet, int& pot);
int Respond_to_Raise(player& player, int& lastBet, int& pot);

int cardsvalues(player& player);
#endif // PLAYER_H
