#include <stdio.h>
char box[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};//character array to display grid number of 3x3

int check()//function to check for win condition
{
    if (box[0] == box[1] && box[1] == box[2])//if first row is equal
        return 1;
    else if (box[3] == box[4] && box[4] == box[5])//if second row is equal
        return 1;
    else if (box[6] == box[7] && box[7] == box[8])//if 3rd row is equal
        return 1;
    else if (box[0] == box[3] && box[3] == box[6])//if 1st column is equal
        return 1;
    else if (box[1] == box[4] && box[4] == box[7])//if 2nd column is equal
        return 1;
    else if (box[2] == box[5] && box[5] == box[8])//if 3rd column is equal
        return 1;
    else if (box[0] == box[4] && box[4] == box[8])//if left diagonal is equal
        return 1;
    else if (box[2] == box[4] && box[4] == box[6])//if right diagonal is equal
        return 1;
    else if (box[0] != '1' && box[1] != '2' && box[2] != '3' && box[3] != '4' && box[4] != '5' && box[5] != '6' && box[6] != '7' && box[7] != '8' && box[8] != '9')//if draw
        return 0;
    else//in other cases
        return -1;
}

void tttboard()//function to display the tictactoe board
{
    printf("\n\t   Tic Tac Toe\n");
    printf("\t   ~~~~~~~~~~~\n");
    printf("\n   Player 1 (X)  -  Player 2 (O)\n");
    printf("   =============================\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", box[0], box[1], box[2]);//displays first row
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", box[3], box[4], box[5]);//displays second row
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", box[6], box[7], box[8]);//displays third row
    printf("\t     |     |     \n");
    printf("   =============================\n");
}

int main()
{
    int player = 1, i, choice;
    char input;
    do
    {
        tttboard();
        player = (player % 2) ? 1 : 2;//to check turn of which player
        printf("\n   Player %d, enter grid number of your choice:  ", player);
        scanf("%d", &choice);
        printf("\n-------------------------------------------------\n");
        input = (player == 1) ? 'X' : 'O';
        //checks if user input number and grid number matches
        if (choice == 1 && box[0] == '1')//swaps the grid number 1 with 'X' or 'O' if user enters 1 as input
            box[0] = input;
        else if (choice == 2 && box[1] == '2')//swaps the grid number 2 with 'X' or 'O' if user enters 2 as input
            box[1] = input;
        else if (choice == 3 && box[2] == '3')//swaps the grid number 3 with 'X' or 'O' if user enters 3 as input
            box[2] = input;
        else if (choice == 4 && box[3] == '4')//swaps the grid number 4 with 'X' or 'O' if user enters 4 as input
            box[3] = input;
        else if (choice == 5 && box[4] == '5')//swaps the grid number 5 with 'X' or 'O' if user enters 5 as input
            box[4] = input;
        else if (choice == 6 && box[5] == '6')//swaps the grid number 6 with 'X' or 'O' if user enters 6 as input
            box[5] = input;
        else if (choice == 7 && box[6] == '7')//swaps the grid number 7 with 'X' or 'O' if user enters 7 as input
            box[6] = input;
        else if (choice == 8 && box[7] == '8')//swaps the grid number 8 with 'X' or 'O' if user enters 8 as input
            box[7] = input;
        else if (choice == 9 && box[8] == '9')//swaps the grid number 9 with 'X' or 'O' if user enters 9 as input
            box[8] = input;
        else//if user enters wrong grid number
        {
            printf("\n\n   INVALID MOVE: RE-ENTER GRID NUMBER\n\n");
            player--;//decrements to same player 
        }
        i = check();//return value of check() function
        player++;//increments i to next player
    }
    while (i == -1);//exits if i=0 or i=1
    tttboard();
    if (i == 1)
        printf("\n   ==>PLAYER %d WON \n", --player);
    else
        printf("\n   ==>GAME DRAWN\n");
    return 0;
}