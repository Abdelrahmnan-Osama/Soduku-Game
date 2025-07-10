#if !defined(SOLVER)
#define SOLVER

#include "SudokuBoard.hpp"
#include <numeric>
#include <random>

extern std::random_device rd;
extern std::mt19937 rng;

class SudokuSolver
{
private:
    static bool isSolvable(SudokuBoard &board, bool shouldRansdomize);

public:
    static void solveBoard(SudokuBoard &board);
    static void fillBoard(SudokuBoard &board);
};

#endif // SOLVER
