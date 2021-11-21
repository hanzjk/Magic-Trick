enum Suit{CLUBS,HEARTS,SPADES,DIAMONDS};  //enum of card suits
enum Value{TWO=2,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE=1}; //enum of face values of cards
class Card{
	private:
		Value value; 
		Suit suit;
	
	public:
		Card();
		Card(Value v,Suit s);
		void getCard() ; //function which is used to take cards from the user
		void print() const; //function which is used to print cards
		int  hopValue(Card card2) const; //function which is used to return the hop value
		static Card* selectTwoCards(Card cards[]) ; //Function which is used to determine the Hidden card and the Revealing Card
		Card* getCardArray(Card cards[5],Card cardReveal) const; //function which is used to find the minimum,maximum,medium cards
		static  Card*  sortedArray(Card cards[4],int hop); //function which is used to create the final sequence of cards
		bool operator ==(Card card2);
		bool operator !=(Card card2);
	
};
