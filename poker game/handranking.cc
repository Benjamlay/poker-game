#include "Handranking.h"

std::string hands::hand_to_string(Hand hand)
{
	switch(hand)
	{
	case Hand::high_card: return "high card";
	case Hand::one_pair: return "one_pair";
	case Hand::two_pair: return "two_pair";
	case Hand::three_of_a_kind: return "three_of_a_kind";
	case Hand::Straight: return "Straight";
	case Hand::Flush: return "Flush";
	case Hand::Full_House: return "Full_House";
	case Hand::Four_of_a_Kind: return "Four_of_a_Kind";
	case Hand::Straight_Flush: return "Straight_Flush";
	case Hand::Royal_Flush: return "Royal_Flush";
	default: return "don't know this hand";
	}
}

bool hands::is_flush()
{
	
}