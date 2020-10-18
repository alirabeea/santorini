#include <stdio.h>

void gameReset(int gameBoard[6][6]){//resets the gameboard
    int i;
    int j;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            gameBoard[i][j] = 2;
        }
    }
}

int checkPoints(int gameBoard[6][6], int playing){//checks the current points for the player and the computer.
    int i;
    int j;
    int playerPoints = 0;
    int compPoints = 0;

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(gameBoard[i][j] == 0){
                compPoints++;
            }
            if(gameBoard[i][j] == 4){
                playerPoints++;
            }
        }
    }
    
    if(playing == 1){
        return playerPoints;
    }
    if(playing == 0){
        return compPoints;
    }

    return 0;
}

void gamePrint(int gameBoard[6][6]){//prints the gameboard
    int i;
    int j;
    for(i=0;i<7;i++){
        if(i==0){
            printf("  ");
        }
        else{
            printf("%i ",i);
        }
    }
    printf("\n");
    for(i=0;i<6;i++){
        for(j=0;j<7;j++){
            if(j==0){
                printf("%i ",i+1);
            }
            else{
                if(gameBoard[i][j-1] == 7){
                    printf("P ");
                }
                else if(gameBoard[i][j-1] == 8){
                    printf("A ");
                }
                else{
                    printf("%i ",gameBoard[i][j-1]);
                }
            }
        }
        printf("\n");
    }
    printf("Player Points: %i , Computer Points: %i\n", checkPoints(gameBoard,1),checkPoints(gameBoard,0));
}

void gameStart(int p1,int p2, int compPlace[2], int gameBoard[6][6]){//places the player and the computer
    gameBoard[p1][p2] = 7;
    //7 is a placeholder for P.
    //8 is a placeholder for A.
    if(p2+1 > 5){
        gameBoard[p1][p2-1] = 8;
        compPlace[0] = p1;
        compPlace[1] = p2-1;
    }
    else{
        gameBoard[p1][p2+1] = 8;
        compPlace[0] = p1;
        compPlace[1] = p2+1;
    }
}

void updateBoard(int row, int col, int playing, int gameBoard[6][6]){
    //updates the board either adding values if the player is playing or deducts values if the computer is playing
    int i;

    for(i = 1;i<6;i++){//updates above values
        if(playing == 1){
            if(row-i>-1){
                if(gameBoard[row-i][col] == 8){
                    break;
                }
                else{
                    if(gameBoard[row-i][col]+1 <= 4){
                        gameBoard[row-i][col]++;
                    } 
                }
            }
            else{
                break;
            }
        }
        else{
            if(row-i>-1){
                if(gameBoard[row-i][col] == 7){
                    break;
                }
                else{
                    if(gameBoard[row-i][col]-1 >= 0){
                        gameBoard[row-i][col]--;
                    }       
                }
            }
            else{
                break;
            }
        }
    }
    for(i = 1;i<6;i++){//updates below values
        if(playing == 1){
            if(row+i<6){
                if(gameBoard[row+i][col] == 8){
                    break;
                }
                else{
                    if(gameBoard[row+i][col]+1 <= 4){
                        gameBoard[row+i][col]++;
                    }
                }
            }
            else{
                break;
            }
        }
        else{
            if(row+i<6){
                if(gameBoard[row+i][col] == 7){
                    break;
                }
                else{
                    if(gameBoard[row+i][col]-1 >= 0){
                        gameBoard[row+i][col]--;
                    }   
                }
            }
            else{
                break;
            }
        }
    }
    for(i = 1;i<6;i++){//updates right values
        if(playing == 1){
            if(col+i<6){
                if(gameBoard[row][col+i] == 8){
                    break;
                }
                else{
                    if(gameBoard[row][col+i]+1 <= 4){
                        gameBoard[row][col+i]++;
                    } 
                }
            }
            else{
                break;
            }
        }
        else{
            if(col+i<6){
                if(gameBoard[row][col+i] == 7){
                    break;
                }
                else{
                    if(gameBoard[row][col+i]-1 >= 0){
                        gameBoard[row][col+i]--; 
                    }  
                }
            }
            else{
                break;
            }
        }
    }
    for(i = 1;i<6;i++){//updates left values
        if(playing == 1){
            if(col-i>-1){
                if(gameBoard[row][col-i] == 8){
                    break;
                }
                else{
                    if(gameBoard[row][col-i]+1 <= 4){
                        gameBoard[row][col-i]++; 
                    } 
                }
            }
            else{
                break;
            }
        }
        else{
            if(col-i>-1){
                if(gameBoard[row][col-i] == 7){
                    break;
                }
                else{
                    if(gameBoard[row][col-i]-1 >= 0){
                        gameBoard[row][col-i]--; 
                    }  
                }
            }
            else{
                break;
            }
        }
    }
    for(i = 1;i<6;i++){//updates upper-right values
        if(playing == 1){
            if(row-i>-1 && col+i <6){
                if(gameBoard[row-i][col+i] == 8){
                    break;
                }
                else{
                    if(gameBoard[row-i][col+i]+1 <= 4){
                        gameBoard[row-i][col+i]++; 
                    }  
                }
            }
            else{
                break;
            }
        }
        else{
            if(row-i>-1 && col+i<6){
                if(gameBoard[row-i][col+i] == 7){
                    break;
                }
                else{
                    if(gameBoard[row-i][col+i]-1 >= 0){
                        gameBoard[row-i][col+i]--;
                    } 
                }
            }
            else{
                break;
            }
        }
    }
    for(i = 1;i<6;i++){//updates lower-left values
        if(playing == 1){
            if(row+i<6 && col-i>-1){
                if(gameBoard[row+i][col-i] == 8){
                    break;
                }
                else{
                    if(gameBoard[row+i][col-i]+1 <= 4){
                        gameBoard[row+i][col-i]++; 
                    } 
                }
            }
            else{
                break;
            }
        }
        else{
            if(row+i<6 && col-i>-1){
                if(gameBoard[row+i][col-i] == 7){
                    break;
                }
                else{
                    if(gameBoard[row+i][col-i]-1 >= 0){
                        gameBoard[row+i][col-i]--; 
                    } 
                }
            }
            else{
                break;
            }
        }
    }
    for(i = 1;i<6;i++){//updates upper-left values
        if(playing == 1){
            if(row-i>-1 && col-i>-1){
                if(gameBoard[row-i][col-i] == 8){
                    break;
                }
                else{
                    if(gameBoard[row-i][col-i]+1 <= 4){
                        gameBoard[row-i][col-i]++; 
                    } 
                }
            }
            else{
                break;
            }
        }
        else{
            if(row-i>-1 && col-i>-1){
                if(gameBoard[row-i][col-i] == 7){
                    break;
                }
                else{
                    if(gameBoard[row-i][col-i]-1 >= 0){
                        gameBoard[row-i][col-i]--; 
                    } 
                }
            }
            else{
                break;
            }
        }
    }
    for(i = 1;i<6;i++){//updates lower-right values
        if(playing == 1){
            if(row+i<6 && col+i<6){
                if(gameBoard[row+i][col+i] == 8){
                    break;
                }
                else{
                    if(gameBoard[row+i][col+i]+1 <= 4){
                        gameBoard[row+i][col+i]++; 
                    }  
                }
            }
            else{
                break;
            }
        }
        else{
            if(row+i<6 && col+i<6){
                if(gameBoard[row+i][col+i] == 7){
                    break;
                }
                else{
                    if(gameBoard[row+i][col+i]-1 >= 0){
                        gameBoard[row+i][col+i]--; 
                    }
                }
            }
            else{
                break;
            }
        }
    }
}

int checkCompMoves(int row, int col, int gameBoard[6][6]){//checks for the best move the computer can make
    int i;
    int count = 0;
    for(i = 1;i<6;i++){//checks above values
        if(row-i>-1){
            if(gameBoard[row-i][col] == 7){
                break;
            }
            else{
                if(gameBoard[row-i][col]-1 >= 0){
                    count++;
                }       
            }
        }
        else{
            break;
        }
        
    }
    for(i = 1;i<6;i++){//checks below values
        if(row+i<6){
            if(gameBoard[row+i][col] == 7){
                break;
            }
            else{
                if(gameBoard[row+i][col]-1 >= 0){
                    count++;
                }   
            }
        }
        else{
            break;
        }
    }
    for(i = 1;i<6;i++){//checks right values
        if(col+i<6){
            if(gameBoard[row][col+i] == 7){
                break;
            }
            else{
                if(gameBoard[row][col+i]-1 >= 0){
                    count++; 
                }  
            }
        }
        else{
            break;
        }
    }
    for(i = 1;i<6;i++){//checks left values
        if(col-i>-1){
            if(gameBoard[row][col-i] == 7){
                break;
            }
            else{
                if(gameBoard[row][col-i]-1 >= 0){
                    count++; 
                }  
            }
        }
        else{
            break;
        }
    }
    for(i = 1;i<6;i++){//checks upper-right values
        if(col+i<6){
            if(gameBoard[row-i][col+i] == 7){
                break;
            }
            else{
                if(gameBoard[row-i][col+i]-1 >= 0){
                    count++;
                } 
            }
        }
        else{
            break;
        }
    }
    for(i = 1;i<6;i++){//checks lower-left values
        if(row+i<6 && col-i>-1){
            if(gameBoard[row+i][col-i] == 7){
                break;
            }
            else{
                if(gameBoard[row+i][col-i]-1 >= 0){
                    count++; 
                } 
            }
        }
        else{
            break;
        }
    }
    for(i = 1;i<6;i++){//checks upper-left values
        if(row-i>-1 && col-i>-1){
            if(gameBoard[row-i][col-i] == 7){
                break;
            }
            else{
                if(gameBoard[row-i][col-i]-1 >= 0){
                    count++; 
                } 
            }
        }
        else{
            break;
        }
    
    }
    for(i = 1;i<6;i++){//checks lower-right values
        if(row+i<6 && col+i<6){
            if(gameBoard[row+i][col+i] == 7){
                break;
            }
            else{
                if(gameBoard[row+i][col+i]-1 >= 0){
                    count++;
                }
            }
        }
        else{
            break;
        }
    }
    return count;
}

void compareCompMoves(int curCompRow, int curCompCol, int bestMove[2], int curRow, int curCol, int gameBoard[6][6]){
    //compares all the possible moves to choose the best possible move for the computer
    int bestMovePoints = 0;
    if (curCompRow-1 > -1){
        if(checkCompMoves(curCompRow-1, curCompCol, gameBoard)>bestMovePoints){
            if (curCompRow-1 != curRow && curCompCol != curCol){
                bestMovePoints = checkCompMoves(curCompRow-1, curCompCol, gameBoard);
                bestMove[0] = curCompRow-1;
                bestMove[1] = curCompCol;
            }
        }
    }
    if (curCompRow+1 < 6){
        if(checkCompMoves(curCompRow+1, curCompCol, gameBoard)>bestMovePoints){
            if (curCompRow+1 != curRow && curCompCol != curCol){
                bestMovePoints = checkCompMoves(curCompRow+1, curCompCol, gameBoard);
                bestMove[0] = curCompRow+1;
                bestMove[1] = curCompCol;
            }
        }
    }
    if (curCompCol+1 < 6){
        if(checkCompMoves(curCompRow, curCompCol+1, gameBoard)>bestMovePoints){
            if (curCompRow != curRow && curCompCol+1 != curCol){
                bestMovePoints = checkCompMoves(curCompRow, curCompCol+1, gameBoard);
                bestMove[0] = curCompRow;
                bestMove[1] = curCompCol+1;
            }
        }
    }
    if (curCompCol-1 > -1){
        if(checkCompMoves(curCompRow, curCompCol-1, gameBoard)>bestMovePoints){
            if (curCompRow != curRow && curCompCol-1 != curCol){
                bestMovePoints = checkCompMoves(curCompRow, curCompCol-1, gameBoard);
                bestMove[0] = curCompRow;
                bestMove[1] = curCompCol-1;
            }
        }
    }
    if (curCompCol-1 > -1 && curCompRow-1 > -1){
        if(checkCompMoves(curCompRow-1, curCompCol-1, gameBoard)>bestMovePoints){
            if (curCompRow-1 != curRow && curCompCol-1 != curCol){
                bestMovePoints = checkCompMoves(curCompRow-1, curCompCol-1, gameBoard);
                bestMove[0] = curCompRow-1;
                bestMove[1] = curCompCol-1;
            }
        }
    }
    if (curCompCol+1 < 6 && curCompRow+1 < 6){
        if(checkCompMoves(curCompRow+1, curCompCol+1, gameBoard)>bestMovePoints){
            if (curCompRow+1 != curRow && curCompCol+1 != curCol){
                bestMovePoints = checkCompMoves(curCompRow+1, curCompCol+1, gameBoard);
                bestMove[0] = curCompRow+1;
                bestMove[1] = curCompCol+1;
            }
        }
    }
    if (curCompCol+1 < 6 && curCompRow-1 > -1){
        if(checkCompMoves(curCompRow-1, curCompCol+1, gameBoard)>bestMovePoints){
            if (curCompRow-1 != curRow && curCompCol+1 != curCol){
                bestMovePoints = checkCompMoves(curCompRow-1, curCompCol+1, gameBoard);
                bestMove[0] = curCompRow-1;
                bestMove[1] = curCompCol+1;
            }
        }
    }
     if (curCompCol-1 > -1 && curCompRow+1 < 6){
        if(checkCompMoves(curCompRow+1, curCompCol-1, gameBoard)>bestMovePoints){
            if (curCompRow+1 != curRow && curCompCol-1 != curCol){
                bestMovePoints = checkCompMoves(curCompRow+1, curCompCol-1, gameBoard);
                bestMove[0] = curCompRow+1;
                bestMove[1] = curCompCol-1;
            }
        }
    }
}

int gameStatus(int gameBoard[6][6]){//checks the game's status and who is winning or losing
    int i;
    int j;
    int playerPoints = 0;
    int compPoints = 0;
    int result = 0;

    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(gameBoard[i][j] == 0){
                compPoints++;
            }
            if(gameBoard[i][j] == 4){
                playerPoints++;
            }
        }
    }
    
    if(compPoints >= 10){
        result = -1;
    }
    if(playerPoints >= 10){
        result = 1;
    }

    return result;
}

void runGame(int bestCompMove[2], int gameBoard[6][6]){
    //this function handles the entire game, including setup, mid-game, and end.
    int curRow;
    int curCol;
    int playerPlaceVal = 2;
    int compPlaceVal = 2;
    int compPlace[2];
    gamePrint(gameBoard);
    int startFlag = 0;
    while(startFlag == 0) {
        printf("Which row and column would you like to place your player? Ex: \"3 4\"\n");
        int tempRow;
        int tempCol;
        scanf("%i %i",&tempRow,&tempCol);
        if(tempRow <= 6 && tempRow >= 1 && tempCol <= 6 && tempCol >= 1){
            curRow = tempRow;
            curRow--;
            curCol = tempCol;
            curCol--;
            startFlag = 1;
        }
        else{
            printf("You must pick a row and column that is not out of bounds.\n");
        }
    }
    gameStart(curRow,curCol,compPlace, gameBoard);
    int curCompRow = compPlace[0];
    int curCompCol = compPlace[1];
    gamePrint(gameBoard);
    while(gameStatus(gameBoard) == 0){
        int row;
        int col;
        int tempRow;
        int tempCol;
        int inputFlag = 0;
        printf("It's your turn. ");
        while(inputFlag == 0) {
            printf("Which row and column would you like to move your player? Ex: \"3 4\"\n");
            scanf("%i %i",&tempRow,&tempCol);
            if(tempRow <= 6 && tempRow >= 1 && tempCol <= 6 && tempCol >= 1){
                tempRow--;
                tempCol--;
                if(((tempRow == curRow-1 || tempRow == curRow || tempRow == curRow+1) && (tempCol == curCol-1 || tempCol == curCol || tempCol == curCol+1))){
                    if(tempRow == curCompRow && tempCol == curCompCol){
                        printf("The other player is occupying this spot.\n");
                    }
                    else if(tempRow == curRow && tempCol == curCol){
                        printf("You must move to a new space.\n"); 
                    }
                    else{
                        row = tempRow;
                        col = tempCol;
                        inputFlag = 1;  
                    }
                }
                else{
                    printf("You must pick a row and column adjacent to your player.\n");
                }
            }
            else{
                printf("You must pick a row and column that is not out of bounds.\n");
            }
        }
        int tempPlayerPlaceVal = playerPlaceVal;
        playerPlaceVal = gameBoard[row][col];
        gameBoard[curRow][curCol] = tempPlayerPlaceVal;
        gameBoard[row][col] = 7;
        curRow = row;
        curCol = col;
        updateBoard(row, col, 1, gameBoard);
        gamePrint(gameBoard);
        if(gameStatus(gameBoard) == 1){
            printf("You got 10 points! You win!\n");
            break;
        }
        printf("Now it's the computer's turn.\n");
        compareCompMoves(curCompRow,curCompCol,bestCompMove, curRow, curCol, gameBoard);
        int compRow = bestCompMove[0];
        int compCol = bestCompMove[1];
        int tempCompPlaceVal = compPlaceVal;
        compPlaceVal = gameBoard[compRow][compCol];
        gameBoard[curCompRow][curCompCol] = tempCompPlaceVal;
        gameBoard[compRow][compCol] = 8;
        curCompRow = compRow;
        curCompCol = compCol;
        updateBoard(compRow, compCol,0, gameBoard);
        gamePrint(gameBoard);  
        if(gameStatus(gameBoard) == -1) {
            printf("The computer got 10 points. You lose.\n");
            break;
        }
    }
}

int main(){
    int gameBoard[6][6];//the gameboard 
    int bestCompMove[2];//an array that will be used to store the best possible move for the computer.
    gameReset(gameBoard);
    runGame(bestCompMove, gameBoard);
    return 0;
}
