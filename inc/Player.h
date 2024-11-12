/**
 * @file Player.h
 * @author Evan Aarons-Wood (evanaaronswood@gmail.com)
 * @brief Header file for the Player class, which represents a player in the card game. The Player class manages the player's hand, score, and win conditions.
 * @version 1
 * @date 2024-11-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <vector>
#include <string>
#include <Card.h>

using namespace std;
namespace chants
{

    /**
     * @brief The Player class represents a player in the card game
     *
     */
    class Player
    {
    private:
        /// @brief The name of the player
        string _name;
        /// @brief The hand of the player
        vector<Card> _hand;
        /// @brief The threshold for the player to win
        int _winThreshold;

        /**
         * @brief Calculate the score of the player
         *
         * @return int
         */
        int calculateScore();

    public:
        /// @brief The score of the player
        bool isBusted;

        /// @brief The score of the player
        bool isWinner;

        /**
         * @brief Construct a new Player object
         *
         * @param name
         * @param threshold
         */
        Player(string name, int threshold);

        /**
         * @brief Get the Threshold object
         *
         * @return int
         */
        int GetThreshold();

        /**
         * @brief Get the Name object
         *
         * @return string
         */
        string GetName();

        /**
         * @brief Add a card to the player's hand
         *
         * @param card
         */
        void AddCard(Card card);

        /**
         * @brief Show the player's hand
         *
         * @return string
         */
        string ShowHand();

        /**
         * @brief Empty the player's hand
         *
         */
        void EmptyHand();

        /**
         * @brief Count the number of cards in the player's hand
         *
         * @return int
         */
        int CountCards();

        /**
         * @brief Get the Score object
         *
         * @return int
         */
        int Score();

        /**
         * @brief Flip a card in the player's hand
         *
         */
        void FlipCard(int);

        /**
         * @brief Flip all cards in the player's hand
         *
         * @param faceUp
         */
        void FlipAllCards(bool faceUp);
    };
}