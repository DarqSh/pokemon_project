# README

## Overview

This terminal-based application provides Pokedex and inventory management functionality, allowing users to view and manage their collection of Pokemon. It utilizes the `ncurses` library to create a navigable user interface with various options and features.

## Features

### Main Menu
- **Pokedex**: Access a comprehensive list of Pokemon with details such as type, avgWeight, avgHeight, and evolution tree.
- **Inventory**: Manage your Pokemon collection with attributes including HP, CP, defence, base attack, and special attack.
- **Close**: Exit the application.
<img width="1066" alt="main_menu" src="https://github.com/user-attachments/assets/24bc06e3-5d77-4842-a09d-42023d263d07">


### Pokedex
- Navigate between Pokemon using the arrow keys.
- Press **`B`** to go back.
<img width="1066" alt="pokedex" src="https://github.com/user-attachments/assets/4754c442-fbb0-4619-a140-ad0d3d27ee48">


### Inventory
- Navigate between Pokemon using the arrow keys.
- Press **`D`** to delete a highlighted Pokemon.
- Press **`A`** to add a new Pokemon.
- Press **`B`** to go back.
<img width="1066" alt="inventory" src="https://github.com/user-attachments/assets/99798db2-7a8f-4421-958d-44640e81554b">

### Delete Option in Inventory
- A confirmation window pops up.
- Press **`Y`** to confirm or **`N`** to cancel.
<img width="1066" alt="inventory_delete" src="https://github.com/user-attachments/assets/76b1f3e5-a3a5-44f3-ad2d-6dbc7bd8379c">


### Add Option in Inventory
- Opens a table similar to the Pokedex, displaying only the name and type of the Pokemon.
- After selecting a Pokemon, press **Enter** to proceed.
<img width="1066" alt="inventory_add_name_type" src="https://github.com/user-attachments/assets/c32ff859-71fd-49c3-b799-e7e2420e61fa">

- Enter weight and height within bounds: more than 0.7\*avgWeight/Height and less than 1.3\*avgWeight/Height based on Pokedex info.
<img width="1066" alt="inventory_add_weight" src="https://github.com/user-attachments/assets/a1acbd2f-7489-48c4-9e8e-e4678f331afe">
<img width="1066" alt="inventory_add_height" src="https://github.com/user-attachments/assets/28d76b54-eabb-460e-91a7-5d8fef7b90e6">

- Enter HP, CP, and defense as any 2-to-4-digit integer.
<img width="1066" alt="inventory_add_HP" src="https://github.com/user-attachments/assets/406275bd-799a-495f-8cd1-e3d59ff1b128">

- Choose base and special attacks, with a 20% boost for matching types.
<img width="1066" alt="inventory_add_base_atk" src="https://github.com/user-attachments/assets/f0b4acc0-3a24-438f-84ae-c6a11e72f77c">
<img width="1066" alt="inventory_add_spec_atk" src="https://github.com/user-attachments/assets/adb403f8-db0c-438c-bcd9-5b01a881b6df">

- The Pokemon is added to the inventory.
<img width="1066" alt="inventory_added_pokemon" src="https://github.com/user-attachments/assets/c637c05b-a700-44fa-ab39-cea23e95c1ac">

- Upon closing the inventory, it is saved to an external file for future sessions.

## Requirements

- **C++20**: Requires a compiler supporting the C++20 standard.
- **ncurses**: Used for the text-based user interface.

## Installing `ncurses`

#### For `Debian/Ubuntu`:

```
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev
```

#### For `macOS (using Homebrew)`:
```
brew install ncurses
```

## Compilation

Compiled file for `MacOS` is already provided in the repository. However, if you'd like to repreduce the compilation yourself, please use the following command:
```
g++ -fdiagnostics-color=always -g -std=c++20 -pedantic-errors -ggdb -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -lncurses -o <output_name> main.cpp
```


## Color support
The program uses colours in the terminal, which may not be supported on all systems. To check for terminal colour support, a program named 'colours' is included in the repository. It displays numbers from 0 to 255, each of them should have its' own colour.
