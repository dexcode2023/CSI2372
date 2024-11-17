#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>


//abstract class Card.
class Card{
    public:

    virtual ~Card(){};

    virtual int getCardsPerCoin(int coins) const = 0;

    virtual std::string getName() const = 0;

    virtual void print(std::ostream&  out) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Card&  card){
        card.print(os);
        return os;
    }
};

//Below  are all concrete class implementations of card for all different bean types.
//Each class implements a concrete version of GetName and print.

class Blue : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 4;
            case 2: return 6;
            case 3: return 8;
            case 4: return 10;
            default: return 0;
        }
    }
    std::string getName() const override { return "Blue"; }
    void print(std::ostream& out) const override { out << 'B'; }
};

class Chili : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 3;
            case 2: return 6;
            case 3: return 8;
            case 4: return 9;
            default: return 0;
        }
    }
    std::string getName() const override { return "Chili"; }
    void print(std::ostream& out) const override { out << 'C'; }
};

class Chili: public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 3;
            case 2: return 6;
            case 3: return 8;
            case 4: return 9;
            default: return 0;
        }
    }
    std::string getName() const override { return "Chili"; }
    void print(std::ostream& out) const override { out << 'C'; }
};

class Stink  : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 3;
            case 2: return 5;
            case 3: return 7;
            case 4: return 8;
            default: return 0;
        }
    }
    std::string getName() const override { return "Stink"; }
    void print(std::ostream& out) const override { out << 'S'; }
};

class Green : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 3;
            case 2: return 5;
            case 3: return 6;
            case 4: return 7;
            default: return 0;
        }
    }
    std::string getName() const override { return "Green"; }
    void print(std::ostream& out) const override { out << 'G'; }

};

class soy:public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 2;
            case 2: return 4;
            case 3: return 6;
            case 4: return 7;
            default: return 0;
        }
    }
    std::string getName() const override { return "soy"; }
    void print(std::ostream& out) const override { out << 's'; }
};

class black:public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 2;
            case 2: return 4;
            case 3: return 5;
            case 4: return 6;
            default: return 0;
        }
    }
    std::string getName() const override { return "black"; }
    void print(std::ostream& out) const override { out << 'b'; }
};

class Red:public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 2;
            case 2: return 3;
            case 3: return 4;
            case 4: return 5;
            default: return 0;
        }
    }
    std::string getName() const override { return "Red"; }
    void print(std::ostream& out) const override { out << 'R'; }


};

class garden: public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 100;
            case 2: return 2;
            case 3: return 3;
            case 4: return 100;

            default: return 0;
        }
    }
    std::string getName() const override { return "garden"; }
    void print(std::ostream& out) const override { out << 'g'; }
};



#endif