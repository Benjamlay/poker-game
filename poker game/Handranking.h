#ifndef HANDRANKING_H
#define HANDRANKING_H
#include <string>
#include <vector>
#include "player.h"
#include "table.h"
#include "card.h"
#include <set>

enum class HandRanking
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
	Royal_Flush
};

class Hand
{
	std::vector<Card> CombinedHandAndTable_;

public:

	Hand() = default;
	Hand(std::vector<Card>CombinedHandAndTable) : CombinedHandAndTable_(CombinedHandAndTable) {}

	std::vector<Card>CombinedHandAndTable(player& player, Table& table);
	std::string hand_to_string(HandRanking hand);

	bool is_pair();
	bool is_two_pair();
	bool is_three_Of_A_Kind();
	bool is_straight();
	bool is_flush();
	bool is_fullHouse();
	bool is_four_of_a_kind();
	bool is_straight_flush();
	bool is_royal_flush();


	void best_hand(HandRanking hand);
};

HandRanking hand_to_Handranking(Hand& hand);


#endif // HANDRANKING_H
