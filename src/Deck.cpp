/**
 * @file Deck.cpp
 * @author Evan Aarons-Wood (evanaaronswood@gmail.com)
 * @brief Deck class implementation file, which manages a collection of Card objects and provides functionalities to build, shuffle, and deal cards.
 * @date 2024-11-10
 *
 *
 */
#include <iostream>
#include <Deck.h>

namespace chants
{

    /**
     * @brief Parameterized constructor that, when true, creates and shuffles
     *        52 Cards, and when false, creates 52 Cards in a vector without shuffling.
     * 
     * @param shuffle Indicates if the deck should be shuffled upon creation.
     */
    Deck::Deck(bool shuffle)
    {
        if (shuffle)
        {
            buildDeck();
            shuffleDeck();
        }
        else
        {
            buildDeck();
        }
    }

    /**
     * @brief Builds a standard deck of 52 cards with 4 suits and 13 ranks each.
     */
    void Deck::buildDeck()
    {
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 13; j++)
            {
                Card card(j, i, false);
                deck.push_back(card);
            }
        }
    }

    /**
     * @brief Shuffles the deck by randomly swapping cards multiple times for randomness.
     */
    void Deck::shuffleDeck()
    {
        srand(time(nullptr));
        for (int i = 0; i < 10000; i++)
        {
            int index1 = rand() % 52;
            int index2 = rand() % 52;
            Card tempCard = deck[index1];
            deck[index1] = deck[index2];
            deck[index2] = tempCard;
        }
    }

    /**
     * @brief Retrieves the number of cards currently left in the deck.
     *
     * @return int Number of remaining cards.
     */
    int Deck::CardsInDeck()
    {
        return deck.size();
    }

    /**
     * @brief Deals a card from the top of the deck and removes it from the deck.
     *
     * @return Card The dealt card from the deck.
     * @throws runtime_error if the deck is empty.
     */
    Card Deck::Deal()
    {
        if (deck.size() > 1)
        {
            Card card = deck[0];
            deck.erase(deck.begin());
            return card;
        }
        else
        {
            throw runtime_error("Deck is out of cards.");
        }
    }

    /**
     * @brief Returns a string representation of the entire deck, listing each card.
     *
     * @return string String with all cards in the deck, each on a new line.
     */
    string Deck::ToString()
    {
        string temp = "";
        for (Card card : deck)
        {
            temp += card.ToString() + "\n";
        }
        return temp;
    }
}