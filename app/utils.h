/**
 * @file utils.h
 * @author Evan Aarons-Wood
 * @brief This file contains the implementation of utility functions for the BlackJack game. It includes functions for sorting players, entering player details, executing the game, and determining game outcomes.
 * @version 1
 * @date 2024-11-01
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> // Required for sorting functionality
#include <Card.h>    // Custom Card class used in game mechanics
#include <Deck.h>    // Custom Deck class for deck operations
#include <Player.h>  // Custom Player class representing game participants

namespace chants
{

    // Comparator function to help sort players by score, in descending order
    bool comparator(Player &lhs, Player &rhs)
    {
        return lhs.Score() > rhs.Score();
    }

    // Utility function to check if a string contains only numeric characters
    bool isANumber(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!isdigit(s[i])) // Check each character for numeric status
            {
                return false;  // Return false if any character is non-numeric
            }
        }
        return true; // Return true if all characters are numeric
    }

    // Function to sort players by score and mark the winner(s)
    void SortPlayers(vector<Player> &players)
    {
        // Use comparator function to sort players by their scores
        sort(players.begin(), players.end(), &comparator);

        int highestScore = 0;
        for (int i = 0; i < players.size(); i++)
        {
            // Check if player score is within allowed limit (21)
            if (players[i].Score() <= 21)
            {
                // Update highest score and mark player as winner if eligible
                if (players[i].Score() >= highestScore)
                {
                    players[i].isWinner = true;
                    highestScore = players[i].Score();
                }
            }
        }
    }

    // Function to gather player information and initialize Player objects
    void EnterPlayers(vector<Player> &players, int threshold)
    {
        bool Done = false;
        string strInput;
        int input;
        while (!Done)
        {
            cout << "Number of players: ";
            cin >> strInput; // Get the number of players
            input = stoi(strInput);
            for (int i = 0; i < input; i++)
            {
                cout << "Name for player number " << i + 1 << ": ";
                cin >> strInput; // Capture player names
                players.push_back(Player(strInput, threshold)); // Add player to the list
            }
            Done = true;
        }
    }

    // Function to execute each player's game actions in BlackJack
    void PlayBlackJack(vector<Player> &players, Deck &deck)
    {
        for (int i = 0; i < players.size(); i++)
        {
            // Deal two initial cards to the player
            try
            {
                players[i].AddCard(deck.Deal());
                players[i].AddCard(deck.Deal());
            }
            catch (runtime_error e)
            {
                cout << "OVER DELT!" << endl; // Error if deck is empty
                exit(-1);                    // Exit with error code
            }

            while (true)
            {
                // Continue drawing cards if player's score is below their threshold
                if (players[i].Score() < players[i].GetThreshold())
                {
                    try
                    {
                        players[i].AddCard(deck.Deal());
                    }
                    catch (runtime_error e)
                    {
                        cout << "OVER DELT!" << endl; // Error if deck is empty
                        exit(-2);                    // Exit with error code
                    }
                }
                else
                {
                    // Mark the player as busted if score exceeds 21
                    if (players[i].Score() > 21)
                        players[i].isBusted = true;

                    players[i].FlipAllCards(true); // Reveal all cards for this player
                    break;                         // End the player's turn
                }
            }
        }
    }

    // Function to display the outcome of the game for each player
    void DetermineOutcomeOfGame(vector<Player> &players)
    {
        bool busted = false;

        // Display formatted headers for player data
        cout << "\n\n";
        cout << setw(10) << right << "Player" << setw(10) << right << "Score" << right << setw(10) << "Results" << " " << left << setw(30) << "Hand" << endl;
        cout << setw(10) << right << "------" << setw(10) << right << "-----" << right << setw(10) << "-------" << " " << left << setw(30) << "------------------------------" << endl;

        // Iterate through each player and output their game result
        for (int i = 0; i < players.size(); i++)
        {
            if (players[i].isBusted)
            {
                busted = true;
                cout << setw(10) << right << players[i].GetName() << setw(10) << right << players[i].Score()
                     << setw(10) << "BUSTED" << setw(1) << "" << left << setw(30) << players[i].ShowHand() << endl;
            }
            else if (players[i].isWinner)
            {
                busted = true;
                cout << setw(10) << right << players[i].GetName() << setw(10) << right << players[i].Score()
                     << setw(10) << "WINNER" << setw(1) << "" << left << setw(30) << players[i].ShowHand() << endl;
            }
            else
            {
                cout << setw(10) << right << players[i].GetName() << setw(10) << right << players[i].Score()
                     << setw(10) << "" << setw(1) << "" << setw(30) << left << players[i].ShowHand() << endl;
            }
        }

        cout << "\n\n";
    }
}
