#include <iostream>
using namespace std;
#include <cassert> 
enum color { club, diamond, heart, spade };

class Card {
public:
    Card(color c = club, int v = 1);
    int value() { return val; }
    void write();
private:
    color col;
    int val;
};

Card::Card(color c, int v) {
    assert(v >= 1 && v <= 13); 
    val = v;
}

void Card::write() {
    switch (col) {
        case club: cout << "Club "; break;
        case diamond: cout << "Diamond "; break;
        case heart: cout << "Heart "; break;
        case spade: cout << "Spade "; break;
    }

    if (val >= 2 && val <= 10) {
        cout << val; 
    } else {
        switch (val) {
            case 1: cout << "Ace"; break;
            case 11: cout << "Jack"; break;
            case 12: cout << "Queen"; break;
            case 13: cout << "King"; break;
        }
    }

    cout << endl;
}

int main() {
    Card card1(heart, 1);  
    Card card2(spade, 11); 
    Card card3(diamond, 7); 

    card1.write();
    card2.write();
    card3.write();

    return 0;
}
