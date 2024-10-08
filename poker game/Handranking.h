#ifndef HANDRANKING_H
#define HANDRANKING_H
#include <string>
#include <vector>
#include "player.h"
#include "table.h"
#include "card.h"

enum class Hand
{
	high_card,
	one_pair,
	two_pair,
	three_of_a_kind,
	Straight,
	Flush,
	Full_House,
	Four_of_a_Kind,
	Straight_Flush,
	Royal_Flush,
};

class hands
{
	std::vector<Card> CombinedHandAndTable_;

public:

	hands() = default;
	hands(std::vector<Card>CombinedHandAndTable) : CombinedHandAndTable_(CombinedHandAndTable){}

	std::vector<Card>CombinedHandAndTable(player& player, Table& table);
	void Display();
	std::string hand_to_string(Hand hand);


	bool is_pair();
	bool is_two_pair();
	bool is_threeOfAKind();
	bool is_straight();
	bool is_flush();
	bool is_fullHouse();
	bool is_for_of_a_kind();
	bool is_straight_flush();
	bool is_royal_flush();
};




#endif // HANDRANKING_H
