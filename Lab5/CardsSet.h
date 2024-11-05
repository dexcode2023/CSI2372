#include <cstdlib>
#include <ctime>
#include "Card.h"


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

void CardsSet::novSet() {
    int x = 0;
    
    for (int i = 1; i < 14; ++i) {
        set[x++] = Card(club, i);
        set[x++] = Card(diamond, i);
        set[x++] = Card(heart, i);
        set[x++] = Card(spade, i);
    }
    
}

void CardsSet::shuffle(){
    if (number == 0 || number == 1) {
        cout << "No cards to shuffle." << endl; 
    }
    srand(static_cast<unsigned int>(time(0)));
    for(int i = 0; i <number;i++){
        int j = rand() % number;
        swap(set[i],set[j]);
    }
}

Card CardsSet::take(){
    if(number==0){
        throw std::out_of_range("Empty card set. Cannot take.");
    }
    Card res = set[number - 1];
    number--;
    return res;
}

void CardsSet::put(Card k){
    if(number == 52){
        cout<<"Deck is full cannot add card."<<endl;
        return;
    }
    set[number] = k;
    number++;

}

Card CardsSet::lookIn(int no){
    if(number-no < 0 ){
        throw std::out_of_range("Cannot access card out of set bounds.");
    }
    return set[number-no];
}