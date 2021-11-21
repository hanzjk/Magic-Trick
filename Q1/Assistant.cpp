#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include "Assistant.h"
using namespace std;
Card::Card(){}//Default constructor

Card::Card(Value v,Suit s):value(v),suit(s){} //Parameterized constructor

void Card::getCard() { //Definition of function which is used to take cards from the user
	bool valid=true;
	while(valid==true){
		string valueName,of;char suitName; //Face value and the suit of the card is taken as user input.
		cin>>valueName>>of>>suitName;  //ex: 10 of H
			
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
		
void Card:: print() const{ //Definition of function which is used to print cards
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
	cout<<" OF ";
	switch(suit){
		case 0:cout<<"CLUBS";break;
		case 1:cout<<"HEARTS";break;
		case 2:cout<<"SPADES";break;
		case 3:cout<<"DIAMONDS";break;
		default:break;
	}
		cout<<setw(10);
}
	
bool Card:: operator ==(Card card2){ //Opertor == is overloaded to check the similiarity of two cards
	if (value==card2.value && suit==card2.suit)
		return true;
	return false;
}
	
bool Card:: operator !=(Card card2){ //Operator != is overloaded 
	if (value!=card2.value && suit!=card2.suit)
		return true;
	return false;
}
	
int Card:: hopValue(Card card2) const{ //Definition of function which is used to return the hop value
	//this function is called by one of the selected cards while the other one is given as a parameter
	int hop1=0,hop2=0,hop=0;
	//Compute the first hop value by getting the absolute value of the difference between the values of the two similiar cards which were selected at the beginning
   	hop1=abs(value-card2.value);
   			
	//Check which card has the highest face value,out of the two cards, and then compute the second  hop value
	(value>card2.value)?hop2=13-value+card2.value:hop2=13-card2.value+value; //Hop from large card to ACE and then ACE to small card	
        	
    //If the first hop value is <=6 then we can hop from small card to large card,else we have to hop from large to small.
	(hop1<6)?hop=hop1:hop=hop2;
	return hop;
}
	
Card* Card:: selectTwoCards(Card cards[]) { //Definition of Function which is used to determine the Hidden card and the Revealing Card
	Card cardselect1,cardselect2,cardHidden,revealCard;bool found;
	for(int i=0;i<5;i++){ //A for loop is used to select two  cards with the same suit ,from the given five cards
		Suit s=cards[i].suit; 
			for(int j=0;j<5;j++){ //Compare the suit of each card with other cards untill we find two cards of the same suit
				if (s==cards[j].suit && i!=j){
			    	found=true;
					cardselect1=cards[i];  
					cardselect2=cards[j];
					break;
				}	
		   }
		if(found==true)
			break;  //Exit the for loop if two similiar cards are found
	}
			
	//If we hop from the small card to large card,then the large card will be selected as the Hidden card.
	if(abs(cardselect1.value-cardselect2.value)<6) //If the difference is <=6 then we can hop from small card to large card
		(cardselect1.value<cardselect2.value)?cardHidden=cardselect2,revealCard=cardselect1:cardHidden=cardselect1,revealCard=cardselect2;
			
	//If we hop from the large card to small card,then the small card will be selected as the Hidden card.
	else
		(cardselect1.value>cardselect2.value)?cardHidden=cardselect2:cardHidden=cardselect1;
		 
	// The card that is revealed is the card from which we can reach the other card clockwise in 6 or fewer hops.
	(cardHidden==cardselect1)?revealCard=cardselect2:revealCard=cardselect1;
		  			
	Card* temp=new Card[2]; //Array is used to store the hidden card and the revealing card
	temp[0]=cardHidden;
	temp[1]=revealCard;
	return temp; //return the array
}
		
Card* Card::getCardArray(Card cards[5],Card cardReveal) const{ //Definition of function which is used to find the minimum,maximum,medium cards
	//this function is called by the hidden card
	int min=13,max=1;Card maxCard,minCard,medCard;
	for(int n=0;n<4;n++){   //revealing card is placed on the 0 th index of the array
	   	if(cardReveal==cards[n] ){
	   	 swap(cards[0],cards[n]); //swap the revealing card with element in the 0 th index
	   		
		}
		
		if(Card(value,suit)==cards[n] ){
	   	 swap(cards[4],cards[n]); //swap the hidden card with element in the last index ->for the easiness
	   		
		}
	}
	
	//Check whther there are any cards with similiar values
	int v=0; bool e=false;  
	for (int i=1;i<4;i++){   //The three cards which i need to arrange are stored in the 1,2, and 3 rd index of the array  
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
	

	if (e==false){ //If there are no cards with similiar values then,find the min,max and med card according to the face value

    for (int n=1;n<4;n++){  //A for loop is used to find the largest and smallest cards from the array excluding the revealing card and hidden cards
		if (cards[n].value>max ){
			max=cards[n].value;
			maxCard=cards[n];
		}
	
	if(cards[n].value<min){  
		min=cards[n].value;
		minCard=cards[n];
		}
   }
	
	for (int n=1;n<4;n++){
	    if(cards[n]!=maxCard && cards[n]!=minCard)  //A for loop is used to find the medium  card from the array excluding the revealing card and hidden card
		    medCard=cards[n];
	}
	
}


else{ //If there are cards with the same face value
	
	Suit ss=Suit(0) ,sl=Suit(3); //CLUBS is the smallest and Diamonds is the largest suit

	//If the three cards which are needed to arrange in a given order have the same face value
	if (cards[1].value==cards[2].value && cards[1].value==cards[3].value){
		for (int j=1;j<4;j++){
			if (cards[j].suit>=ss){ //The card which  has the maximum suit will be the max card
				ss=cards[j].suit;
				maxCard=cards[j];
			}
			
			if (cards[j].suit<=sl){  //The card which  has the minimum suit will be the max card
				sl=cards[j].suit;
				minCard=cards[j];
			}
		}
		
	for (int k=1;k<4;k++){
	    if(cards[k].suit!=maxCard.suit && cards[k].suit!=minCard.suit)  //A for loop is used to find the medium  card from the array excluding the revealing card and hidden card
		    medCard=cards[k];
	}
		
	}
	
else{ //If there are only two cards with the same face value out of the 3 cards which are needed to be arranged in an order
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
	 		maxCard=cards[k];  								//have similiar face value
	 
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
	if (minCard==cards[i] || maxCard==cards[i]) //Choose the medium card
	 	medCard=cards[j];
	else
		medCard=cards[i];
}
}
	  		
	Card* temp=new Card[4]; //Array is used to store those 4 cards
	temp[0]=cardReveal; temp[1]=minCard; 
	temp[2]=medCard; temp[3]=maxCard;
	return temp; //that array is returned
}
	
Card* Card:: sortedArray(Card cards[4],int hop){ //Definition of function which is used to create the final sequence of cards
    //Array which stored the revaling card,min,max & med cards is given as a input parameter
	Card minCard=cards[1], maxCard=cards[3], medCard=cards[2]; //minimum ,maximum & medium cards are stored into temp card objects
	switch(hop){ //Rearrange the array according to the hop value
   	case 1:cards[1]=minCard;cards[2]=medCard;cards[3]=maxCard;break;
   	case 2:cards[1]=minCard;cards[2]=maxCard;cards[3]=medCard;break;
   	case 3:cards[1]=medCard;cards[2]=minCard;cards[3]=maxCard;break;
   	case 4:cards[1]=medCard;cards[2]=maxCard;cards[3]=minCard;break;
   	case 5:cards[1]=maxCard;cards[2]=minCard;cards[3]=medCard;break;
   	case 6:cards[1]=maxCard;cards[2]=medCard;cards[3]=minCard;break;
   	default:break;
   }
   return cards;
}

