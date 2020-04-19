//
// Created by Ronak on 4/14/2020.
//

#include "deck.h"
#include <cstdlib>

Deck::Deck() {
    int i = 0;
    int c = 1;
    Card temp;
    while(i <=12){
        temp = Card(c, Card::spades);
        myCards[i] =  temp;
        i++;
        c++;
    }
c = 1;
    while(i <=25){
        temp = Card(c, Card::hearts);
        myCards[i] =  temp;
        i++;
        c++;
    }
c = 1;
    while(i <=38){
        temp = Card(c, Card::diamonds);
        myCards[i] =  temp;
        i++;
        c++;
    }
c = 1;
    while(i <=51){
        temp = Card(c, Card::clubs);
        myCards[i] =  temp;
        i++;
        c++;
    }
    myIndex = 0;

}

void Deck::shuffle() {
    Card temp;
    long r;
    for(int c = 0; c < 8; c++) {
        for (int i = 0; i < SIZE; i++) {
            r = rand() % SIZE;
            temp = myCards[r];
            myCards[r] = myCards[i];
            myCards[i] = temp;
        }
    }

}

Card Deck::dealCard() {
    myIndex++;
    return myCards[(myIndex-1)];

}

int Deck::size() const {

    if(myIndex == 0){
        return SIZE;
    }

    return (SIZE - myIndex - 1);
}

void Deck::print() {
    for(int i = 0; i < 52; i++){
        cout << myCards[i].toString() << "\n";
    }

}

