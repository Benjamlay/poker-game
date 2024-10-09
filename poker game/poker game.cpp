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
	do
	{
		Table table;
		Hand combinedHandAndTableP1;
		Hand combinedHandAndTableP2;
		deck deck;
		deck.shuffle();

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

		combinedHandAndTableP1.CombinedHandAndTable(player1, table);
		HandRanking handrankingP1 = hand_to_Handranking(combinedHandAndTableP1);
		combinedHandAndTableP1.hand_to_string(handrankingP1);

		combinedHandAndTableP2.CombinedHandAndTable(player2, table);
		HandRanking handrankingP2 = hand_to_Handranking(combinedHandAndTableP2);
		combinedHandAndTableP1.hand_to_string(handrankingP2);

		if(handrankingP1 > handrankingP2)
		{
			std::cout << "player 1 won \n";
		}
		else if(handrankingP1 < handrankingP2)
		{
			std::cout << "player 2 won \n";
		}
		else if(handrankingP1 == handrankingP2)
		{
			if(cardsvalues(player1) > cardsvalues(player2))
			{
				std::cout << "player 1 won \n";
			}
			else if (cardsvalues(player1) < cardsvalues(player2))
			{
				std::cout << "player 2 won \n";
			}
		}
	} while (StillWantToPlay());

	
	
	return 0;
	



}

