# Santorini - CS230 Project 1

This is a program of the game Santorini implemented using the C language. The game consists of a gameboard and the two players, the computer and the real-life player playing against the computer. The player and the computer both place their placeholders on the board, and move around the board collecting points. As the player moves around, the tiles are increased in an octagonal manner around the player to the end of the board. Similarly, as the computer moves, the tiles are decreased in an octangonal manner around the computer to the end of the board. The player collects points by getting tiles increased to 4, whereas the computer collects points by getting tiles decreased to 0.  First to reach 10 points wins. The AI playing against the player attempts to find the best possible move based on the adjacent spaces by calculating the most amount of deductions. Upon simulating each outcome, it chooses the best move and enacts it.

My implementation fulfils the requirements of the project by:

-Implementing a two dimensional array that serves as the gameboard and is updated each turn, player and computer respectively.

-Takes in a "row column" input to ease playing experience, as well as showing the player the amount of points he/she has earned as well as the points the computer has earned. At the end of the game, once either the player wins or the computer wins, the game immediately lets the player know by displaying a message, then closing the program afterwards.

-The computer functions on an AI that searches for the best possible move by checking and simulating each possible move and the most possible deductions made by each move, then choosing the best move to do in the game.

-Arrays are passed into arguments from the main in functions such as updateGame() and gameStart().

-Iteration is used to traverse the gameboard in order to print it and also to simulate the AI moves as well as updating the board by increasing tiles and decreasing them for the plaer and computer respectively.

-No disallowed C constructs are used in this project.

-Algorithms such as updateBoard() are made efficiently to suit the player's moves and the computer's moves, and doing all the iteration in one function, rather than being split across several functions.

-There are no global variables used in this project.

-Variable naming adequetely portrays what the function or variable is used for, such as gamePrint() which prints the gameboard. 

-Various comments are written for each function, outlining what the function does.

-The standard "tab" spacing is used when coding within a function. Curly braces are used around a function to indicate the code within it.


https://youtu.be/0CHoAKjWVGs
