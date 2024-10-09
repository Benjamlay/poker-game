

#include "Handranking.h"

std::string Hand::hand_to_string(HandRanking hand)
{
	switch(hand)
	{
	case HandRanking::high_card:  std::cout << "high card " << std::endl; return "high card ";
	case HandRanking::one_pair: std::cout << "one_pair" << std::endl; return "one_pair";
	case HandRanking::two_pair: std::cout << "two_pair" << std::endl; return "two_pair";
	case HandRanking::three_of_a_kind: std::cout << "three_of_a_kind" << std::endl; return "three_of_a_kind";
	case HandRanking::Straight: std::cout << "Straight" << std::endl; return "Straight";
	case HandRanking::Flush: std::cout << "Flush" << std::endl; return "Flush";
	case HandRanking::Full_House: std::cout << "Full_House" << std::endl; return "Full_House";
	case HandRanking::Four_of_a_Kind: std::cout << "Four_of_a_Kind " << std::endl; return "Four_of_a_Kind";
	case HandRanking::Straight_Flush: std::cout << "Straight_Flush" << std::endl; return "Straight_Flush";
	case HandRanking::Royal_Flush: std::cout << "Royal_Flush" << std::endl; return "Royal_Flush";
	default: std::cout << "don't know this hand" << std::endl; return "don't know this hand";
	}
}
std::vector<Card> Hand::CombinedHandAndTable(player& player, Table& table)
{

	CombinedHandAndTable_.push_back(player.getCard1());
	CombinedHandAndTable_.push_back(player.getCard2());

	const std::array<Card, 5> tableCards = table.GetTable();
	CombinedHandAndTable_.insert(CombinedHandAndTable_.end(), tableCards.begin(), tableCards.end());

	return CombinedHandAndTable_;
}


bool Hand::is_pair()
{
	for(int i = 0; i < CombinedHandAndTable_.size(); i++)
	{
		for(int j = i+1; j < CombinedHandAndTable_.size(); j++)
		{
			if (CombinedHandAndTable_[i].value_ == CombinedHandAndTable_[j].value_)
			{
				return true;
			}
		}
	}
	return false;
}

bool Hand::is_two_pair()
{
	std::vector<int> values(13, 0);

	for(Card& card : CombinedHandAndTable_)
	{
		values[static_cast<int>(card.value_) - static_cast<int>(Value::two)]++;
	}

	int pairfound = 0;

	for(int count : values)
	{
		if(count == 2)
		{
			pairfound++;
		}
	}

	if(pairfound >= 2)
	{
		return true;
	}

	return false;
}
bool Hand::is_three_Of_A_Kind()
{
	for (int i = 0; i < CombinedHandAndTable_.size(); i++)
	{
		for (int j = i + 1; j < CombinedHandAndTable_.size(); j++)
		{
			for (int k = j + 1; k < CombinedHandAndTable_.size(); k++)
			{
				if (CombinedHandAndTable_[i].value_ == CombinedHandAndTable_[j].value_ && CombinedHandAndTable_[j].value_ == CombinedHandAndTable_[k].value_)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Hand::is_straight()
{
	std::vector<int> values;
	for(Card& card : CombinedHandAndTable_)
	{
		values.push_back(static_cast<int>(card.value_));
	}

	//tri des cartes
	std::sort(values.begin(), values.end());


	for(int i = 1; i < values.size(); i++)
	{
		int followedNumbers = 1;
		if(values[i] == values[i - 1] + 1)
		{
			followedNumbers++;
			if(followedNumbers == 5)
			{
				return true;
			}
		}
		else if(values[i] != values[i - 1])
		{
			followedNumbers = 1;
		}
	}
	return false;
}

bool Hand::is_flush()
{
	std::vector<int> suits(4, 0);
	for (Card& card : CombinedHandAndTable_)
	{
		suits[static_cast<int>(card.suit_)]++;
	}

	for(int count : suits)
	{
		if(count >= 5)
		{
			return true;
		}
	}
	
	return false;
}

bool Hand::is_fullHouse()
{
	std::vector<int> values(13, 0);

	for(Card& card : CombinedHandAndTable_)
	{
		values[static_cast<int>(card.value_) - static_cast<int>(Value::two)]++;
	}

	bool is_pair = false;
	bool is_threeOfAKind = false;

	for(int count : values)
	{
		if(count == 3)
		{
			is_threeOfAKind = true;
		}
		else if(count == 2)
		{
			is_pair = true;
		}
	}
	if(is_pair && is_threeOfAKind)
	{
		return true;
	}

	return false;
}


bool Hand::is_four_of_a_kind()
{
	std::vector<int> values(13, 0);

	for(Card& card : CombinedHandAndTable_)
	{
		//int valueIdx = static_cast<int>(card.value_) - static_cast<int>(Value::two);
		//if(valueIdx >= 0)
		//{
		//	values[valueIdx]++;
		//}
		//else
		//{
		//	std::cout << "value idx fourOfAKind inférieur a zero \n";
		//}
		values[static_cast<int>(card.value_) - static_cast<int>(Value::two)]++;
	}


	for(int count : values)
	{
		if(count == 4)
		{
			return true;
		}
	}
	return false;
}

bool Hand::is_straight_flush()
{
	if(is_straight() && is_flush())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand::is_royal_flush()
{
	if (is_flush())
	{

		std::set<int> values;
		for (Card& card : CombinedHandAndTable_)
		{
			values.insert(static_cast<int>(card.value_));

		}

		//std::sort(values.begin(), values.end());

		if(values.find(static_cast<int>(Value::ten)) != values.end() && 
			values.find(static_cast<int>(Value::jack)) != values.end()&&
			values.find(static_cast<int>(Value::queen)) != values.end()&&
			values.find(static_cast<int>(Value::king)) != values.end()&&
			values.find(static_cast<int>(Value::ace)) != values.end())
		{
			return true;
		}
	}
	return false; 
}

HandRanking hand_to_Handranking(Hand& hand)
{

	if(hand.is_royal_flush())
	{

		return HandRanking::Royal_Flush;
	}
	else if (hand.is_straight_flush())
	{
		return HandRanking::Straight_Flush;
	}
	else if (hand.is_four_of_a_kind())
	{
		return HandRanking::Four_of_a_Kind;
	}
	else if (hand.is_fullHouse())
	{
		return HandRanking::Full_House;
	}
	else if (hand.is_flush())
	{
		return HandRanking::Flush;
	}
	else if (hand.is_straight())
	{
		return HandRanking::Straight;
	}
	else if (hand.is_three_Of_A_Kind())
	{
		return HandRanking::three_of_a_kind;
	}
	else if (hand.is_two_pair())
	{
		return HandRanking::two_pair;
	}
	else if (hand.is_pair())
	{
		return HandRanking::one_pair;
	}

	return HandRanking::high_card;
}


