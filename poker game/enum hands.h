#ifndef ENUM_HANDS_H
#define ENUM_HANDS_H
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>



enum class Suit
{
	club,
	heart,
	square,
	spade,
};

enum class Value
{
	two = 2,
	three,
	four,
	five,
	six,
	seven,
	height,
	nine,
	ten,
	jack,
	queen,
	king,
	ace,

};

std::string SuitToString(Suit suit);
std::string ValueToString(Value value);

bool StillWantToPlay();




#endif // ENUM_HANDS_H