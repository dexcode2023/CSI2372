#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include <string>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class TradeArea{

    private:
        std::list<Card*> tradespace;
    
    public:

        TradeArea& operator+=(Card* card){
            tradespace.push_back(card);
            return *this;
        }

        bool legal(Card* card) const{
            for(const auto& carda: tradespace){
                if(carda->getName() == card->getName()){
                    return true;
                }
            }
            return false;
        }

        Card* trade(const std::string& bean){

            for(auto card = tradespace.begin(); card != tradespace.end(); ++card){
                if((*card)->getName() == bean){
                    Card* hold = *card;
                    tradespace.erase(card);
                    return hold;
                }
            }
            return nullptr;
        }

        int numCards() const{
            return tradespace.size();
        }

        void print(std::ostream& os) const{

            for (const auto& card : tradespace){
                card->print(os);
                os<< " ";
            }
        }

        friend std::ostream& operator<<(std::ostream& os,const TradeArea& tradearea){
            tradearea.print(os);
            return os;
        }

        const std::list<Card*>& getCards() const {
            return tradespace;
        }


};

#endif