#include<iostream>

// Library for TicTacToe Random Number Generator
#include <cstdlib>
#include <ctime>

using namespace std;


// TicTacToe Code by @ Mikail Khan

// Incase the square is already taken. 
bool squareTakenTTT(char ticTacToe[3][3], char input){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(ticTacToe[i][j] == input){
                return false;
             } 
        }
    }
    return true;
}

// Convert the integers into chars for the loops to work coorrectly
char convertInputToChar(int input){
    switch (input)
    {
    case 1:
        return '1';
    break;
    case 2:
        return '2';
    break;
    case 3:
        return '3';
    break;
    case 4:
        return '4';
    break;
    case 5:
        return '5';
    break;
    case 6:
        return '6';
    break;
    case 7:
        return '7';
    break;
    case 8:
        return '8';
    break;
    case 9:
        return '9';
    break;
    default:
        return '0';
    break;
    }
}


// Take user input 
// And validate if it is in between 0 and 9
char userInput(){
    int input;
    cin >> input;
    
    while (input < 0 || input > 9){
        cout << "\nWrong Input, try again: ";
        cin >> input;
    }

    return convertInputToChar(input);
}

// When it's the turn of the computer
// Enter O into the sqaure generated randomly
void computerTurnTTT(char ticTacToe[3][3], char randomSquare){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(ticTacToe[i][j] == randomSquare) {
                ticTacToe[i][j] = 'O';
            }
        } 
    }
}

// When it's the turn of the user
// Enter X into the sqaure specified by the user
void userTurnTTT(char ticTacToe[3][3], char input){
    if(input != 0){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if(ticTacToe[i][j] == input) {
                        ticTacToe[i][j] = 'X';
                }
            } 
         }
    } 
}


// Display the tic tac toe visually
void displayTTT(char ticTacToe[3][3]){
    int squareNumber = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            squareNumber++;
            cout << ticTacToe[i][j];
            if(squareNumber == 1 || squareNumber == 4 || squareNumber == 7){
                cout << "|";
            } else if(squareNumber == 2 || squareNumber == 5 || squareNumber == 8){
                cout << "|";
            } else if (squareNumber == 3 || squareNumber == 6){
                cout << "\n" << "------";
            } else {
                cout << "\n";
            }
        }
        cout << endl; 
    }
}

// Determines who wins
int win (char ticTacToe[3][3]){
    for(int i = 0; i < 3; i++){
        if(ticTacToe[i][0] == 'X' && ticTacToe[i][1] == 'X' && ticTacToe[i][2] == 'X'){
            return 1;
        } else if (ticTacToe[0][i] == 'X' && ticTacToe[1][i] == 'X' && ticTacToe[2][i] == 'X'){
            return 1;
        } else if (ticTacToe[0][0] == 'X' && ticTacToe[1][1] == 'X' && ticTacToe[2][2] == 'X'){
            return 1;
        }  else if (ticTacToe[0][2] == 'X' && ticTacToe[1][1] == 'X' && ticTacToe[2][0] == 'X'){
            return 1;
        } else if(ticTacToe[i][0] == 'O' && ticTacToe[i][1] == 'O' && ticTacToe[i][2] == 'O'){
            return 2;
        } else if (ticTacToe[0][i] == 'O' && ticTacToe[1][i] == 'O' && ticTacToe[2][i] == 'O'){
            return 2;
        } else if (ticTacToe[0][0] == 'O' && ticTacToe[1][1] == 'O' && ticTacToe[2][2] == 'O'){
            return 2;
        }  else if (ticTacToe[0][2] == 'O' && ticTacToe[1][1] == 'O' && ticTacToe[2][0] == 'O'){
            return 2;
        }
    }
    return 0;
}

// Game's main function
void ticTacToe(){
    char ticTacToe[3][3];

    // initialise the tic tac toe game Squares

    ticTacToe[0][0] = '1';
    ticTacToe[0][1] = '2';
    ticTacToe[0][2] = '3';
    ticTacToe[1][0] = '4';
    ticTacToe[1][1] = '5';
    ticTacToe[1][2] = '6';
    ticTacToe[2][0] = '7';
    ticTacToe[2][1] = '8';
    ticTacToe[2][2] = '9';

    // Toss whose turn start first
    // if 0 computer turn
    // if 1 user turn
    srand(time(0));
    int turn = rand() % 2;
    
    // Display the game before user or computer enters their elements
    cout << "Game Started \n";
    displayTTT(ticTacToe);

    // stores the input of user 
    char userIn = 0;

    // stores the random input of computer
    int randSquare;
    
    // Stores the char value of the int randSquare
    char convertedInput;

    for (int i = 0; i < 9; i++){

        // Incase user or computer wins between the round (i: 0 - 7)
        // Display a message
        // and stop the loop
        if(win(ticTacToe) == 1){
            cout << "User Won!";
            break;
        } else if (win(ticTacToe) == 2){
            cout << "Computer Won!";
            break;
        }

        // Turns of user or computer
        if (turn == 0){
            // If computer turn 

            cout << "COMPUTER TURN: \n";

            // Incase computer generate a random number
            // that is already taken
            // then it generates again
            // until it gets a random number that is not taken
            do{
                srand(time(0));
                randSquare = rand() % 9 + 1;
                convertedInput = convertInputToChar(randSquare);
            }  while(squareTakenTTT(ticTacToe, convertedInput) != false);

            // Insert the computer input into the tic tac toe square
            computerTurnTTT(ticTacToe, convertedInput);

            // pass the turn to user
            turn = 1;
        } else {
            // if user turn 

            cout << "USER TURN: \n";
            cout << "Enter Number (1-9) or (Any Key->quit): ";
            userIn = userInput();
            

            // Incase user types anything besides the (0-9)
            // It will terminate the game and display message
            if(userIn == '0'){
                cout << "Good Bye!";
                break;
            }
            
            // Check if the square is already taken or not
            // Incase taken ask user to enter again
            while(squareTakenTTT(ticTacToe, userIn) != false){
                cout << "Square already taken, try again:";
                userIn = userInput();
            }

            // Insert the user input into the tic tac toe square
            userTurnTTT(ticTacToe, userIn);

            // pass the turn to computer
            turn = 0;
        }

        cout << '\n';
        displayTTT(ticTacToe);

        // Incase the game has reached the last square!
        if(i == 8 && win(ticTacToe) == 1){
            cout << "User Won!";
            break;
        } else if (i == 8 && win(ticTacToe) == 2){
            cout << "Computer Won!";
            break;
        } else if (i == 8 && win(ticTacToe) == 0){
            cout << "Game Draw!";
            break;
        }
    }
}

int main (){
    ticTacToe();
    cout << '\n';
    return 0;
}
