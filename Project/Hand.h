#ifndef HAND_H
#define HAND_H

#include <list>
#include <iostream>
#include "Card.h"

// The Hand class manages a player's hand of cards.

class Hand{
    private:
        std::list<Card*> hand; // List to store pointers to cards.
    public:
    // Add a card to the front of the hand.
        Hand& operator+=(Card* card){
            hand.push_front(card);
            return *this;
        }

    // Remove and return the card at index `i`.
    // Returns nullptr if index is out of range.
        Card* operator[](int i){
            if(i < 0 || i >= hand.size()){
                return nullptr;
            }

            auto hold = hand.begin();
            std::advance(hold, i);

            Card* card = *hold;
            hand.erase(hold);
            return card;
        }


        Card* play()  {
            if(hand.empty()){
                return nullptr;
            } else{
                Card* card=hand.front();
                hand.pop_front();
                return card;
            }
        }

        Card* top() const{
            if(hand.empty()){
                return nullptr;
            } else{
                return hand.front();
            }
        }


        friend std::ostream& operator<<(std::ostream& os,const Hand& printed){
            for(const auto& card: printed.hand){

                os<< *card << " ";

            }
            return os;
        }

        bool empty() const{
            return hand.empty();
        }





};

#endif
