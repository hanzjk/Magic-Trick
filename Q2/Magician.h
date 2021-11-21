enum Suit{CLUBS,HEARTS,SPADES,DIAMONDS};  //enum of card suits
enum Value{TWO=2,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE=1}; //enum of face values of cards
class Card{
	private:
		Value value;
		Suit suit;
	
	public:
		Card();
		Card(Value v,Suit s);
		void  getCard(); //function which is used to take cards from the user
		void  print() const; // function which is used to print cards
		bool operator ==(Card card2);
		bool operator !=(Card card2);
		static Card findHidden(Card cards[4]); //Function which is used to find the hidden Card
};
