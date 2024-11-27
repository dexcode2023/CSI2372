#include <iostream>
#include <fstream>
#include "CardFactory.h"
#include "Table.h"

int main() {
    // Initialize the game
    CardFactory* factory = CardFactory::getFactory();
    Deck deck = factory->getDeck();

    // Get player names
    std::cout << "Enter name for Player 1: ";
    std::string name1;
    std::cin >> name1;

    std::cout << "Enter name for Player 2: ";
    std::string name2;
    std::cin >> name2;

    Player* player1 = new Player(name1);
    Player* player2 = new Player(name2);

    // Deal 5 cards to each player
    for (int i = 0; i < 5; ++i) {
        player1->addCardToHand(deck.draw());
        player2->addCardToHand(deck.draw());
    }

    Table table(player1, player2, deck);
    
    TradeArea& TA = table.getTradeArea();

    DiscardPile& DP = table.getDiscardPile();

    // Main game loop
    std::string winnerName;
    while (!table.win(winnerName)) {
        for (Player* currentPlayer : {player1, player2}) {
            std::cout << "---------------------------------\n";
            std::cout << "Current Table State:\n" << table;

            // Draw a card
            if (!deck.empty()) {
                Card* drawnCard = deck.draw();
                std::cout << currentPlayer->getName() << " draws a card: " << *drawnCard << "\n";
                currentPlayer->addCardToHand(drawnCard);
            }

            // Show the player's hand
            std::cout << currentPlayer->getName() << "'s hand: ";
            currentPlayer->printHand(std::cout, true);
            std::cout << "\n";

            //If trade area is not empty add bean cards from the TradeArea to chains or discard them.
            if(TA.numCards() > 0){
                for (Card* tradeCard : TA.getCards()) {
                    bool Chained = false;
                    std::cout << "Considering card: " << *tradeCard << "\n";


                    // Try to add the card to a chain
                    for (int i = 0; i < currentPlayer->getNumChains(); ++i) {
                        try {
                            currentPlayer->operator[](i) += tradeCard;
                            std::cout << currentPlayer->getName() << " chains " << *tradeCard << " to Chain " << i + 1 << "\n";
                            Chained = true;
                            break; 
                        } catch (IllegalType&) {
                            continue; 
                        }
                    }

                    // If not chained, discard the card
                    if (!Chained) {
                        DP += tradeCard;
                        std::cout << currentPlayer->getName() << " discards " << *tradeCard << "\n";
                    }
                }


            }

            if (currentPlayer->getNumChains() < 3 && currentPlayer->getNumCoins() >= 3) {
                char choice;
                std::cout << "Do you want to buy a third chain for 3 coins? (y/n): ";
                std::cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    try {
                        currentPlayer->buyThirdChain();
                        std::cout << currentPlayer->getName() << " buys a third chain!\n";
                    } catch (const NotEnoughCoins& e) {
                        std::cout << "Not enough coins to buy a third chain." << std::endl;
                    }
                }
            }
            

             currentPlayer->playCard(std::cout);


            
        }
    }

   

    return 0;
}
