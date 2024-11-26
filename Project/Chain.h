#ifndef CHAIN_H
#define CHAIN_H

#include "Card.h"
#include <vector>
#include <stdexcept>

//adding the IllegalType exception 
class IllegalType : public std::exception {
    const char* what() const noexcept override {

         return "Illegal Card type added to chain using += opperator."; 
         }
};

/// Chain class definition
template<typename T>
class Chain{

    private:
        std::vector<T*> cards;

    public:
        Chain(){};

        //check if card to be added is same type as other cards in this chain
        Chain& operator+=(Card* card){
            if (T* typedCard = dynamic_cast<T*>(card)) {
                cards.push_back(typedCard);

            } else {
                throw IllegalType();

            }
            return *this;
        }

        int sell() const;

        friend std::ostream& operator<<(std::ostream& os, const Chain& chain) {
            os << cards[0]->getName() <<"/t";
            for(const auto&  card : cards){
                os << *card << " " << endl;
            }
            return os;
        }

        bool empty(){
            return(cards.empty());
        }

    
};

//sell member function(was just testing to see how I could declare it outside)
template<typename T>
int Chain<T>::sell() const{
    if(cards.empty()){
        return 0;
    } else{
        int size = cards.size();
        if(cards[0].getCardsPerCoin(4) =< size){
            return 4;
        } else if(cards[0].getCardsPerCoin(3) =< size){
            return 3;
        }  else if(cards[0].getCardsPerCoin(2) =< size){
            return 2;
        } else if(cards[0].getCardsPerCoin(1) =< size){
            return 1;
        } else{
            return 0;
        }
    }
}





#endif 