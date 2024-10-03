#include "table.h"
#include <iostream>

void Table::table_draw(Card card)
{
	table_[card_index_] = card;
	card_index_++;
}

void Table::Display()
{
	for(int i = 0; i < card_index_; i++)
	{
		std::cout << table_[i].to_string() << std::endl;
	}
}