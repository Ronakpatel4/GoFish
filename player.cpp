//
// Created by Ronak on 4/14/2020.
//

#include "player.h"
#include <random>

Player::Player() {

}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    if(c1.getRank() == c2.getRank()){
        return true;
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    long r = rand() % (this->getHandSize());
    return myHand[r];
}

bool Player::cardInHand(Card c) const {
    return sameRankInHand(c);
}

Card Player::removeCardFromHand(Card c) {
    Card temp = c;
    int it = 0;
    for(auto i = myHand.begin(); i != myHand.end(); i++){
        if(c.getRank() == myHand[it].getRank()){
            temp = myHand[it];
            myHand.erase(myHand.begin()+it);
            return temp;
        }
        it++;
    }
    return temp;
}

string Player::showHand() const {
    int it = 0;
    string temp;
    for(auto i = myHand.begin(); i != myHand.end(); i++){
        if(i == myHand.begin()){
            temp = myHand[it].toString();
        }
        else{
            temp += myHand[it].toString();
        }
        temp += " ";
        it++;
    }
    temp += "\n";
    return temp;
}

string Player::showBooks() const {
    int it = 0;
    string temp;
    for(auto i = myBook.begin(); i != myBook.end(); i++){
        if(i == myBook.begin()){
            temp = myBook[it].toString();
        }
        else{
            temp += myBook[it].toString();
        }
        temp += " ";
        it++;
    }
    temp += "\n";
    return temp;
}

int Player::getHandSize() const {
    int c = 0;
    for(auto i = myHand.begin(); i != myHand.end(); i++){
        c++;
    }
    return c;
}

int Player::getBookSize() const {
    int c = 0;
    for(auto i = myBook.begin(); i != myBook.end(); i++){
        c++;
    }
    return c;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    int sz = getHandSize();

    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            if((myHand[i].getRank() == myHand[j].getRank()) && (i != j)){
                c1 = myHand[i];
                c2 = myHand[j];
                bookCards(c1, c2);
                removeCardFromHand(c1);
                removeCardFromHand(c2);
                return true;
            }

            }
        }
    return false;
}

bool Player::sameRankInHand(Card c) const {
    int it = 0;
    for(auto i = myHand.begin(); i != myHand.end(); i++){
        if(c.getRank() == myHand[it].getRank()){
            return true;
        }
        it++;
    }

    return false;
}

