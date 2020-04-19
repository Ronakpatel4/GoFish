//
// Created by Ronak on 4/14/2020.
//

#include "card.h"

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;

}

string Card::toString() const {
    string temp = rankString(myRank);
    temp += suitString(mySuit);
    return temp;
}

bool Card::sameSuitAs(const Card &c) const {
    if(this->mySuit == c.mySuit){
        return true;
    }
    return false;
}

int Card::getRank() const {
    return (myRank);
}

string Card::suitString(Card::Suit s) const {
    if(this->mySuit == spades){
        return "s";
    }

    if(this->mySuit == hearts){
        return "h";
    }

    if(this->mySuit == diamonds){
        return "d";
    }

    if(this->mySuit == clubs){
        return "c";
    }
    return std::__cxx11::string();
}

string Card::rankString(int r) const {
    if(r == 1){
        return "A";
    }

    if(r == 11){
        return "J";
    }

    if(r == 12){
        return "Q";
    }

    if(r == 13){
        return "K";
    }
    std::string temp = std::to_string(r);
    return temp;

}

bool Card::operator==(const Card &rhs) const {
    if (this->mySuit == rhs.mySuit) {
        if (this->myRank == rhs.myRank) {
            return true;
        }
    }
    return false;
}

bool Card::operator!=(const Card &rhs) const {
    if (this->mySuit != rhs.mySuit) {
        if (this->myRank != rhs.myRank) {
            return true;
        }
    }
    return false;
}

