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

        void print(std::ostream& os);

        friend std::ostream& operator<<(std::ostream& os, const Chain& chain) {
            chain.print(os);
            return os;
        }

    private:
        std::vector<T*> cards;



};

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

template<typename T>
void Chain<T>::print(std::ostream& os){
    
}




#endif 