# README

## Overview

This terminal-based application provides Pokedex and inventory management functionality, allowing users to view and manage their collection of Pokemon. It utilizes the `ncurses` library to create a navigable user interface with various options and features.

## Features

### Main Menu
- **Pokedex**: Access a comprehensive list of Pokemon with details such as type, weight, height, and evolution tree.
- **Inventory**: Manage your Pokemon collection with attributes including HP, CP, defense, base attack, and special attack.
- **Close**: Exit the application.

### Pokedex
- Opens the Pokedex.
- Navigate between Pokemon using the arrow keys.
- Press **`B`** to go back.

### Inventory
- Opens the inventory.
- Navigate between Pokemon using the arrow keys.
- Press **`D`** to delete a highlighted Pokemon.
- Press **`A`** to add a new Pokemon.
- Press **`B`** to go back.

### Delete Option in Inventory
- A confirmation window pops up.
- Press **`Y`** to confirm or **`N`** to cancel.

### Add Option in Inventory
- Opens a table similar to the Pokedex, displaying only the name and type of the Pokemon.
- After selecting a Pokemon, press **Enter** to proceed.
- Enter weight and height within bounds: more than 0.7\*avgWeight/Height and less than 1.3\*avgWeight/Height based on Pokedex info.
- Enter HP, CP, and defense as any 4-digit integer.
- Choose base and special attacks, with a 20% boost for matching types.
- The Pokemon is added to the inventory.
- Upon closing the inventory, it is saved to an external file for future sessions.

## Requirements

- **C++20**: Requires a compiler supporting the C++20 standard.
- **ncurses**: Used for the text-based user interface.

## Installing `ncurses`

#### For Debian/Ubuntu:

```
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev
```

#### For macOS (using Homebrew):
```
brew install ncurses
```

## Compilation

Compiled file is already provided in the repository. However, if you'd like to repreduce the compilation yourself, please use the following command:
```
g++ -fdiagnostics-color=always -g -std=c++20 -pedantic-errors -ggdb -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -lncurses -o <output_name> <source_file>
```


## Color support
The program uses colours in the terminal, which may not be supported on all systems. To check for terminal colour support, a program named 'colours' is included in the repository. It displays numbers from 0 to 255, each of them should have its' own colour.
