#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {

private:
	Card storage[52];
	int topCard = 51;

public:
	Deck();
	void shuffle();
	void showDeck();
	void RefreshDeck();
	Card deal();
};

#endif

