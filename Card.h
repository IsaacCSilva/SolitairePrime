#ifndef CARD_H
#define CARD_H
//#include<stdio.h>
#include<fcntl.h>
#include<Windows.h>

class Card {

private:
	char suit;
	char rank;

public:
	Card();
	Card(char suit, char rank);
	int getValue();
	void showCard();
	void setCard(char suit, char rank);
};

#endif
 