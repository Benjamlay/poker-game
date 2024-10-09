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
int cardsvalues(player& player)
{
	return static_cast<int>(player.getCard1().value_) + static_cast<int>(player.getCard2().value_);
}
//bool player::operator<(player& other)
//{
//	 if(cardsvalues(this))
//	 {
//		 return true;
//	 }
//	 else
//	 {
//		 return false;
//	 }
//}


//int player::CardValues()
//{
//	{
//		return(card1.PlayerValueCards(card2));
//	}
//}

