#pragma once
#include "Board.h"

class Game
{
public:
    static const char* const DEFAULT_FEN;
private:
    Board board;
    bool gameRunning;

private:
    void gameLoop();
    void displayBoard(const Board& board) const;
    void endGame();

public:
    Game();
    void StartGame();
};
