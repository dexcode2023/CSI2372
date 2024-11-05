#include <cstdlib>
#include <ctime>


class CardsSet {
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no);
    void empty() { number = 0; }
private:
    Card set[52];
    int number;
};

void CardsSet::novSet(){

}

void CardsSet::shuffle(){

}

Card CardsSet::take(){

}

void CardsSet::put(Card k){

}

Card CardsSet::lookIn(int no){

}