/**
 * @file Deck.h
 * @author evan aarons-wood (evanaaronswood@gmail.com)
 * @brief Header file for the Deck class, which manages a collection of Card objects and provides functionalities to build, shuffle, and deal cards.
 * @version 1.2
 * @date 2024-11-09
 *
 *
 */

#pragma once

#include <string>
#include <vector>
#include <Card.h>

using namespace std;

namespace chants
{

    /**
     * @brief Deck class for managing a collection of cards. Includes functionalities to build, shuffle, and deal cards, as well as retrieve the deck's current state.
     */
    class Deck
    {
    private:
        /// @brief Vector to hold the collection of Card objects in the deck.
        vector<Card> deck;

        /**
         * @brief Initializes and builds the standard deck of cards.
         */
        void buildDeck();

        /**
         * @brief Randomly shuffles the deck of cards to ensure randomized order.
         */
        void shuffleDeck();

    public:
        /**
         * @brief Construct a new Deck object, optionally shuffled.
         * @param shuffle Determines whether the deck should be shuffled upon creation.
         */
        Deck(bool shuffle);

        /**
         * @brief Deals a card from the top of the deck.
         * @return Card object representing the dealt card.
         */
        Card Deal();

        /**
         * @brief Provides a string representation of the entire deck.
         * @return string representing the deck's current state.
         */
        string ToString();

        /**
         * @brief Returns the number of cards currently in the deck.
         * @return int representing the count of remaining cards in the deck.
         */
        int CardsInDeck();
    };
}