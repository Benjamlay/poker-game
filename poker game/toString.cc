#include "enum hands.h"
#include <iostream>
#include <string>

std::string SuitToString(Suit suit)
{
	switch(suit)
	{
		case Suit::heart: return "hearts";
		case Suit::club: return "clubs";
		case Suit::spade: return "spades";
		case Suit::square: return "squares";
		default: return "?";
	}
	
}
std::string ValueToString(Value value)
{
	switch(value)
	{
	case Value::two: return "2";
	case Value::three: return "3";
	case Value::four: return "4";
	case Value::five: return "5";
	case Value::six: return "6";
	case Value::seven: return "7";
	case Value::height: return "8";
	case Value::nine: return "9";
	case Value::ten: return "10";
	case Value::jack: return "jack";
	case Value::queen: return "queen";
	case Value::king: return "king";
	case Value::ace: return "ace";
	default: return "doesn't exist";
	}
}

bool StillWantToPlay()
{
	char reponse;
	std::cout << "still want to play ? \n";
	std::cout << "Y or N ? \n";
	std::cin >> reponse;
	if (reponse == 'Y' || reponse == 'y')
	{
		std::cout << '\n';
		return true;
	}
	else if (reponse == 'N' || reponse == 'n')
	{
		return false;
	}
}