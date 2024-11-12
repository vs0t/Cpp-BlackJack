/**
 * @file game.cpp
 * @author Evan Aarons-Wood (evanaaronswood@gmail.com)
 * @brief This is the main file for the BlackJack game. It will prompt the user for the number of players and the threshold for the dealer to hit. It will then play the game and determine the outcome.
 * @version 1.0
 * @date 2024-11-10
 *
 *
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <utils.h>
#include <Card.h>

using namespace std;
using namespace chants;

int main(int argc, char **argv)
{
    // Default threshold if no argv
    int threshold = 17;
    if (argc == 2 && isANumber(argv[1]))
    {
        // cout << argv[1];
        string strThreshold = argv[1];
        threshold = stoi(strThreshold);
    }
    cout << "Threshold: " << threshold << endl;

    vector<Player> players;
    Deck deck(true);
    EnterPlayers(players, threshold);
    PlayBlackJack(players, deck);
    SortPlayers(players);
    DetermineOutcomeOfGame(players);
}
