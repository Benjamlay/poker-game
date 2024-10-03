#ifndef TABLE_H
#define TABLE_H
#include <array>
#include "card.h"

class Table
{
	std::array<Card, 5> table_;
	int card_index_ = 0;

public:
	Table() = default;
	void table_draw(Card card);
	void Display();

};


#endif // TABLE_H
