
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

#include "myFile.h"
#include "Card.h"
#include "CardsSet.h"
#include "Player.h"

int main() {
	CardsSet packet;
	Player you(packet, false);
	Player me(packet, true);
	char answer[3];
	bool continuous = true;
	cout << "Hello! " << endl;
	while (continuous)
	{
		cout << "A new game? " << endl;
		cin >> answer;
		continuous = answer[0] == 'y';
		if (continuous)
		{
			packet.novSet();
			packet.shuffle();
			packet.take();
			int p1 = you.play();
			if (p1 > 21) {
				cout << "You lost! " << endl;
			}
			else if (p1 == 21) {
				cout << "You won! " << endl;
			}
			else // the computer must play
			{
				int p2 = me.play();
				if (p2 <= 21 && p2 >= p1) {
					cout << "You lost! " << endl;
				}
				else {
					cout << "You won! " << endl;
				}
			}
		}
	}
	return 0;
}

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


