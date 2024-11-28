#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"
#include "Chain.h"

class NotEnoughCoins : public std::exception {
    const char* what() const noexcept override { return "Not enough coins to buy a third chain."; }
};

class Player{
    private:
        std::string name;
        std::vector<Chain_Base*> chains;

        int maxchains;
        int coins;

        Hand hand;

        Chain_Base* chainCreateType(Card* newCard){
            Chain_Base* newChain = nullptr;
            if (newCard->getName() == "Blue") {
                    newChain = new Chain<Blue>();
            } else if (newCard->getName() == "Chili") {
                newChain = new Chain<Chili>();
            } else if (newCard->getName() == "Stink") {
                newChain = new Chain<Stink>();
            } else if (newCard->getName() == "Green") {
                newChain = new Chain<Green>();
            } else if (newCard->getName() == "soy") {
                newChain = new Chain<soy>();
            } else if (newCard->getName() == "black") {
                newChain = new Chain<black>();
            } else if (newCard->getName() == "Red") {
                newChain = new Chain<Red>();
            } else if (newCard->getName() == "garden") {
                newChain = new Chain<garden>();
            }
            return newChain;

        }


        void sellAndReplaceChain(Card* newCard, std::ostream& os) {
            // Sell the first chain
            int maxProfitIndex = 0;
            int maxCoins = chains[0]->sell();
            for (size_t i = 1; i < chains.size(); ++i) {
                const auto currentChainProfit = chains[i]->sell();
                if (currentChainProfit > maxCoins) {
                    maxProfitIndex = i;
                }
            }

            // Give coins to the player and replace the chain
            os<<"Selling: "<<*chains[maxProfitIndex]<<std::endl;
            os << "Sold chain for " << maxCoins << " coins.\n";
            *this += maxCoins; 
            delete chains[maxProfitIndex];
            Chain_Base* newChain = chainCreateType(newCard);
            chains[maxProfitIndex] = newChain; // Replace it with a new chain
            *chains[maxProfitIndex] += newCard; 
        }

    public:

        Player(std::string& playerName): name(playerName), coins(0), maxchains(2){

        }
        ~Player() {
        for (auto chain : chains) {
            delete chain;
        }
        }

        std::string getName() const{
            return name;
        }

        int getNumCoins() const{
            return coins;
        }

        int getMaxNumChains() const{
            return maxchains;
        }

        Player& operator+=(int c){
            coins+=c;

            return *this;
        }

        int getNumChains() const {
            int nonZero = 0;
            for (const auto& chain : chains) {
                if (!chain->empty()) {
                    ++nonZero;
                }
            }
                return nonZero;
        }   

        Chain_Base& operator[](int i) {

            if (i < 0 || i >= chains.size()) {
                throw std::out_of_range("Invalid chain index");
            }
            return *chains[i];
        }

        void addCardToHand(Card* card) {
            hand += card; 
        }

        void buyThirdChain() {
            if (coins < 3) {
                throw NotEnoughCoins();
            }
            coins -= 3;
            maxchains = 3;
            chains.push_back(new Chain<Card>);
        }


        void printHand(std::ostream& os, bool allcards) const {
            if (allcards) {
                os << hand;
            } else if (hand.top()) {
                os << *hand.top();
            } else {
                os << "Empty hand.";
            }
        }

        friend std::ostream& operator<<(std::ostream& os,const Player& printed){
            
            os<< printed.name << " " << printed.coins << " coins\n";

            for(int i = 0; i<printed.chains.size();++i){
                if(!printed.chains[i]->empty()){
                    os<<*printed.chains[i] << "\n";
                }
            }




            return os;
        }



        void playCard(std::ostream& os) {
            if (hand.empty()) {
                os << name << " has no cards to play.\n";
                return;
            }

            // Get the top card

            Card* cardToPlay = hand.play(); 
            os << name << " plays " << *cardToPlay << "\n";

            // Check if the card can be added to an existing chain
            for (auto& chain : chains) {

                if(cardToPlay->getName() == chain->getType()){
                    *chain += cardToPlay; 
                    os << "Added " << *cardToPlay << " to an existing chain.\n";
                    os<< *chain <<"\n";
                    return;
                } else{
                    continue;
                }
    
            }

            // If no matching chain exists and we can create a new chain
            if (chains.size() < maxchains) {
                Chain_Base* newChain = chainCreateType(cardToPlay);

                *newChain += cardToPlay;
                chains.push_back(newChain);
                os << "Started a new chain with " << *cardToPlay << ".\n";
                return;
            }

            // If no matching chain exists and max chains reached, tie and sell an existing chain
            os << "No matching chain and maximum chains reached. Selling a chain...\n";
            sellAndReplaceChain(cardToPlay, os);
        }

        Card* discardCard(int index) {
        Card* discardedCard = hand[index]; 
        if (discardedCard == nullptr) {
            throw std::out_of_range("Invalid index for discard.");
        }
        std::cout<<coins<<std::endl;
        return discardedCard;
    }
    


};


#endif