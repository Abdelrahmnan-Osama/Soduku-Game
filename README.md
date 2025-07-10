==================================================================
                    SUDOKU GAME (C++ Console Project)
==================================================================

A modular, object-oriented Sudoku puzzle game and solver implemented in C++. 
It demonstrates clean architecture, STL usage, and separation of concerns between 
board logic, solving, user interaction, and optional advanced features.

------------------------------------------------------------------
FEATURES
------------------------------------------------------------------

- Console-based 9×9 Sudoku board
- Load and save puzzles from/to files
- Enter and validate user moves
- Automatic puzzle solving using backtracking
- (Optional) Puzzle generation with unique solutions
- (Optional) Advanced solving techniques (e.g., naked pairs)

------------------------------------------------------------------
PROJECT STRUCTURE
------------------------------------------------------------------

SUDOKU-GAME/
│
├── include/               --> Header files
│   ├── SudokuBoard.hpp
│   ├── SudokuGame.hpp
│   ├── SudokuGenerator.hpp
│   └── SudokuSolver.hpp
│
├── src/                   --> Implementation files
│   ├── SudokuBoard.cpp
│   ├── SudokuGame.cpp
│   ├── SudokuGenerator.cpp
│   └── SudokuSolver.cpp
│
├── data/
|   ├── puzzle_input.txt   --> Input/output puzzle files (optional)
│     
├── main.cpp               --> Entry point
├── sudoku_game.exe               --> Compiled executable (Windows)
└── README.txt             --> This file

------------------------------------------------------------------
CLASS RESPONSIBILITIES
------------------------------------------------------------------

- SudokuBoard:
  - Manages the 9×9 grid
  - Handles validation and board display
  - Loads and saves puzzles

- SudokuSolver:
  - Solves puzzles using backtracking

- SudokuGame:
  - Manages the user interface and game flow

- SudokuGenerator:
  - Generates full puzzles and removes numbers to create challenges

------------------------------------------------------------------
HOW TO BUILD
------------------------------------------------------------------

If you're using g++ (on Windows via MinGW, Git Bash, or WSL):

    g++ main.cpp src/*.cpp -o sudoku_game.exe

Then run:

    ./sudoku_game    (Linux/Mac/WSL)
    sudoku_game.exe  (Windows)

------------------------------------------------------------------
PUZZLE FILE FORMAT
------------------------------------------------------------------

A 9x9 text file with digits 0–9 (0 = empty cell), one line per row.

Example:

-------------------------------------
5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .
-------------------------------------
8 . . | . 6 . | . . 3
4 . . | 8 . 3 | . . 1
7 . . | . 2 . | . . 6
-------------------------------------
. 6 . | . . . | 2 8 .
. . . | 4 1 9 | . . 5
. . . | . 8 . | . 7 9
-------------------------------------

------------------------------------------------------------------
SAMPLE GAME FLOW
------------------------------------------------------------------

1) Program starts, prints current board
2) User is shown options:
   1. Enter a move
   2. Solve automatically
   3. Load puzzle from file
   4. Save puzzle to file
   5. Exit

Example interaction:

  Choice: 1
  Enter row (1–9), column (1–9), and value (1–9): 1 3 4
  Move accepted!

  Choice: 2
  Puzzle solved!

------------------------------------------------------------------
LEARNING OBJECTIVES
------------------------------------------------------------------

- Apply OOP principles and STL in C++
- Implement modular design
- Use vector, iota, shuffle, and file I/O
- Separate game logic from user interface

------------------------------------------------------------------
AUTHOR
------------------------------------------------------------------

Abdelrahman Osama  
Bachelor of Computer and Systems Engineering

------------------------------------------------------------------
LICENSE
------------------------------------------------------------------

MIT License — Free to use, modify, and share
