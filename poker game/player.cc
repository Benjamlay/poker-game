#include "player.h"
#include "card.h"

#include <iostream>

void player::Display()
{
	std::cout << card1.to_string() << std::endl;
	std::cout << card2.to_string() << std::endl;
	std::cout << '\n';
}


int player::CardValues()
{
	{
		return(card1.PlayerValueCards(card2));
	}
}

