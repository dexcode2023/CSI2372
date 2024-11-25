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
            
        }


};

#endif