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


class Chain_Base {
protected:
    std::vector<Card*> cards;
    std::string chainType;
public:
    virtual ~Chain_Base() {}

    Chain_Base& operator+=(Card* card){

            
            cards.push_back(card);
            return *this;
        };

    std::string getType() const{
            return chainType;
        }
    
    virtual int sell() const = 0;

    int size() const {
        return cards.size();
    }

    bool empty() const {
        return cards.empty();
    }

    // Print the cards in the chain
    friend std::ostream& operator<<(std::ostream& os, const Chain_Base& chain) {
        if (!chain.cards.empty()) {
            os<< chain.chainType << " ";
            for (const auto& card : chain.cards) {
                os << *card << " "; // Print each card in the chain
            }
        } else {
            os << "Empty Chain"; // If the chain is empty
        }
        return os;
    }

    
};

/// Chain class definition
template<typename T>
class Chain : public Chain_Base{

    private:
        
        


    public:
        Chain() {
            if (typeid(T) == typeid(Blue)) {
                chainType = "Blue";
            } else if (typeid(T) == typeid(Chili)) {
                chainType = "Chili";
            } else if (typeid(T) == typeid(Stink)) {
                chainType = "Stink";
            } else if (typeid(T) == typeid(Green)) {
                chainType = "Green";
            } else if (typeid(T) == typeid(soy)) {
                chainType = "soy";
            } else if (typeid(T) == typeid(black)) {
                chainType = "black";
            } else if (typeid(T) == typeid(Red)) {
                chainType = "Red";
            } else if (typeid(T) == typeid(garden)) {
                chainType = "garden";
            }
        }

        //check if card to be added is same type as other cards in this chain
        Chain& operator+=(Card* card){
            
            if (typeid(T) == typeid(*card)) {
                cards.push_back(card);
                std::cout<< "Card added success." <<std::endl;
            } else {
                std::cout<< "Illegal card type." <<std::endl;
            }
            return *this;
        }

        int sell() const{
            if(cards.empty()){
                return 0;
            } else{
                int size = cards.size();
                if(cards[0]->getCardsPerCoin(4) <= size){
                    return 4;
                } else if(cards[0]->getCardsPerCoin(3) <= size){
                    return 3;
                }  else if(cards[0]->getCardsPerCoin(2) <= size){
                    return 2;
                } else if(cards[0]->getCardsPerCoin(1) <= size){
                    return 1;
                } else{
                    return 0;
                }
            }
        }

    
};


#endif 