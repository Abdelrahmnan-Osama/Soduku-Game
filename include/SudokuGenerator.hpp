#if !defined(GENERATOR)
#define GENERATOR

#include "SudokuSolver.hpp"

class SudokuGenerator
{
private:
    SudokuBoard board;

    void createSolvedBoard();
    int countNumberOfSolutions(int &count);
    bool hasUniqueSolution();
    void removeCells(int clues);
    int getNumberOfClues(int difficultyLevel);

public:
    SudokuBoard generateBoard(int difficultyLevel);
};

#endif // GENERATOR
