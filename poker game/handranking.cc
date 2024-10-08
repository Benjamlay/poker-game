#include <set>

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
std::vector<Card> hands::CombinedHandAndTable(player& player, Table& table)
{
	//std::vector<Card> CombinedHand;

	CombinedHandAndTable_.push_back(player.getCard1());
	CombinedHandAndTable_.push_back(player.getCard2());

	const std::array<Card, 5> tableCards = table.GetTable();
	CombinedHandAndTable_.insert(CombinedHandAndTable_.end(), tableCards.begin(), tableCards.end());

	return CombinedHandAndTable_;
}

void hands::Display()
{
	for(Card& card : CombinedHandAndTable_)
	{
		std::cout << card.to_string() << std::endl;
	}
}

bool hands::is_pair()
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

bool hands::is_two_pair()
{
	std::vector<int> values(13, 0);

	for(Card& card : CombinedHandAndTable_)
	{
		values[static_cast<int>(card.value_)]++;
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
bool hands::is_threeOfAKind()
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

bool hands::is_straight()
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

bool hands::is_flush()
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

bool hands::is_fullHouse()
{
	std::vector<int> values(13, 0);

	for(Card& card : CombinedHandAndTable_)
	{
		values[static_cast<int>(card.value_)]++;
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


bool hands::is_for_of_a_kind()
{
	std::vector<int> values(13, 0);

	for(Card& card : CombinedHandAndTable_)
	{
		values[static_cast<int>(card.value_)]++;
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

bool hands::is_straight_flush()
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

bool hands::is_royal_flush()
{
	if (is_flush())
	{

		std::set<int> values;
		for (Card& card : CombinedHandAndTable_)
		{
			values.insert(static_cast<int>(card.value_));

		}

		std::sort(values.begin(), values.end());

		if(values.find(static_cast<int>(Value::ten)) != values.end() && 
			values.find(static_cast<int>(Value::jack)) != values.end()&&
			values.find(static_cast<int>(Value::queen)) != values.end()&&
			values.find(static_cast<int>(Value::king)) != values.end()&&
			values.find(static_cast<int>(Value::Ace)) != values.end())
		{
			return true;
		}
	}
	return false; 
}
	