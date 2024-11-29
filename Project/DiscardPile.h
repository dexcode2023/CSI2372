#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include "Card.h"

//DiscardPile class definition
class DiscardPile{

    private:
        std::vector<Card*> pile;
    public:

        
        //operator to add to the discard pile
        DiscardPile& operator +=(Card* card){
            pile.push_back(card);
            return *this;
        }


        //pickup top card from discard pile
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

        //view to card of  discard pile
        Card* top() const{
            if(pile.empty()){
                return nullptr;
            } else{
                return pile.back();
            }

        }
        //print discard pile onto output stream
        void print(std::ostream& os) const {
            for (const auto& card : pile) {
                card->print(os);
                os << " ";
            }
        }   

        //<< operator for ouput  of discard pile
        friend std::ostream& operator<<(std::ostream& os, const DiscardPile& dp) {
            if(!dp.pile.empty()){
                dp.pile.back()->print(os);


            }
            else{
                os<<"Pile Empty";


            }
            return os;
        
    }
    //return empty status of discard pile
    bool empty() const{
        return pile.empty();
    }
        



};

#endif