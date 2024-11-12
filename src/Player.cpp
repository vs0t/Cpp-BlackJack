/**
 * @file Player.cpp
 * @author evan aarons-wood (evanaaronswood@gmail.com)
 * @brief Player class implementation, which represents a player in the card game. The Player class manages the player's hand, score, and win conditions.
 * @version 1.0
 * @date 2024-10-31
 *
 *
 */
#include <stdexcept>
#include <Player.h>

namespace chants
{

    /**
     * @brief Construct a new Player object with a specified name and score threshold.
     *
     * @param name Name of the player.
     * @param threshold Win threshold for the player, between 1 and 21.
     */
    Player::Player(string name, int threshold)
    {
        _name = name;

        if (threshold < 1 || threshold > 21)
            throw runtime_error("Threshold must be between 1 and 21");

        _winThreshold = threshold;
        isBusted = false;
        isWinner = false;
    }

    /**
     * @brief Retrieves the win threshold score for the player.
     *
     * @return int Player's win threshold score.
     */
    int Player::GetThreshold()
    {
        return _winThreshold;
    }

    /**
     * @brief Calculates and returns the player's current score.
     *
     * @return int Player's current score based on their hand.
     */
    int Player::Score()
    {
        return calculateScore();
    }

    /**
     * @brief Flips all cards in the player's hand face up or down based on the parameter.
     *
     * @param faceUp Boolean indicating whether to flip cards face up (true) or face down (false).
     */
    void Player::FlipAllCards(bool faceUp)
    {
        for (int i = 0; i < _hand.size(); i++)
        {
            _hand[i].isFaceUp = faceUp;
        }
    }

    /**
     * @brief Flips a specific card in the player's hand face up.
     *
     * @param intCard Index of the card in the hand to flip face up.
     */
    void Player::FlipCard(int intCard)
    {
        _hand[intCard].isFaceUp = true;
    }

    /**
     * @brief Adds a card to the player's hand.
     *
     * @param card Card to be added to the hand.
     */
    void Player::AddCard(Card card)
    {
        _hand.push_back(card);
    }

    /**
     * @brief Provides a string representation of the player's hand, showing each card.
     *
     * @return string Player's hand represented as a string.
     */
    string Player::ShowHand()
    {
        string temp = "";
        for (Card card : _hand)
        {
            temp += card.ToString() + " ";
        }
        return temp;
    }

    /**
     * @brief Clears all cards from the player's hand.
     */
    void Player::EmptyHand()
    {
        _hand.clear();
    }

    /**
     * @brief Counts the number of cards in the player's hand.
     *
     * @return int Number of cards in hand.
     */
    int Player::CountCards()
    {
        return _hand.size();
    }

    /**
     * @brief Retrieves the player's name.
     *
     * @return string Player's name.
     */
    string Player::GetName()
    {
        return _name;
    }

    /**
     * @brief Calculates the player's score, adjusting for Aces as needed to keep the score below or equal to 21.
     *
     * @return int Player's calculated score.
     */
    int Player::calculateScore()
    {
        int score = 0;
        int numberOfAces = 0;

        for (Card card : _hand)
        {
            int val = card.GetValue();
            if (val == 11)
            {
                numberOfAces++;
            }
            score += val;
        }

        if (score > 21)
        {
            while (true)
            {
                if (numberOfAces > 0)
                {
                    score = score - 10;
                    numberOfAces--;
                }
                else
                    break;
            }
        }

        return score;
    }
}