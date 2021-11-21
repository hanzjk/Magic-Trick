# Magic-Trick - OOP Programming Assignment

It turns out that the order in which the Assistant reveals the cards tells the Magician what
the fifth card is! The Assistant needs to be able to decide which of the cards is going to be
hidden – he or she cannot allow the audience to pick the hidden card out of the five cards
that the audience picks. Here’s one way that the Assistant and the Magician can work
together.

As a running example, suppose that the audience selects: 10♥ 9♦ 3♥ Q♠ J♣
- The Assistant picks out two cards of the same suit. Given five cards, there will definitely be two with the same suit, since we only have four different suits. In the example, the assistant might choose the 3♥ and 10♥.
- The Assistant locates the values of these two cards on the cycle of cards shown below:


<p align="center">
    <img  width=250  height=200 src="https://user-images.githubusercontent.com/65526190/142779236-a62dd66a-1647-4432-a194-0d94c2f9d472.jpg">

</p>

   For any two distinct values on this cycle, one is always between 1 and 6 hops clockwise from the other. For example, even though the 10♥ is 7 hops clockwise from the 3♥, the 3♥ is 6 hops clockwise from the 10♥.

- One of these two cards is revealed first, and the other becomes the secret card. The
card that is revealed is the card from which we can reach the other card clockwise in
6 or fewer hops. Thus, in our example, the 10♥ would be revealed, and the 3♥ would
be the secret card since we can reach the 3♥ from the 10♥ in 6 hops. (If on the other
hand, the two cards were the 4♥ and the 10♥, the 4♥ would be revealed since the 10♥
is 6 hops clockwise from the 4♥.)

  - The suit of the secret card is the same as the suit of the first card revealed.
  - The value of the secret card is between 1 and 6 hops clockwise from the value of the first card revealed.
- All that remains is to communicate a number between 1 and 6. The Magician and Assistant agree beforehand on an ordering of all the cards in the deck from smallest to largest such as:
    A♣ A♥ A♠ A♦ 2♣ 2♥ 2♠ 2♦ . . . Q♣ Q♥ Q♠ Q♦ K♣ K♥ K♠ K♦
- The order in which the last three cards are revealed communicates the number according to the following scheme:
  - ( small, medium, large ) = 1
  -  ( small, large, medium ) = 2
  - ( medium, small, large ) = 3
  - ( medium, large, small ) = 4
  - ( large, small, medium ) = 5
  -  ( large, medium, small ) = 6

  In the example, the Assistant wants to send 6 and so reveals the remaining three
cards in large, medium, small order. Here is the complete sequence that the
Magician sees: 10♥ Q♠ J♣ 9♦

- The Magician starts with the first card, 10♥, and hops 6 values clockwise to reach 3♥,
which is the secret card!

### Exercise 01
Write a computer program using C++ to assist the helper of the magician to decide
the hidden card and order the remaining cards. Five random cards should be taken
as user inputs.

### Exercise 02
Write a computer program using C++ to assist the magician to decide on what is the
hidden card based on the four cards he can see. Four random cards should be taken
as user inputs.

