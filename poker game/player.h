#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"

class player
{
private:

	Card card1;
	Card card2;


public:

	player(Card one, Card two) : card1(one), card2(two){}
	

	void Display();
	int CardValues();
};


#endif // PLAYER_H
