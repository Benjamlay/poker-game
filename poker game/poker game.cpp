#include <array>
#include <iostream>
#include "enum hands.h"
#include "deck.h"
#include "Handranking.h"
#include "intro.h"
#include "player.h"
#include "table.h"

int main()
{
	intro();
	do
	{
		Table table;
		deck deck;
		deck.shuffle();

		player player1(deck.picka_card(), deck.picka_card());
		player1.coinsLeft_ = 1000;
		std::cout << "______________________________card player one :______________________________\n";
		std::cout << '\n';
		player1.Display();

		player player2(deck.picka_card(), deck.picka_card());
		player2.coinsLeft_ = 1000;
		std::cout << "______________________________card player two :______________________________\n";
		std::cout << '\n';
		player2.Display();

		std::cout << '\n';
		// phase de pari
		player1.PlaceBet();
		int lastBet = player1.currentBet_;
		int pot = player1.currentBet_;
		std::cout << '\n';
		std::cout << "Player 2, your turn\n\n";
		int which_Bet = Respond_To_Bet(player2, lastBet, pot);
		if (which_Bet == 1)
		{
			continue;
		}
		else if (which_Bet == 3) {
			Respond_to_Raise(player2, lastBet, pot);
		}

		std::cout << "______________________________card player one :______________________________\n";
		std::cout << '\n';
		player1.Display();
		std::cout << "______________________________card player two :______________________________\n";
		std::cout << '\n';
		player2.Display();
		std::cout << "______________________________flop :______________________________\n";

		table.table_draw(deck.picka_card());
		table.table_draw(deck.picka_card());
		table.table_draw(deck.picka_card());
		table.Display();
		std::cout << "\n\n";

		player1.PlaceBet();
		std::cout << '\n';
		std::cout << "Player 2, your turn\n\n";
		if (Respond_To_Bet(player2, lastBet, pot) == 1)
		{
			continue;
		}
		else if (which_Bet == 3) {
			Respond_to_Raise(player2, lastBet, pot);
		}

		std::cout << "______________________________card player one :______________________________\n";
		std::cout << '\n';
		player1.Display();
		std::cout << "______________________________card player two :______________________________\n";
		std::cout << '\n';
		player2.Display();
		std::cout << "______________________________turn :______________________________ \n";
		table.table_draw(deck.picka_card());
		table.Display();
		std::cout << "\n";

		// phase de pari
		player1.PlaceBet();
		std::cout << '\n';
		std::cout << "Player 2, your turn\n\n";
		if (Respond_To_Bet(player2, lastBet, pot) == 1)
		{
			continue;
		}
		else if (which_Bet == 3) {
			Respond_to_Raise(player2, lastBet, pot);
		}

		std::cout << "______________________________card player one :______________________________\n";
		std::cout << '\n';
		player1.Display();
		std::cout << "______________________________card player two :______________________________\n";
		std::cout << '\n';
		player2.Display();
		std::cout << "______________________________river :______________________________ \n";
		table.table_draw(deck.picka_card());
		table.Display();
		std::cout << "\n\n";

		// phase de pari
		player1.PlaceBet();
		std::cout << '\n';
		std::cout << "Player 2, your turn\n\n";
		if (Respond_To_Bet(player2, lastBet, pot) == 1)
		{
			continue;
		}
		else if (which_Bet == 3) {
			Respond_to_Raise(player2, lastBet, pot);
		}

		Hand combinedHandAndTableP1;
		Hand combinedHandAndTableP2;
		combinedHandAndTableP1.CombinedHandAndTable(player1, table);
		HandRanking handrankingP1 = hand_to_Handranking(combinedHandAndTableP1);
		std::cout << '\n';
		std::cout << "player 1 : " << std::endl;
		combinedHandAndTableP1.hand_to_string(handrankingP1);

		combinedHandAndTableP2.CombinedHandAndTable(player2, table);
		HandRanking handrankingP2 = hand_to_Handranking(combinedHandAndTableP2);
		std::cout << '\n';
		std::cout << "player 2 : " << std::endl;
		combinedHandAndTableP1.hand_to_string(handrankingP2);
		std::cout << '\n';

		if (handrankingP1 > handrankingP2) {
			std::cout << "player 1 won \n";
		}
		else if (handrankingP1 < handrankingP2) {
			std::cout << "player 2 won \n";
		}
		else if (handrankingP1 == HandRanking::high_card && handrankingP2 == HandRanking::high_card) {
			if (cardsvalues(player1) > cardsvalues(player2)) {
				std::cout << "player 1 won \n";
			}
			else if (cardsvalues(player1) < cardsvalues(player2)) {
				std::cout << "player 2 won \n";
			}
		}
		else if (handrankingP1 == handrankingP2)
		{
			if (cardsvalues(player1) > cardsvalues(player2)) {
				std::cout << "player 1 won \n";
			}
			else if (cardsvalues(player1) < cardsvalues(player2)) {
				std::cout << "player 2 won \n";
			}
		}
		std::cout << '\n';
	} while (StillWantToPlay());
	return 0;
}

