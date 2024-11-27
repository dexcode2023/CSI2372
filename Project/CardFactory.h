#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "Card.h"
#include "Deck.h"


class CardFactory{


    private:

        static CardFactory* instance;
        Deck deck;

        CardFactory() {
        for (int i = 0; i < 20; ++i) deck.addCard(new Blue());
        for (int i = 0; i < 18; ++i) deck.addCard(new Chili());
        for (int i = 0; i < 16; ++i) deck.addCard(new Stink());
        for (int i = 0; i < 14; ++i) deck.addCard(new Green());
        for (int i = 0; i < 12; ++i) deck.addCard(new soy());
        for (int i = 0; i < 10; ++i) deck.addCard(new black());
        for (int i = 0; i < 8; ++i) deck.addCard(new Red());
        for (int i = 0; i < 6; ++i) deck.addCard(new garden());

        deck.shuffle();
    }


    public:

        static CardFactory* getFactory() {
            if (!instance) {
                instance = new CardFactory();
            }
            return instance;
        }

        Deck getDeck() {
            return deck;
        }



        CardFactory(const CardFactory&) = delete;
        
        CardFactory& operator=(const CardFactory&) = delete;

};
CardFactory* CardFactory::instance = nullptr;

#endif