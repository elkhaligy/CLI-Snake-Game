# Simple Snake Game

This is a simple implementation of the classic Snake game using C++. The game features a snake that moves around the board, collecting fruits to grow in length while avoiding collisions with itself and the walls.

## Project Structure

- `Simple snake game.cpp`: The main C++ source file containing the game logic and functionality.

## Dependencies

This project requires the following libraries:

- `iostream`
- `conio.h`
- `windows.h`

These libraries are typically included with most C++ development environments, such as Visual Studio.

## How to Play

1. **Compile the Code**: Use a C++ compiler to compile the `Simple snake game.cpp` file.

    ```sh
    g++ -o snake_game "Simple snake game.cpp"
    ```

2. **Run the Game**: Execute the compiled file to start the game.

    ```sh
    ./snake_game
    ```

3. **Game Controls**:
    - `W`: Move Up
    - `A`: Move Left
    - `S`: Move Down
    - `D`: Move Right
    - `X`: Exit the Game

## Game Rules

- The snake starts in the middle of the board.
- Use the keyboard controls to move the snake in the desired direction.
- The goal is to eat the fruits (`F`) that appear on the board.
- Each time the snake eats a fruit, its length increases by one segment, and the score increases by 10 points.
- The game ends if the snake collides with itself.

## Function Descriptions

- `setup()`: Initializes the game by setting the starting position of the snake, placing the first fruit, and resetting the score.
- `draw()`: Draws the game board, snake, and fruit on the console screen.
- `input()`: Handles user input to control the direction of the snake.
- `logic()`: Contains the game logic for moving the snake, checking for collisions, and updating the game state.
- `main()`: The main function that sets up the game loop, calling the draw, input, and logic functions.

## Game Board

The game board is a 20x10 grid surrounded by walls (`#`). The snake's head is represented by `O`, the snake's body by `o`, and the fruit by `F`.

```
######################
#                    #
#                    #
#                    #
#                    #
#                    #
#                    #
#                    #
#                    #
#                    #
######################
```
