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
        std::vector<Chain<Card>*> chains;

        int maxchains;
        int coins;

        Hand hand;

    public:

        Player(std::string& playerName): name(playerName), coins(0), maxchains(2){
            chains.push_back(new Chain<Card>());
            chains.push_back(new Chain<Card>());

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

        int getNumChains() const{
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

        Chain<Card>& operator[](int i) {

            if (i < 0 || i >= chains.size()) {
                throw std::out_of_range("Invalid chain index");
            }
            return *chains[i];
        }

        void buyThirdChain() {
            if (coins < 3) {
                throw NotEnoughCoins();
            }
            coins -= 3;
            maxchains = 3;
            chains.push_back(new Chain<Card>());
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
   


};


#endif