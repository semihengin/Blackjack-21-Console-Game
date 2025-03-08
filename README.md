# Blackjack 21 Game

This project is a console-based implementation of the classic Blackjack game, developed in the C programming language. It serves as an educational exercise to enhance proficiency in C and to understand fundamental game development concepts. This was one of my first programming experiences and helped me grasp basic programming logic and game mechanics.

**Note:**

This project was developed in **October 2020 during my first year of university** as one of my earliest programming experiences, helping me understand C programming and game development fundamentals.

## Game Overview

Blackjack, also known as 21, is a popular card game where the objective is to have a hand value closer to 21 than the dealer's hand without exceeding 21. The game is typically played with one or more decks of standard playing cards.

## Game Rules

- **Card Values**:
  - Number cards (2-10): Face value.
  - Face cards (Jack, Queen, King): 10 points each.
  - Ace: Either 1 or 11 points, depending on which value benefits the hand more.

- **Gameplay**:
  1. Both the player and the dealer are dealt two cards initially.
  2. The player's cards are typically dealt face up, while the dealer has one card face up and one face down (the "hole" card).
  3. The player can choose to:
     - **Hit**: Draw additional cards to increase the hand's value.
     - **Stand**: Retain the current hand value and end their turn.
     - **Double Down**: Double the initial bet and receive exactly one more card.
     - **Split**: If the first two cards have the same value, split them into two separate hands (Note: Implementation of this feature may vary).
  4. After the player's turn, the dealer reveals the hole card and draws additional cards until reaching a hand value of at least 17.
  5. The outcomes are determined as follows:
     - If the player's hand exceeds 21, it's a bust, and the player loses.
     - If the dealer busts, the player wins.
     - If neither busts, the hand closest to 21 without exceeding wins.
     - A tie results in a "push," where the player's bet is returned.

## Features

- **Console-Based Interface**: Interactive text-based gameplay suitable for terminal execution.
- **Randomized Card Dealing**: Ensures a fair and unpredictable game experience.
- **Basic Game Mechanics**: Includes hitting, standing, and dealer logic.

## Requirements

- A C compiler (e.g., GCC)
- Compatible operating system (Windows, macOS, Linux)

## Project Structure

- `blackjack.c`: Main source code file containing the game logic.
- `README.md`: This documentation file.

## Future Enhancements

- Implementing additional features like splitting pairs, doubling down, and insurance bets.
- Developing a graphical user interface (GUI) for enhanced user experience.
- Adding support for multiple players.

**Note**: This project was developed in December 2021 as one of my first programming experiences, helping me understand C programming and game development fundamentals.
