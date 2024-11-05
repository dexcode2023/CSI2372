#include <iostream>
#include "myFile.h"
#include "Card.h"
#include "Player.h"
#include "CardsSet.h"

void Card::write() {
    std::string colorName;
    switch (color) {
        case club: colorName = "Club"; break;
        case diamond: colorName = "Diamond"; break;
        case heart: colorName = "Heart"; break;
        case spade: colorName = "Spade"; break;
    }

    std::cout << colorName << " ";
    if (value >= 1 && value <= 10) {
        std::cout << value;
    } else if (value == 11) {
        std::cout << "Jack";
    } else if (value == 12) {
        std::cout << "Queen";
    } else if (value == 13) {
        std::cout << "King";
    }
    std::cout << std::endl;
}

void Player::play() {
    bool wantsMore = true;
    int totalPoints = 0;
    cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★" <<;
    std::cout << "Starting your turn..." << std::endl;

    while (wantsMore && totalPoints <= 21) {
        Card drawnCard = packet.take();
        hand.push_back(drawnCard);
        drawnCard.write();

        totalPoints = countPoints();

        std::cout << "Current total points: " << totalPoints << std::endl;
        if (totalPoints > 21) {
            std::cout << "You exceeded 21 points!" << std::endl;
            break;
        }
        char response;
        std::cout << "Do you want an additional card? (y/n): ";
        std::cin >> response;
        wantsMore = (response == 'y');
    }
}
int Player::countPoints() {
    int points = 0;
    bool hasAce = false;
    for (const Card& card : hand) {
        if (card.getValue() == 1) {
            hasAce = true;
            points += 14; 
        } else if (card.getValue() >= 11 && card.getValue() <= 13) {
            points += 10; 
        } else {
            points += card.getValue();
        }
    }
    if (points > 21 && hasAce) {
        points -= 13; 
    }
    return points;
}



