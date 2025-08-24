#include "SudokuSolver.hpp"

std::random_device rd;
std::mt19937 rng(rd());

bool SudokuSolver::isSolvable(SudokuBoard &board, bool shouldRandomize)
{
    // traverse all cells
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // try to fill empty cells only
            if (board.getValue(i, j) == 0)
            {
                // try all possible digitsG
                std::vector<int> possibleDigits(9);
                std::iota(possibleDigits.begin(), possibleDigits.end(), 1);

                // shuffle digits if solution should be random
                if (shouldRandomize)
                {
                    // initialize a random number generator
                    std::shuffle(possibleDigits.begin(), possibleDigits.end(), rng);
                }

                for (auto &&digit : possibleDigits)
                {
                    if (board.isValidMove(i, j, digit))
                    {
                        board.setValue(i, j, digit);
                        // check whether the new puzzle is solvable
                        if (isSolvable(board, shouldRandomize))
                        {
                            return true;
                        }
                        else
                        {
                            board.setValue(i, j, 0); // backtrack
                        }
                    }
                }
                return false; // no digit form 1 to 9 satify constraints for this cell
            }
        }
    }
    return true; // board complete
}

void SudokuSolver::solveBoard(SudokuBoard &board)
{
    // solve the board in deterministic manner
    if (!isSolvable(board, false))
    {
        throw std::logic_error("Error: Sudoku puzzle is unsolvable!");
    }
}

void SudokuSolver::fillBoard(SudokuBoard &board)
{
    // initiates empty board with random solution each time
    isSolvable(board, true);
}
