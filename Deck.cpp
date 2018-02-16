#include "Deck.h"
#include "Card.h"
#include <iostream>
#include<ctime>
using namespace std;

Deck::Deck() {
	char suit[] = { 'S','C','H','D' };
	char rank[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q' , 'K' };
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			storage[count].setCard(suit[i], rank[j]);
			count++;
		}
	}
}

void Deck::RefreshDeck() {

	char suit[] = { 'S','C','H','D' };
	char rank[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q' , 'K' };
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			storage[count].setCard(suit[i], rank[j]);
			count++;
		}
	}
}

	Card Deck::deal() {
		Card card1 = storage[topCard];
		storage[topCard].setCard('\0','\0');
		topCard++;
		return card1; 
}
	
void Deck::shuffle()
{
	srand(time(0));
	int a, b;
	topCard = 52;
	for (int i = 0; i < topCard; i++) {
		a = rand() % topCard;
		b = rand() % topCard;
		Card c1 = storage[a];
		storage[a] = storage[b];
		storage[b] = c1;

	}
}
	
void Deck::showDeck() {
	int count = 1;
		for (int i = 0; i < 52; i++) {
			 storage[i].showCard();
			 if (count == 13) 
			 {
				 cout << endl;
				 count = 1;
			 }
			 else {
				 cout << ' ';
				 count++;
			 }
		}
	}


