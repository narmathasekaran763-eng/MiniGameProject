# Mini Game Project — Tic-Tac-Toe

A console-based Tic-Tac-Toe game built with C++.

The application provides an interactive two-player interface where players take turns marking a 3 × 3 board. It demonstrates fundamental programming concepts, including arrays, loops, conditional logic, input validation, and game-state management.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Technology Stack](#technology-stack)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Game Logic](#game-logic)
- [Testing](#testing)
- [Limitations](#limitations)
- [Future Enhancements](#future-enhancements)

## Overview

Mini Game Project — Tic-Tac-Toe is a command-line game designed to provide an interactive gaming experience while demonstrating core C++ programming concepts.

The game uses a fixed-size `std::array` to represent the board and a class to organize the game logic. Players alternate between `X` and `O`, selecting available positions until a player wins or the board is full.

The application supports win detection, draw detection, input validation, dynamic board updates, and replay functionality.

## Features

| Feature | Description |
|---|---|
| Interactive game board | Display the 3 × 3 board and update it after every move. |
| Two-player gameplay | Allow two players to alternate between `X` and `O`. |
| Input validation | Reject invalid positions and non-numeric input. |
| Move validation | Prevent players from selecting occupied positions. |
| Win detection | Check rows, columns, and diagonals for a winning combination. |
| Draw detection | Identify when the board is full without a winner. |
| Replay option | Allow players to start another round without restarting the program. |

## Technology Stack

- **Language:** C++
- **Data structures:** `std::array`
- **Programming concepts:** Classes, functions, loops, conditional statements, and input validation
- **Development environment:** Ubuntu Linux and Visual Studio Code
- **Compiler:** GNU C++ (`g++`)

## Project Structure

```text
MiniGameProject/
├── main.cpp       # Game implementation
├── README.md      # Project documentation
└── .gitignore     # Files excluded from version control
```

The compiled executable is generated during compilation and is not required as a source file.

## Getting Started

### Prerequisites

- Ubuntu Linux or a compatible environment
- GNU C++ compiler with C++17 support
- Terminal access

Install the compiler on Ubuntu if necessary:

```bash
sudo apt update
sudo apt install g++
```

### Build

Clone the repository after it has been published:

```bash
git clone <repository-url>
cd MiniGameProject
```

Compile the application:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o MiniGameProject
```

### Run

```bash
./MiniGameProject
```

## Usage

After launching the application, the game displays a numbered 3 × 3 board. Players select positions by entering numbers from `1` to `9`.

| Position | Board location |
|---|---|
| `1`, `