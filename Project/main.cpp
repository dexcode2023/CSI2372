#include <iostream>
#include <fstream>
#include "CardFactory.h"
#include "Table.h"

int main() {


    // Initialize the game.
    CardFactory* factory = CardFactory::getFactory();
    Deck deck = factory->getDeck();

    // Get player names.
    std::cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
    std::cout << "Please enter name for Player 1: ";
    std::string name1;
    std::cin >> name1;

    std::cout << "Please enter name for Player 2: ";
    std::string name2;
    std::cin >> name2;

    Player* player1 = new Player(name1);
    Player* player2 = new Player(name2);
    std::cout << "Players created: " << name1 << " and " << name2 << "\n";
    std::cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
    
    // Deal 5 cards to each player.
    for (int i = 0; i < 5; ++i) {
        player1->addCardToHand(deck.draw());
        player2->addCardToHand(deck.draw());
    }

    Table table(player1, player2, deck);
    
    TradeArea& TA = table.getTradeArea();

    DiscardPile& DP = table.getDiscardPile();

    // Main game loop.
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

            //STEP 1:
            //If trade area is not empty add bean cards from the TradeArea to chains or discard them.
            if(TA.numCards() > 0){
                for (Card* tradeCard : TA.getCards()) {
                    bool Chained = false;
                    std::cout << "Considering card: " << *tradeCard << "\n";


                    // Try to add the card to a chain.
                    for (int i = 0; i < currentPlayer->getNumChains(); ++i) {

                        if(tradeCard->getName() == currentPlayer->operator[](i).getType()){
                            currentPlayer->operator[](i) += tradeCard; 
                            std::cout << currentPlayer->getName() << " chains " << *tradeCard << " to Chain " << i + 1 << "\n";
                            Chained = true;
                            break;
                        } else{
                            continue;
                        }


                  
                    }

                    // If not chained, discard the card.
                    if (!Chained) {
                        DP += tradeCard;
                        std::cout << currentPlayer->getName() << " discards " << *tradeCard << "\n";
                    }
                }


            }
            //option to buy a third chain.
            if (currentPlayer->getNumChains() < 3 && currentPlayer->getNumCoins() >= 3) {
                char choice;
                std::cout << "𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉\n";                
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
            //STEP 2
            //Forced to play top card and sell chains if necessary.
             currentPlayer->playCard(std::cout);

             //allowed to repeat step 2 here.

             bool runitback = true;
             while(runitback){

                char check;
                std::cout << currentPlayer->getName() << "'s updated hand: ";
                currentPlayer->printHand(std::cout, true);
                std::cout << "\n𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽𓇽";
                std::cout<<"\nWould you like to play another card from hand? (y/n): ";
                std::cin>>check;
                if(check == 'y' || check == 'Y'){
                    currentPlayer->playCard(std::cout);
                    runitback = true;
                }
                else{
                    runitback = false;
                }

             }

            //STEP4
            //Optionally discard one card from hand on DP face up.
            std::cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";            
            std::cout << "Would you like to discard a card from your hand? (y/n): ";
            char discardChoice;
            std::cin >> discardChoice;


            if (discardChoice == 'y' || discardChoice == 'Y') {
                    currentPlayer->printHand(std::cout, true); // Show the full hand
                    std::cout << "\nSelect the index of the card to discard: ";
                    int discardIndex;
                    std::cin >> discardIndex;
                    
                    Card* discardedCard = currentPlayer->discardCard(discardIndex); // Implement discardCard in Player
                    DP += discardedCard;
                    std::cout << currentPlayer->getName() << " discards " << *discardedCard << "\n";
                }
            

            // Step 5: Draw three cards from the deck into the trade area
            for (int i = 0; i < 3 && !deck.empty(); ++i) {
                Card* hold = deck.draw();
                std::cout <<"drawing card and adding to Trade Area:"<< *hold << "\n";
                TA += hold;
            }

            // Move cards from the discard pile to the trade area if they match
            while (!DP.empty() && TA.legal(DP.top())) {
                Card* discardCard = DP.pickUp();
                TA += discardCard;
                std::cout << "Moved " << *discardCard << " from discard pile to trade area.\n";
            }

            // The player chooses whether to chain or leave the cards in the trade area
            std::cout<<"Your hand: "<<std::endl;
            currentPlayer->printHand(std::cout,true);
            std::cout<<std::endl;

            for (Card* tradeCard : TA.getCards()) {
                std::cout << "𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉𓆉\n"; 
                std::cout << "Would you like to chain " << *tradeCard << "? (y/n): ";
                char chainChoice;
                std::cin >> chainChoice;
                if (chainChoice == 'y'||chainChoice == 'Y') {
                    currentPlayer->addCardToHand(tradeCard);
                    currentPlayer->playCard(std::cout); 
                    currentPlayer->printHand(std::cout,true);
                }
                else{
                    std::cout<< "Card: "<< *tradeCard  << " left to be traded."<<"\n";
                    continue;
                }
            }

            // Step 6: Draw two cards from the deck and add them to the player's hand
            for (int i = 0; i < 2 && !deck.empty(); ++i) {
                
                currentPlayer->addCardToHand(deck.draw());
            }

            // Print the updated Trade Area
            std::cout << "Trade Area after adding cards: " << TA << "\n";

            // End of turn, check for winner
            if (table.win(winnerName)) {
                std::cout << "𓇼 Game Over! Winner 𓇼: " << winnerName << "\n";
                break;
            }





        }
    }


    delete player1;
    delete player2;

   

    return 0;
}
