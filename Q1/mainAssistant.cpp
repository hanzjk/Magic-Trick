#include <iostream>
#include "Assistant.h"
using namespace std;
int main() {
	Card card1,card2,card3,card4,card5,cardHidden,cardReveal;Card *cardsArray;
	int hop=0;

	Card cards[]={card1,card2,card3,card4,card5}; //Store 5 cards into a Card array
	cout<<"Enter 5 cards: (Ex:10 of Hearts = 10 of H , ACE of Clubs = A of H )\n"; 
    for(int i=0;i<5;i++){
       cout<<"Card "<<i+1<<": "; //Get user input
       cards[i].getCard();
    }
     //SelectTwoCards function find two similiar cards and the return an array containing the hiiden card and the revealing card
	cardHidden=Card::selectTwoCards(cards)[0]; // Hidden card is decided 
	cardReveal=Card::selectTwoCards(cards)[1]; //Revealinf card is decided 
    hop=cardHidden.hopValue(cardReveal);
   
    cardsArray=cardHidden.getCardArray(cards,cardReveal); //This function find the smallest,medium & largest cards in the array and return the arrray excluding the hidden card
    cardsArray=Card::sortedArray(cardsArray,hop);//This function arrage the final sequence of cards in the array according to the hop value
    
    cout<<"\nHidden Card :";cardHidden.print();//Print the hidden card
	cout<<"\n\nOrder of the remaining cards :";
    for(int k=0;k<4;k++)  //Print the order of the remaining cards
		cardsArray[k].print();

	return 0;
}
