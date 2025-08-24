#include "SudokuGenerator.hpp"

void SudokuGenerator::createSolvedBoard()
{
    SudokuSolver::fillBoard(board);
}

int SudokuGenerator::countNumberOfSolutions(int &count)
{
    // traverse all cells
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // try to fill empty cells only
            if (board.getValue(i, j) == 0)
            {
                for (int digit = 1; digit <= 9; digit++)
                {
                    if (board.isValidMove(i, j, digit))
                    {
                        board.setValue(i, j, digit);
                        countNumberOfSolutions(count);
                        board.setValue(i, j, 0); // backtrack from valid path to check other paths

                        if (count > 1)
                        {
                            return count; // early termination if case of multisolutions
                        }
                    }
                }
                return count; // no digit form 1 to 9 satify constraints for this cell (backtrack from invalid path)
            }
        }
    }

    count++; // filled all cells successfully so this is a solution
    return count;
}

bool SudokuGenerator::hasUniqueSolution()
{
    int count = 0;
    countNumberOfSolutions(count);
    return count == 1;
}

void SudokuGenerator::removeCells(int clues)
{
    int shouldBeRemoved = 81 - clues;
    int attempts = 0;
    int maxAttempts = 500;
    while (shouldBeRemoved > 0 && attempts < maxAttempts)
    {
        int row = rng() % 9;
        int col = rng() % 9;
        int valueToBeRemoved = board.getValue(row, col);

        // make sure the cell is not empty
        if (valueToBeRemoved != 0)
        {
            // start removing
            board.setValue(row, col, 0);

            // check if board still has a unique solution
            if (hasUniqueSolution())
            {
                shouldBeRemoved--; // go to remove another one
            }
            else
            {
                board.setValue(row, col, valueToBeRemoved); // backtrack if not unique
            }
        }
        attempts++;
    }
    // throw error if a unique puzzle couldn't be geenrated
    if (shouldBeRemoved > 0)
    {
        throw std::runtime_error("Sudoku Generation Error: Please try Again");
    }
}

int SudokuGenerator::getNumberOfClues(int difficultyLevel)
{
    int clues;
    switch (difficultyLevel)
    {
    case 1: // Easy
        clues = std::uniform_int_distribution(36, 49)(rng);
        break;
    case 2: // Medium
        clues = std::uniform_int_distribution(32, 35)(rng);
        break;
    case 3: // Hard
        clues = std::uniform_int_distribution(28, 31)(rng);
        break;
    case 4: // Expert
        clues = std::uniform_int_distribution(25, 27)(rng);
        break;
    }
    return clues;
}

SudokuBoard SudokuGenerator::generateBoard(int difficultyLevel)
{
    // create solved board
    createSolvedBoard();

    // generate number of clues
    int clues = getNumberOfClues(difficultyLevel);

    // remove cells based on difficulty level
    removeCells(clues);

    return board;
}
