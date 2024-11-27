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

        bool empty() const{
            return(cards.empty());
        }

        void playCard(std::ostream& os) {
        if (hand.empty()) {
            os << name << " has no cards to play.\n";
            return;
        }

        Card* cardToPlay = hand.play(); // Get the top card
        os << name << " plays " << *cardToPlay << "\n";

        // Check if the card can be added to an existing chain
        for (auto& chain : chains) {
            try {
                *chain += cardToPlay; // Try adding the card to the chain
                os << "Added " << *cardToPlay << " to an existing chain.\n";
                return;
            } catch (IllegalType&) {
                continue; // Skip chains that don't match
            }
        }

        // If no matching chain exists and we can create a new chain
        if (chains.size() < maxchains) {
            Chain<Card>* newChain = new Chain<Card>();
            *newChain += cardToPlay; // Add the card to the new chain
            chains.push_back(newChain);
            os << "Started a new chain with " << *cardToPlay << ".\n";
            return;
        }

        // If no matching chain exists and max chains reached, tie and sell an existing chain
        os << "No matching chain and maximum chains reached. Selling a chain...\n";
        sellAndReplaceChain(cardToPlay, os);
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