/*Ex1b - a3 CSI2372A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
	Color color;
	Face face;
};

typedef Card Hand[5];

Color inputColor() {
	int color;
	cout << "Enter color (0: club, 1: diamond, 2: spades, 3: heart): ";
	cin >> color;
	return static_cast<Color>(color);
}

Face inputFace() {
	int face;
	cout << "Enter face (0: seven, 1: eight, 2: nine, 3: ten, 4: jack, 5: queen, 6: king, 7: ace): ";
	cin >> face;
	return static_cast<Face>(face);
}

bool testPair(const Hand& h) {
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			if (h[i].face == h[j].face) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	Hand myHand;

	for (int i = 0; i < 5; ++i) {
		cout << "Enter details for card " << i + 1 << ":" << endl;
		myHand[i].color = inputColor();
		myHand[i].face = inputFace();
	}

	// Check if the hand contains at least one pair
	cout << "\nI have at least: " << testPair(myHand) << " pair" << endl;

	return 0;
}


