#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include "Card.h"

class DiscardPile{

    private:
        std::vector<Card*> pile;
    public:

        DiscardPile& operator +=(Card* card){
            pile.push_back(card);
            return *this;
        }

        Card* pickUp(){
            if(pile.empty()){
                return nullptr;
            }
            else{
                Card* card = pile.back();
                pile.pop_back();
                return card;
            }
        }

        Card* top() const{
            
        }
        



};

#endif