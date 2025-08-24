#include "SudokuBoard.hpp"

SudokuBoard::SudokuBoard()
{
    grid.resize(9, std::vector<int>(9));
}

SudokuBoard::SudokuBoard(const int (&puzzleArray)[9][9])
{
    grid.reserve(9);
    for (auto &&row : puzzleArray)
    {
        grid.emplace_back(std::begin(row), std::end(row));
    }
}

std::ifstream &operator>>(std::ifstream &ifs, SudokuBoard &board)
{
    if (!ifs.is_open())
    {
        throw std::ios_base::failure("Error: Couldn't open the file for reading!");
    }

    board.grid.clear();
    board.grid.resize(9);
    std::string line;
    int row = 0;
    while (std::getline(ifs, line))
    {
        for (auto &&ch : line)
        {
            if (isdigit(ch))
            {
                board.grid[row].emplace_back(ch - '0');
            }
            if (ch == '.')
            {
                board.grid[row].emplace_back(0);
            }
        }
        if (line != "-------------------------------------")
        {
            row++;
        }
    }
    return ifs;
}

bool SudokuBoard::isComplete() const
{
    for (auto &&row : grid)
    {
        if (std::find(row.begin(), row.end(), 0) != row.end())
        {
            return false;
        }
    }
    return true;
}

bool SudokuBoard::isValidMove(int row, int col, int value) const
{
    for (int i = 0; i < 9; i++)
    {
        // check row constraint
        if (grid[row][i] == value)
        {
            return false;
        }

        // check column constraint
        if (grid[i][col] == value)
        {
            return false;
        }

        // check box constraints
        int rowIndexOfBox = 3 * (row / 3) + (i / 3); // starting row of the box + offset
        int colIndexOfBox = 3 * (col / 3) + (i % 3); // starting col of the box + offset

        if (grid[rowIndexOfBox][colIndexOfBox] == value)
        {
            return false;
        }
    }
    return true;
}

void SudokuBoard::PlaceInBoard(int row, int col, int value)
{
    if (grid[row][col] != 0)
    {
        throw std::logic_error("Invalid Move: Cell already Occupied!");
    }
    else
    {
        if (!isValidMove(row, col, value))
        {
            throw std::logic_error("Invalid Move: digit already exists in row/col/box!");
        }
        else
        {
            grid[row][col] = value;
        }
    }
}

int SudokuBoard::getValue(int row, int col) const
{
    return grid[row][col];
}

void SudokuBoard::setValue(int row, int col, int value)
{
    grid[row][col] = value;
}

std::ostream &operator<<(std::ostream &os, const SudokuBoard &board)
{
    os << "-------------------------------------" << std::endl;

    int rowCount = 0;
    for (auto &&row : board.grid)
    {
        int cellCount = 0;
        for (auto &&cell : row)
        {
            // print cell values & . for empty cells
            if (cell == 0)
            {
                os << ". ";
            }
            else
            {
                os << cell << " ";
            }
            cellCount++;

            // put | at end of each box
            if (cellCount == 3)
            {
                os << std::setw(4) << "| ";
                cellCount = 0;
            }
        }
        os << std::endl;

        rowCount++;
        if (rowCount == 3)
        {
            os << "-------------------------------------" << std::endl;
            rowCount = 0;
        }
    }
    return os;
}

std::ofstream &operator<<(std::ofstream &ofs, const SudokuBoard &board)
{
    if (!ofs.is_open())
    {
        throw std::ios_base::failure("Error: Couldn't open the file for writing!");
    }

    ofs << "-------------------------------------" << std::endl;

    int rowCount = 0;
    for (auto &&row : board.grid)
    {
        int cellCount = 0;
        for (auto &&cell : row)
        {
            // print cell values & . for empty cells
            if (cell == 0)
            {
                ofs << ". ";
            }
            else
            {
                ofs << cell << " ";
            }
            cellCount++;

            // put | at end of each box
            if (cellCount == 3)
            {
                ofs << std::setw(4) << "| ";
                cellCount = 0;
            }
        }
        ofs << std::endl;

        rowCount++;
        if (rowCount == 3)
        {
            ofs << "-------------------------------------" << std::endl;
            rowCount = 0;
        }
    }
    return ofs;
}
