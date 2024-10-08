#include <array>
#include <iostream>

#include "enum hands.h"
#include "card.h"
#include "deck.h"
#include "Handranking.h"
#include "player.h"
#include "table.h"

int main()
{

	
	//mélanger le deck

	do
	{
		Table table;
		hands combinedHandAndTable;
		deck deck;
		deck.shuffle();

		//choix des cartes des joueurs
		player player1(deck.picka_card(), deck.picka_card());
		std::cout << "card player one :\n";
		std::cout << '\n';
		player1.Display();

		player player2(deck.picka_card(), deck.picka_card());
		std::cout << "card player two :\n";
		std::cout << '\n';
		player2.Display();
		std::cout << '\n';

		std::cout << "flop : \n";
		//tirer une carte sur la table
		table.table_draw(deck.picka_card());
		table.table_draw(deck.picka_card());
		table.table_draw(deck.picka_card());
		table.Display();
		std::cout << "\n\n";


		// phase de pari
		std::cout << "turn : \n";
		table.table_draw(deck.picka_card());
		table.Display();
		std::cout << "\n";

		// phase de pari
		std::cout << "river : \n";
		table.table_draw(deck.picka_card());
		table.Display();
		std::cout << "\n\n";

		combinedHandAndTable.CombinedHandAndTable(player1, table);
		if (combinedHandAndTable.is_pair())
		{
			std::cout << "you have a pair" << std::endl;
		}
		
	} while (StillWantToPlay());
	
	
	return 0;
	



}

