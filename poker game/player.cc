#include "player.h"
#include "card.h"

#include <iostream>

void player::Display()
{
	for (Card& card : cards)
	{
		std::cout << card.to_string() << std::endl;
	}
	std::cout << '\n';
}


const Card& player::getCard1()
{
	return cards[0];
}
const Card& player::getCard2()
{
	return cards[1];
}


//int player::CardValues()
//{
//	{
//		return(card1.PlayerValueCards(card2));
//	}
//}

