#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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


// Implementing the write() method for the Card class
void Card::write() {
    std::string colorName;
    switch (col) {
        case club: colorName = "Clubs"; break;
        case diamond: colorName = "Diamonds"; break;
        case heart: colorName = "Hearts"; break;
        case spade: colorName = "Spades"; break;
    }

    
    if (value() > 1 && value() <= 10) {
        cout << value();
    } else if(value() == 1){
		cout << "Ace";
	}
	 else if (value() == 11) {
        cout << "Jack";
    } else if (value() == 12) {
        cout << "Queen";
    } else if (value() == 13) {
        cout << "King";
    }
    cout <<" of "<< colorName;
    cout << endl;
}

// Implementing the novSet() method for the CardsSet class
void CardsSet::novSet() {
    int x = 0;
    for (int i = 1; i < 14; ++i) {
        set[x++] = Card(club, i);
        set[x++] = Card(diamond, i);
        set[x++] = Card(heart, i);
        set[x++] = Card(spade, i);
    }
	number = 52;
}

// Implementing the shuffle() method for the CardsSet class
void CardsSet::shuffle() {
	
    if (number == 0 || number == 1) {
        cout << "No cards to shuffle." << endl;
        return;
    }
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < number; i++) {
        int j = rand() % number;
        swap(set[i], set[j]);
    }
}

// Implementing the take() method for the CardsSet class
Card CardsSet::take() {
	
    if (number == 0) {
        throw std::out_of_range("Empty card set. Cannot take.");
    }
    Card res = set[number - 1];
    number--;
    return res;
}

// Implementing the put() method for the CardsSet class
void CardsSet::put(Card k) {
    if (number == 52) {
        cout << "Deck is full cannot add card." << endl;
        return;
    }
    set[number] = k;
    number++;
}

// Implementing the lookIn() method for the CardsSet class
Card CardsSet::lookIn(int no) {
    if (number - no < 0) {
        throw std::out_of_range("Cannot access card out of set bounds.");
    }
    return set[number - no];
}

// Implementing the play() method for the Player class
int Player::play() {
    bool wantsMore = true;
    int totalPoints = 0;
    if(!computer){
        cout << "Your turn" << std::endl;

        while (wantsMore && totalPoints <= 21) {
            Card drawnCard = packet.take();
            inHand.put(drawnCard);
            cout<< "You get Card: ";
            drawnCard.write();
            cout<<endl;

            totalPoints = countPoints();

            cout << "Your score is " << totalPoints <<" points"<<endl;
            if (totalPoints > 21 || totalPoints == 21) {
                break;
            }

            char response;
            cout << "Any additional Card ? ";
            cin >> response;
            wantsMore = (response == 'y');
        }
    } else{
        cout << "Computers turn" << std::endl;
        while (totalPoints < 17) {
            Card drawnCard = packet.take();
            inHand.put(drawnCard);
            cout << "Computer gets Card: ";
            drawnCard.write();
            cout << endl;

            totalPoints = countPoints();
            cout << "Computer's score is " << totalPoints << " points" << endl;

            if (totalPoints >= 21) {
                break;
            }
        }
    }
    inHand = CardsSet();
    return totalPoints; 
}

// Implementing the countPoints() method for the Player class (private)
int Player::countPoints() {
    int points = 0;
    bool hasAce = false;
	int cardnum = inHand.numCards();

    for (int i = 0; i <cardnum; i++) {
		Card card = inHand.lookIn(i+1);
        if (card.value() == 1) {
            hasAce = true;
            points += 14;  
        } else {
            points += card.value();
        }
    }

    
    if (points > 21 && hasAce) {
        points -= 13; 
    }

    return points;
}
