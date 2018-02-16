//Isaac Silva
//2/13/2018
//CECS 282 SEC - 05
//prog - 01 Solitaire Prime

#include<iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;


int IsPrime(int number) {
	if (number == 1) {
		return false;
	}
	for (int i = 2; i< number; i++)
	{
		if (number%i == 0)
			return false;
	}
	return true;
}
	
int main() {

	int choice;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "Welcome to Solitaire Prime Master Gold!\n";
	Deck deck1;
	Card card;
	int sum = 0;
	int manyHands = 0;
	int temp;
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "\n1)New Deck\n2)Display Deck\n3)Shuffle Deck\n4)Play Solitaire Prime\n5)Exit\n";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "New Deck is created!\n";
			deck1.RefreshDeck();
			break;
		case 2:
			deck1.showDeck();
			break;
		case 3:
			cout << "shuffling..." << endl;
			deck1.shuffle();
			break;
		case 4:
			for (int i = 0; i < 52; i++) {
				card = deck1.deal();
				card.showCard();
				sum = sum + card.getValue();
				temp = IsPrime(sum);
				if (temp == true) {
					cout << "(" << sum << ")";
					cout << "prime: " << sum << endl;
					sum = 0;
					manyHands++;
				}
				else {
					cout << "(" << sum << ")" << " ";
				}

				if (i == 51 && temp == true) {
				
					cout << "Winner in" << manyHands <<" hands!\n"<<endl;
				}
				else if (i == 51 && temp == false) {
				
					cout << sum << " Loser\n ";
				}
			}
			
			break;
		case 5:
			exit(0);
		default:
			cout << "Incorrect Choice\n";
			break;
			
		}
	}
	return 0;
}



