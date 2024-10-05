#include <array>
#include <iostream>

#include "enum hands.h"
#include "card.h"
#include "deck.h"
#include "player.h"
#include "table.h"

int main()
{

	/* déroulement du jeu de poker :
	 *
	 * distribution des cartes
	 * mise de départ
	 * première carte sortie
	 * deuxième mise
	 * deuxième carte sortie
	 * dernière mise
	 * révelation des cartes */


	Table table;

	//mélanger le deck
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

	//qui gagne ?

	/*if(player1.CardValues() > player2.CardValues())
	{
		std::cout << "player 1 won \n";
	}
	else if(player1.CardValues() == player2.CardValues())
	{
		std::cout << "draw game \n";
	}
	else
	{
		std::cout << "player 2 won \n";
	}
	*/

	
	return 0;
	



}

