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
            if(pile.empty()){
                return nullptr;
            } else{
                return pile.back();
            }

        }
        void print(std::ostream& os) const {
            for (const auto& card : pile) {
                card->print(os);
                os << " ";
            }
        }   

        friend std::ostream& operator<<(std::ostream& os, const DiscardPile& dp) {
            if(!dp.pile.empty()){
                dp.pile.back()->print(os);


            }
            else{
                os<<"Pile Empty";


            }
            return os;
        
    }

    bool empty() const{
        return pile.empty();
    }
        



};

#endif