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
	case Value::two: return "Two";
	case Value::three: return "Three";
	case Value::four: return "four";
	case Value::five: return "five";
	case Value::six: return "six";
	case Value::seven: return "seven";
	case Value::height: return "eight";
	case Value::nine: return "nine";
	case Value::ten: return "ten";
	case Value::jack: return "jack";
	case Value::queen: return "queen";
	case Value::king: return "king";
	case Value::Ace: return "ace";
	default: return "doesn't exist";
	}
}