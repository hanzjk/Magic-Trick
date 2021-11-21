#include <iostream>
#include "Magician.h"
using namespace std;


int main() {
	Card card1,card2,card3,card4,hiddenCard;
	int hop=0;

	Card cards[]={card1,card2,card3,card4}; //Store 4 cards into a Card array
	cout<<"Enter 4 cards: (Ex:10 of Hearts =10 of H , ACE of hearts = A of H)\n";
    for(int i=0;i<4;i++){
       cout<<"Card "<<i+1<<": "; //Get user input
       cards[i].getCard();
    }
   cout<<"\n\nHidden Card : ";
   hiddenCard=Card::findHidden(cards); 
   hiddenCard.print(); //Print the hidden Card
	return 0;
}
