// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{


    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards


    d.shuffle();

    d.print();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    Card temp1;
    Card temp2;
    int di = (2 * numCards) - 1;

    while(di < 52){

        while(p1.checkHandForPair(temp1, temp2)){
            cout << p1.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
        }

        while(p2.checkHandForPair(temp1, temp2)){
            cout << p2.getName() << " books the " << temp2.rankString(temp2.getRank()) << endl;
        }

        temp1 = p1.chooseCardFromHand();
        cout << p1.getName() << " asks for a " << temp1.rankString(temp1.getRank()) << endl;

        if(p2.cardInHand(temp1)){
            temp1 = p2.removeCardFromHand(temp1);
            p1.addCard(temp1);
            cout << p1.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
            p1.checkHandForPair(temp1, temp2);

        }

        if(!p2.cardInHand(temp1) && (di < 52)){
            cout << p2.getName() << " says Go Fish" << endl;
            temp1 = d.dealCard();
            p1.addCard(temp1);
            di++;
            cout << p1.getName() << " draws " << temp1.toString() << endl;
        }

        temp2 = p2.chooseCardFromHand();
        cout << p2.getName() << " asks for a " << temp2.rankString(temp2.getRank()) << endl;

        if(p1.cardInHand(temp2)){
            temp2 = p1.removeCardFromHand(temp2);
            p2.addCard(temp2);
            cout << p2.getName() << " books the " << temp2.rankString(temp2.getRank()) << endl;
            p2.checkHandForPair(temp1, temp2);

        }

        if(!p1.cardInHand(temp2) && (di < 52)){
            cout << p1.getName() << " says Go Fish" << endl;
            temp2 = d.dealCard();
            p2.addCard(temp1);
            di++;
            cout << p2.getName() << " draws " << temp2.toString() << endl;
        }




    }

    if(p1.getBookSize() > 26){
        cout << p1.getName() <<" is the winner!" << endl;
    }

    if(p2.getBookSize() > 26){
        cout << p2.getName() <<" is the winner!" << endl;
    }

    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   



