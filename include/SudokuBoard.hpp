#if !defined(BOARD)
#define BOARD

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

class SudokuBoard
{
private:
    std::vector<std::vector<int>> grid;

public:
    SudokuBoard();
    SudokuBoard(const int (&puzzleArray)[9][9]);

    bool isComplete() const;
    bool isValidMove(int row, int col, int value) const;
    void PlaceInBoard(int row, int col, int value);

    int getValue(int row, int col) const;
    void setValue(int row, int col, int value);

    friend std::ifstream &operator>>(std::ifstream &file, SudokuBoard &board);
    friend std::ostream &operator<<(std::ostream &os, const SudokuBoard &board);
    friend std::ofstream &operator<<(std::ofstream &ofs, const SudokuBoard &board);
};

#endif // BOARD
