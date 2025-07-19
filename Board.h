#pragma once
#include <string>

static class Board
{
private:
    char m_board_arr[8][8];

public:
    Board();
    const char(&getBoard() const)[8][8];
    void setBoard(const std::string& FEN);
};
