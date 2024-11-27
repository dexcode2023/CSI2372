#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"


//Deck class definition:
class Deck{

    private:
        std::vector<Card*> cards;
    
    public:

    //draws top element in vector
     Card* draw() {
        if (cards.empty()){
            std::cout << "Empty deck." << std::endl;
            return nullptr;
            
        } 
        Card* card = cards.back();
        cards.pop_back();
        return card;
    }

    //overwrite << operator for deck class.
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck) {
        for (const auto& card : deck.cards) {
            os << *card << " ";
        }
        return os;
    }

    bool empty() const{
        return cards.empty();
    }

    void addCard(Card* card) {
        cards.push_back(card);
    }

    void shuffle() {
        std::shuffle(cards.begin(), cards.end(), std::default_random_engine(std::random_device{}()));
    }




};







#endif