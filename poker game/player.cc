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


void player::PlaceBet()
{
	int bet;
	std::cout << "bet something :\n";
	std::cin >> bet;
	system("cls");
	if(bet <= coinsLeft_)
	{
		coinsLeft_ -= bet;
		currentBet_ += bet;
		std::cout << "your bet : " << currentBet_ << std::endl;
		std::cout << "you have " << coinsLeft_ << " remaining" << std::endl;
	}
	else
	{
		std::cout << "not enough coins \n";
		!StillHasCoins();
	}
}
void player::Fold()
{
	std::cout << "Fold \n";
}
void player::Call(int& lastBet, int& pot)
{
	if(lastBet <= coinsLeft_)
	{
		coinsLeft_ -= lastBet;
		pot = lastBet + lastBet;
		system("cls");
		std::cout << "Call \n";
		std::cout << "you have " << coinsLeft_ << " remaining" << std::endl;
	}
}

void player::Raise(int& lastBet, int& pot)
{
	if(lastBet <= coinsLeft_)
	{
		std::cout << "how much do you want to bet ?" << std::endl;
		int raise;
		std::cin >> raise;
		if(raise <= coinsLeft_)
		{
			coinsLeft_ -= raise;
			pot = raise + lastBet;
			system("cls");
			std::cout << "you have " << coinsLeft_ << " remaining" << std::endl;
		}
		else
		{
			std::cout << "not enough coins \n";
		}
	}
}
void player::AllIn(int& lastBet, int& pot)
{
	std::cout << "All in !! \n";
	pot + coinsLeft_;
	coinsLeft_ = 0;
	system("cls");
	std::cout << "you have " << coinsLeft_ << " remaining" << std::endl;
}

int Respond_To_Bet(player& player, int& lastBet, int& pot)
{
	int action;
	std::cout << "choose a number :\n1.Fold \n 2. Call \n 3. Raise \n 4. All in\n";
	std::cin >> action;
	switch(action)
	{
	case 1: player.Fold(); return 1;
	case 2: player.Call(lastBet, pot); return 2;
	case 3: player.Raise(lastBet, pot); return 3;
	case 4: player.AllIn(lastBet, pot); return 4;
	default: std::cout << "non valid Respond_To_Bet \n"; return 0;
	}

}
int Respond_to_Raise(player& player, int& lastBet, int& pot)
{
	int action;
	std::cout << "choose a number :\n1.Fold \n 2. Call\n";
	std::cin >> action;
	switch (action)
	{
	case 1: player.Fold(); return 1;
	case 2: player.Call(lastBet, pot); return 2;
	default: std::cout << "non valid Respond_To_Bet \n"; return 0;
	}
}




