#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "Player.h"



class Table{

    private:

        Player* p1;
        Player* p2;

        Deck D;

        DiscardPile DP;

        TradeArea TA;

    public:

        Table(Player* player1, Player* player2, Deck& d): p1(player1), p2(player2),D(d){

        }

        ~Table(){
            delete p1;
            delete p2;

        }


        bool win(std::string& name) const{

            if(D.empty()){
                if (p1->getNumCoins() > p2->getNumCoins()) {
                    name = p1->getName();
                }
                else if(p1->getNumCoins() < p2->getNumCoins()){
                    name = p2->getName();
                }
                else{
                    name = "Tie";
                }
                return true;

            } else{
                return false;
            }
            


        }

        TradeArea& getTradeArea() {
            return TA;
        }

        DiscardPile& getDiscardPile(){
            return DP;
        }




        void printHand(bool allcards) const {
            std::cout << p1->getName() << "'s hand: ";
            p1->printHand(std::cout, allcards);
            std::cout << "\n";

            std::cout << p2->getName() << "'s hand: ";
            p2->printHand(std::cout, allcards);
            std::cout << "\n";
        }

        friend std::ostream& operator<<(std::ostream& os, const Table& table) {
            os << "Player 1: " << *(table.p1) << "\n";
            os << "Player 2: " << *(table.p2) << "\n";
            //not  printing deck here as there are issues with it  updating properly
            os << "Discard Pile: " << table.DP << "\n";
            os << "Trade Area: " << table.TA << "\n";
            return os;
        }




};

#endif