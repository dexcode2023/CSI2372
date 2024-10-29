/*Ex1a - a3 CSI2372A*/
#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
    Color color;
    Face face;
};

int main() {
    Card game[32];

    const char* colorNames[] = { "club", "diamond", "spades", "heart" };
    const char* faceNames[] = { "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };

    int index = 0;
    for (int c = 0; c < 4; ++c) {        // Loop through colors
        for (int f = 0; f < 8; ++f) {    // Loop through faces
            game[index].color = static_cast<Color>(c);
            game[index].face = static_cast<Face>(f);
            index++;
        }
    }

    for (int i = 0; i < 32; ++i) {
        cout << "Card " << i + 1 << ": " << colorNames[game[i].color] 
             << " of " << faceNames[game[i].face] << endl;
    }

    return 0;
}


