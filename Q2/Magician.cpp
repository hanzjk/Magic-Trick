#include<iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include "Magician.h"
using namespace std;
Card::Card(){} //Default constructor

Card::Card(Value v,Suit s):value(v),suit(s){}  //Parameterized constructor

void Card::getCard()   {//Definition of function which is used to take cards from the user
	bool valid=true;
	while(valid==true){
	string valueName,of;char suitName; //Face value and the suit of the card is taken as user input.
	cin>>valueName>>of>>suitName;
			
	map<char,Suit> mapSuit; // A map with 'suit name' as the the key value and the 'enum 'as the mapped value
	mapSuit['C']=CLUBS;
	mapSuit['D']=DIAMONDS;
	mapSuit['H']=HEARTS;
	mapSuit['S']=SPADES;
			
	map<string,Value> mapValue; // A map with 'face value' as the the key value and the 'enum' as the mapped value
	mapValue["2"]=TWO;
	mapValue["3"]=THREE;
	mapValue["4"]=FOUR;
	mapValue["5"]=FIVE;
	mapValue["6"]=SIX;
    mapValue["7"]=SEVEN;
	mapValue["8"]=EIGHT;
	mapValue["9"]=NINE;
	mapValue["10"]=TEN;
    mapValue["J"]=JACK;
	mapValue["Q"]=QUEEN;
	mapValue["K"]=KING;
	mapValue["A"]=ACE;
			
	if(mapSuit.count(suitName)>0 && mapValue.count(valueName)>0){ //Check whether the user inputs exist in the maps
		suit=mapSuit[suitName]; //suitName is mapped with the declared map and the correspoding enum is returned to the suit.
		value=mapValue[valueName]; //valueName is mapped with the declared map and the correspoding enum is returned to the value.
		valid=false;
	}
			
	else{ 
		valid=true; //User is asked to enter again if the enterd inoputs are invalid
		cout<<"Invald:Enter again: ";
		}
	}
}
		
void Card:: print() const{  //Definition of function which is used to print cards
	switch(value){
		case 2: cout<<"TWO";break;
		case 3: cout<<"THREE";break; 
		case 4: cout<<"FOUR";break;
		case 5: cout<<"FIVE";break;
		case 6: cout<<"SIX";break;
		case 7: cout<<"SEVEN";break;
		case 8: cout<<"EIGHT";break;
		case 9: cout<<"NINE";break;
		case 10: cout<<"TEN";break; 
		case 11: cout<<"JACK";break;
		case 12: cout<<"QUEEN";break;
		case 13: cout<<"KING";break;
		case 1: cout<<"ACE";break;
		default:break;
	}
	cout<<" of ";
	switch(suit){
		case 0:cout<<"CLUBS";break;
		case 1:cout<<"HEARTS";break;
		case 2:cout<<"SPADES";break;
		case 3:cout<<"DIAMONDS";break;
		default:break;
	}
	cout<<setw(10);
}

bool Card:: operator ==(Card card2){  //Opertor == is overloaded to check the similiarity of two cards
	if (value==card2.value && suit==card2.suit)
		return true;
	return false;
}
	
bool Card::operator !=(Card card2){  //Operator != is overloaded 
	if (value!=card2.value && suit!=card2.suit)
		return true;
	return false;
}
	
	
Card Card:: findHidden(Card cards[4]){ //Function which is used to find the hidden Card
	Card hiddenCard;int min=13,max=1;Card maxCard,minCard,medCard;int hop=0;
		
	hiddenCard.suit=cards[0].suit; //Suit of the hidden card is equal to the Suit of the first Card in the card list
	
	//Check whther there are any cards with similiar values among the three cards which aree needed to decide the value of the hidden card
	int v=0,count=1; bool e=false;
	for (int i=1;i<4;i++){
		v=cards[i].value;
		for (int j=1;j<5;j++){
			if (v==cards[j].value && i!=j ){
				e=true;
				break;
			}
		}
		if (e==true)
			break;
	}
	
	//First get the smallest ,largest and the medium cards of the given cards array excluding the card at the 0 th index
	if (e==false){ //If there are no cards with similiar values then,find the min,max and med card according to the face value
	for (int n=1;n<4;n++){   //For loop is used to find the largest card from the remaining three card
		if (cards[n].value>max){
			max=cards[n].value;
			maxCard=cards[n];
		}
		
		if(cards[n].value<min){ //For loop is used to find the smallest card from the remaining three card
			min=cards[n].value;
			minCard=cards[n];
		}
	}
	
	for (int n=1;n<4;n++){  //For loop is used to find the medium card from the remaining three card
		if(cards[n]!=maxCard && cards[n]!=minCard )
			medCard=cards[n];
	}
	
}
else{ //If there are cards with the same face value
	
	Suit ss=Suit(0) ,sl=Suit(3); //CLUBS is the smallest and Diamonds is the largest suit
    //If the three cards which are needed to decide the  value of the hidden card have the same face value
	if (cards[1].value==cards[2].value && cards[1].value==cards[3].value){
		for (int j=1;j<4;j++){
			if (cards[j].suit>=ss){ //The card which  has the maximum suit will be the max card
				ss=cards[j].suit;
				maxCard=cards[j];
			}
			
			if (cards[j].suit<=sl){ //The card which  has the minimum suit will be the min card
				sl=cards[j].suit;
				minCard=cards[j];
			}
		}
		
	for (int k=1;k<4;k++){
	    if(cards[k].suit!=maxCard.suit && cards[k].suit!=minCard.suit)  //A for loop is used to find the medium  card  
		    medCard=cards[k];
	}
		
	}
	
else{ //If there are only two cards with the same face value out of the 3 cards which are needed to find the vaue of the hidden card
	int i=1,j=1;bool found=false;
	
	for ( i=1;i<4;i++){ //For loop is used to getthe indexes(i&j) of the two similiar cards
	
		for (j=1;j<4;j++) {
		
			if (cards[i].value==cards[j].value && i!=j){
				found=true;
				break;
			}
		}
		if (found==true)
			break;
	}
	 
	for (int k=1;k<4;k++){
	 	if (cards[k].value>cards[i].value && k!=i && k!=j) //If the card which has a different face value,has a higher value than the cards which
	 		maxCard=cards[k];                             	//have similiar face value
	 	else{ //otherwise the card which has the highest suit out of the cards which have similiar face values will be the maXCard
	 		if (cards[i].suit>cards[j].suit)
	 			maxCard=cards[i];
	 		else
	 			maxCard=cards[j];
		 }
}
		 for (int k=1;k<4 ;k++){
		 if (k!=i && k!=j){
		  /*If the card which has a different face value,has a smaller value than the cards which
	 	have similiar face value*/
	    if (cards[k].value<cards[i].value )
	 		  minCard=cards[k];
	 		  
	 	
	 	else{ //otherwise the card which has the smalles suit out of the cards which have similiar face values will be the minCard
		 
	 		if (cards[i].suit<cards[j].suit)
	 			minCard=cards[i];
	 		else
	 			minCard=cards[j];
		 }
	 }
}

	 
	 if (minCard==cards[i] || maxCard==cards[i]) //find the med card
	 	medCard=cards[j];
	else
		medCard=cards[i];
	 }

}
			
	if(cards[1]==minCard && cards[2]==medCard && cards[3]==maxCard) //hop value is calculated according to the sequence of cards
		hop=1;
	else if (cards[1]==minCard && cards[2]==maxCard && cards[3]==medCard)
		hop=2;
	else if (cards[1]==medCard && cards[2]==minCard && cards[3]==maxCard)
		hop=3;
	else if (cards[1]==medCard && cards[2]==maxCard && cards[3]==minCard)
		hop=4;
	else if (cards[1]==maxCard && cards[2]==minCard && cards[3]==medCard)
		hop=5;
	else if (cards[1]==maxCard && cards[2]==medCard && cards[3]==minCard)
		hop=6;
			
	int value; 
	value=cards[0].value+hop;  //hop in the clockwise direction
	if(value>13) 
		value-=13; 
		   	
	hiddenCard.value=Value(value);   //Value of the hidden card
	return hiddenCard; //return the hidden card
}
		
