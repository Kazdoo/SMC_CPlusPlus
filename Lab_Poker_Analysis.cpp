//by Olivier Ged
//11/11/2022

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <time.h>

using namespace std;



enum Suits {SPADE,HEART,CLUB,DIAMOND};
const string suitNames[4] {"Spade", "Heart", "Club", "Diamond"};
enum Ranks {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING,ACE};
const string rankNames[13] {"two","three", "four", "five", "six","seven",
                            "eight","nine", "ten", "jack", "queen", "king", "ace"};

class Card{
public:
    string getSuit() const;
    string GetRank() const; //return a string readable by the user.
    int GetRank2() const; //return the enum rank, used for Sorting the hand.

    void setSuit(Suits value);
    void setRank(Ranks value);

    friend ostream& operator<<(ostream& out, const Card& card);

    //Card(string suit, string value);  I don't use these constructors given by the teacher.
    //Card(string suit, rank string);  I don't use these constructors given by the teacher.
    Card(Suits inSuit, Ranks inRank);
    Card();


private:
    Suits suit;
    Ranks rank;

};
Card::Card() {

}
Card::Card(Suits inSuit, Ranks inRank)
{
    suit = inSuit;
    rank = inRank;
}
ostream &operator<<(ostream &outs, const Card &card) {
    cout << card.GetRank()<< " of "<< card.getSuit()<<endl;
    return outs;
}
string Card::getSuit() const {
    return suitNames[suit];
}
string Card::GetRank() const {
    return rankNames[rank];
}
void Card::setSuit(Suits value) {
    suit = value;
}
void Card::setRank(Ranks value) {
    rank = value;
}
int Card::GetRank2() const {
    return rank;
}


class Deck{
public:
    bool empty(); //return true is the deck is empty.

    friend ostream& operator<<(ostream& out, Deck& deck);

    Card dealCard(); // returns the next Card in the deck
    Card getCardAt (int index);//gets the Card at the given index
    Deck();// constructor of 52 cards.

    void shuffle(int n); //shuffle randomly n times.

private:
    const int DECK_SIZE = 52;
    int cardIndex=-1; //marks the index of the next card in the deck, start at -1,
                        // since we increment before return in the dealCard().
    Card deck[52];

};
Deck::Deck() {
    for (int i = 0; i < 4 ; i++)
    {
        for (int j =0; j <13; j++)
        {
            Card card ((Suits)i, (Ranks)j);
            deck[i * 13 + j] = card;
        }
    }
}
ostream &operator<<(ostream &out, Deck &deck) {
    for (int i = 0; i < 52; i++)
        cout << i<<":"<<deck.getCardAt(i);

    return out;
}
Card Deck::getCardAt(int index) {
    return deck[index];
}
void Deck::shuffle(int n)
{
    for (int i=0; i<n ;i++)
    {
        // Random for remaining positions.
        int r = i + (rand() % (52 -i));
        swap(deck[i], deck[r]);
    }
}
Card Deck::dealCard() {
    cardIndex++;
    return getCardAt(cardIndex);
    }


class CardHand{
public:
    friend ostream &operator<<(ostream &outs, CardHand& hand);

    Card getCardAtPos(int a) ; //return the next card in hand.
    void addCard(Card in);
    CardHand();
    void sortHand(); //order cards by rank in hand from small to high




private:
    vector<Card> hand;
    int chIndex=0;
};
ostream &operator<<(ostream &outs, CardHand &inHand) {

    for (int i=0; i<5; i++)
        cout<< inHand.getCardAtPos(i);
    return outs;
}
Card CardHand::getCardAtPos(int a) {
    return hand[a];
}
void CardHand::addCard(Card in) {
    hand.push_back(in);
        chIndex++;
}
CardHand::CardHand() {
//meant to be empty.
}
void CardHand::sortHand() {

    for (int w=0; w<4;w++){  //this is brute forcing it but could not find a better way to sort it than running this logic a few times.
        for (int z=0; z<hand.size()-1;z++) {
            if (hand[z].GetRank2() > hand[z+1].GetRank2()){
                iter_swap(hand.begin() + z, hand.begin()+(z+1));
            }
        }
    }
}


class PokerScore{

public:
    enum Scores {
        ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.
        STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking
        FOUR_OF_A_KIND, //four cards of the same ranking
        FULL_HOUSE, //three cards of the same rank along with two cards of the same rank
        FLUSH, //five cards of the same suit
        STRAIGHT, //five cards in consecutive ranking
        THREE_OF_A_KIND, //three cards of the same rank
        TWO_PAIR, //two cards of the same rank along with another two cards of the same rank
        ONE_PAIR, //two cards of the same rank
        HIGH_CARD //highest card in the player’s hand
    };

    void operator+=(const Scores& score);
    //friend bool operator==(const PokerScore& p, Scores score);

    friend ostream& operator<<(ostream &outs, PokerScore& p);
    void operator&=( PokerScore& rightSide);
    Scores& operator[](unsigned int index);

    PokerScore();

private:
    int size();
    vector<Scores> scores;
};
ostream& operator<<(ostream &outs, PokerScore &p) {

    for (int i = 0; i<10; i++)
        cout<< p.scores[i]<<endl;
    return outs;


}

PokerScore::Scores &PokerScore::operator[](unsigned int index) {
    if(index >= 10){
        cout <<"array index out of bound, exiting";
        exit(0);
         }
    return scores[index];
}
void PokerScore::operator&=( PokerScore &rightSide) {
    scores = rightSide.scores;

    for (int i = 0; i<scores.size(); i++)
        scores[i] = rightSide.scores[i];

}
int PokerScore::size() {
    scores.size();
    return 0;
}

PokerScore::PokerScore() {

}

class CardHandScorer{
public:
    static void scoreHand (CardHand ch, int *run1000);
};
void CardHandScorer::scoreHand(CardHand ch, int *run1000) {

    PokerScore p(); //not used, but I have to return a PokerScore object.

    int pairCounter=0;
    bool flush = true;
    int straight = 4;
    bool threeOfKind = false;

    //get.Rank2() is returning the enum position of a card.
    //there is always 1 high card, it is always ch.getCardAtPos(4).GetRank2()
    run1000[PokerScore::HIGH_CARD]+=1;

    for (int i = 0; i<4;i++){
        if(ch.getCardAtPos(i).GetRank2() == ch.getCardAtPos(i+1).GetRank2())
            pairCounter++;
        //if 2 cards next to each other in rank, it will decrease straight by 1, if straight get to 0, then the hand is a straight;
        straight -=(ch.getCardAtPos(i+1).GetRank2() - ch.getCardAtPos(i).GetRank2());
    }

    //the unique case of a straight with cards : 2, 3, 4, 5 and Ace.
    if(ch.getCardAtPos(0).GetRank2() == 0
       &&ch.getCardAtPos(1).GetRank2() == 1
       &&ch.getCardAtPos(2).GetRank2() == 2
       &&ch.getCardAtPos(3).GetRank2() == 3
       && ch.getCardAtPos(4).GetRank2() == 12)
        straight =0;

    for (int i = 0; i<3;i++){
        if ((ch.getCardAtPos(i).GetRank2() == ch.getCardAtPos(i+1).GetRank2())
        && (ch.getCardAtPos(i+1).GetRank2() == ch.getCardAtPos(i+2).GetRank2()))
            threeOfKind =true;}

    if (pairCounter == 1 || pairCounter == 2 && threeOfKind )
        run1000[PokerScore::ONE_PAIR]+=1;

    if(pairCounter == 2 && !threeOfKind)
        run1000[PokerScore::TWO_PAIR]+=1;

    if(threeOfKind)
        run1000[PokerScore::THREE_OF_A_KIND]+=1;

    if(pairCounter == 2 && threeOfKind)
        run1000[PokerScore::FULL_HOUSE]+=1;

    //let's find 4 of a kind
    if (pairCounter == 3)
        run1000[PokerScore::FOUR_OF_A_KIND]+=1;

    //let's find flush
    for (int i = 0; i<4;i++){
        while(flush){
            if(ch.getCardAtPos(i).getSuit() == ch.getCardAtPos(i+1).getSuit())
                flush= true;
            else
                flush = false;
             }
        }

    if(flush)
        run1000[PokerScore::FLUSH]+=1;

    if (straight==0)
        run1000[PokerScore::STRAIGHT]+=1;

    if (straight==0 && flush)
        run1000[PokerScore::STRAIGHT_FLUSH]+=1;

    if (straight==0 && flush && ch.getCardAtPos(4).GetRank2()==12) //an ace in the last position.
        run1000[PokerScore::ROYAL_FLUSH]+=1;

    //return p;
}


int main() {
    srand(time(0));

    int run1000 [10]={0 };


    for (int z = 0; z<1;z++){
        Deck deck;
        deck.shuffle( 40);
        CardHand ch;
        for (int i =0;i<5;i++)
            ch.addCard(deck.dealCard());

        ch.sortHand();

        CardHandScorer::scoreHand(ch, run1000);
    }

    cout<<"ROYAL_FLUSH : "<<run1000[0] <<endl
        <<"STRAIGHT_FLUSH : "<<run1000[1] <<endl
        <<"FOUR_OF_A_KIND : "<<run1000[2] <<endl
        <<"FULL_HOUSE : "<<run1000[3] <<endl
        <<"FLUSH : "<<run1000[4] <<endl
        <<"STRAIGHT : "<<run1000[5] <<endl
        <<"THREE_OF_A_KIND : "<<run1000[6] <<endl
        <<"TWO_PAIR : "<<run1000[7] <<endl
        <<"ONE_PAIR : "<<run1000[8] <<endl
        <<"HIGH_CARD : "<<run1000[9] <<endl;


    return 0;
}