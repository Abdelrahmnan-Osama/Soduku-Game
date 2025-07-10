# Sudoku Game (C++ Console Project)

A modular, object-oriented Sudoku puzzle game and solver implemented in C++. This project demonstrates clean architecture, STL usage, and clear separation of concerns between board logic, solving, user interaction, and optional features.

---

## Features

- Console-based 9×9 Sudoku board
- Load and save puzzles from/to files
- Enter and validate user moves
- Automatically solve puzzles using backtracking
- Puzzle generation with unique solutions

---

## Project Structure

```bash
SUDOKU-GAME/
│
├── include/
│   ├── SudokuBoard.hpp
│   ├── SudokuGame.hpp
│   ├── SudokuGenerator.hpp
│   └── SudokuSolver.hpp
├── src/
│   ├── SudokuBoard.cpp
│   ├── SudokuGame.cpp
│   ├── SudokuGenerator.cpp
│   └── SudokuSolver.cpp
├── data/
│   └── puzzle_input.txt
├── main.cpp
├── sudoku_game.exe
└── README.md
```

---

## Class Responsibilities

- **SudokuBoard**:
  - Manages the 9×9 grid
  - Handles validation and board display
  - Loads and saves puzzles to/from files

- **SudokuSolver**:
  - Solves puzzles using backtracking

- **SudokuGame**:
  - Manages the user interface and game flow
  - Coordinates between board and solver

- **SudokuGenerator**:
  - Creates complete puzzles and removes values to form playable boards

---

## How to Build

If you're using g++ (Windows with MinGW/Git Bash or Linux/macOS/WSL):

```bash
g++ main.cpp src/*.cpp -o sudoku_game.exe
```

---

## How to Run

```bash
# Linux/macOS/WSL (in terminal):
./sudoku_game

# Windows (in Command Prompt/PowerShell):
sudoku_game.exe
```

---

## Learning Objectives

- Apply object-oriented programming (OOP) principles in C++
- Use STL containers and algorithms (e.g., `vector`, `iota`, `shuffle`)
- Implement a modular and maintainable architecture
- Separate game logic from input/output (UI)
- Perform input validation and file I/O
- Practice building multi-file C++ projects

---

## Author

**Abdelrahman Osama**  
Bachelor of Computer and Systems Engineering

---

## License

This project is licensed under the **MIT License**.

You are free to use, modify, and distribute it under the terms of the license.

