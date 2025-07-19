#include "Game.h"
#include "Player.h"
#include <iostream>

// Default FEN string
const char* const Game::DEFAULT_FEN{ "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1" };

// creates a board object and initializes the game state
Game::Game() : board(), gameRunning(false)
{
    board.setBoard(Game::DEFAULT_FEN);
}

// Starts the game by setting the gameRunning flag to true and calling the game loop
void Game::StartGame()
{
    gameRunning = true;
    gameLoop();
}


// Displays the current state of the board in a readable format
void Game::displayBoard(const Board& board) const
{
    const auto& boardArr = board.getBoard(); // Cleaner syntax using 'auto'

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            std::cout << boardArr[row][col] << ' ';
        }
        std::cout << '\n';  // Prefer '\n' over std::endl unless flushing is needed
    }
}


// ends the game by setting the gameRunning flag to false
void Game::endGame()
{
    gameRunning = false;
}


// main game loop that continues until the gameRunning flag is false
void Game::gameLoop()
{
    while (gameRunning)
    {
        displayBoard(board);
        endGame(); 
    }
}
