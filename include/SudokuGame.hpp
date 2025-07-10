#if !defined(GAME)
#define GAME

#include "SudokuGenerator.hpp"

class SudokuGame
{
private:
    SudokuBoard board;
    SudokuGenerator generator;

    void readMove(int &row, int &col, int &value) const;
    void MakeMove();
    void solveAutomatically();
    void LoadFromFile();
    void saveToFile();
    int selectDifficulty() const;
    int selectOption() const;

public:
    void play();
};

#endif // GAME
