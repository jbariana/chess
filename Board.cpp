#include "Board.h"
#include <cctype>

// sets default display for the board to all x's
Board::Board()
{
    for (int row = 0; row < 8; ++row)
        for (int col = 0; col < 8; ++col)
            m_board_arr[row][col] = 'x';
}

// sets the board state based on a provided FEN string
void Board::setBoard(const std::string& FEN)
{
    int row = 0, col = 0;
    for (char c : FEN)
    {
        if (c == '/')
        {
            row++;
            col = 0;
        }
        else if (std::isdigit(c))
        {
            int emptyCount = c - '0';
            for (int i = 0; i < emptyCount && col < 8; ++i)
                m_board_arr[row][col++] = 'x';
        }
        else
        {
            if (col < 8)
                m_board_arr[row][col++] = c;
        }
        if (row >= 8) break;
    }
}

// retrieves the current state of the board as a 2D array
const char(&Board::getBoard() const)[8][8]
{
    return m_board_arr;
}
