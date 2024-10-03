#ifndef HANDRANKING_H
#define HANDRANKING_H

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


public:

	void hand_to_string();
};
#endif // HANDRANKING_H
