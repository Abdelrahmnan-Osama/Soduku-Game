#include "../include/SudokuGame.hpp"

void SudokuGame::readMove(int &row, int &col, int &value) const
{
    std::cout << "Enter row (1-9), column (1-9), and value (1-9): ";
    std::cin >> row >> col >> value;

    if (row < 1 || row > 9)
    {
        throw std::out_of_range("Row must be between 1 and 9");
    }
    if (col < 1 || col > 9)
    {
        throw std::out_of_range("Column must be between 1 and 9");
    }
    if (value < 1 || value > 9)
    {
        throw std::out_of_range("Value must be between 1 and 9");
    }
    // map sudoku board index to array index
    row--;
    col--;
}

void SudokuGame::MakeMove()
{
    try
    {
        int row, col, value;
        readMove(row, col, value); // reads board coordiantes and maps to array coordinates
        board.PlaceInBoard(row, col, value);
        std::cout << "Move accepted!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << board;
    if (board.isComplete())
    {
        std::cout << "Great job! The Sudoku is solved!" << std::endl;
    }
}

void SudokuGame::solveAutomatically()
{
    try
    {
        SudokuSolver::solveBoard(board);
        std::cout << "Puzzle solved!" << std::endl;
        std::cout << board;
        std::cout << "Great job! The Sudoku is solved!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void SudokuGame::LoadFromFile()
{
    try
    {
        std::string filename;
        std::cout << "Enter file name to load puzzle from: ";
        std::cin >> filename;
        std::ifstream inputFile(filename);
        inputFile >> board;
        std::cout << "Board read from " << filename << "!" << std::endl;
        std::cout << board;
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void SudokuGame::saveToFile()
{
    try
    {
        std::string filename;
        std::cout << "Enter filename to save puzzle to: ";
        std::cin >> filename;
        std::ofstream outputFile(filename);
        outputFile << board;
        std::cout << "Puzzle saved to " << filename << "!" << std::endl;
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int SudokuGame::selectOption() const
{

    try
    {
        std::cout << "1) Enter a move" << std::endl;
        std::cout << "2) Solve automatically" << std::endl;
        std::cout << "3) Load puzzle from file" << std::endl;
        std::cout << "4) Save current puzzle to file" << std::endl;
        std::cout << "5) Exit" << std::endl;

        // read user input
        int option;
        std::cout << "Choice: ";
        std::cin >> option;
        if (option < 1 || option > 5)
        {
            throw std::invalid_argument("Error: Please enter a number between 1-5!");
        }

        return option;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << std::endl;
        return -1;
    }
}

int SudokuGame::selectDifficulty() const
{
    std::cout << "Choose the game difficulty level: " << std::endl;
    std::cout << "1) Easy" << std::endl;
    std::cout << "2) Medium" << std::endl;
    std::cout << "3) Hard" << std::endl;
    std::cout << "4) Expert" << std::endl;

    // read user input
    int difficulty;
    std::cout << "Choice: ";
    std::cin >> difficulty;
    if (difficulty < 1 || difficulty > 4)
    {
        throw std::invalid_argument("Error: Please enter a number between 1-4!");
    }

    return difficulty;
}

void SudokuGame::play()
{
    bool notGenerated = true;
    while (notGenerated)
    {
        try
        {
            // choose difficulty level
            int difficulty = selectDifficulty();

            // generate a board
            board = generator.generateBoard(difficulty);

            notGenerated = false;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
            std::cout << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            // handle error silently
        }
    }

    // dispaly the board
    std::cout << std::endl;
    std::cout << "Board generated successfully!" << std::endl;
    std::cout << board << std::endl;

    while (true)
    {
        // choose option
        int option = selectOption();

        // handle option 1
        if (option == 1)
        {
            MakeMove();
            std::cout << std::endl;
        }
        // handle option 2
        else if (option == 2)
        {
            solveAutomatically();
            std::cout << std::endl;
        }
        // handle option 3
        else if (option == 3)
        {
            LoadFromFile();
            std::cout << std::endl;
        }
        // handle option 4
        else if (option == 4)
        {
            saveToFile();
            std::cout << std::endl;
        }
        // handle option 5
        else if (option == 5)
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
    }
}
