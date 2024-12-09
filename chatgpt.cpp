#include <iostream>
using namespace std;
char board[3][3] = {{'1' , '2' , '3',},
                        {'4' , '5' , '6'},
                        {'7' , '8' , '9'}};

char currentMarker;
int currentPlayer;
void dispLayboard(){
    cout <<"\n";
    for (int i = 0; i < 3; i++)
    {
        for(int j=0; j<3; j++){
            cout << board[i][j]<<" ";
        }
        cout <<"\n";
    }
    
}
bool placeMarker(int position){
    int row=(position -1)/3;
    int col =(position -1)%3;
    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = currentMarker;
        return true;
    }
    else {
        return false;
    }
}
int cheakWinner(){
    for (int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] ==board[i][2]){
            return currentPlayer;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if(board[0][i] ==board[1][i]==board[2][i]){
            return currentPlayer;

        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return currentPlayer;
    
    }
    if(board[0][2] == board[1][1] && board[1][1]== board[2][0]){
        return currentPlayer;
    }
    return 0;
    
    
}
void swapPlayerAndMarker(){
    if (currentPlayer = 'X')
    {
        currentMarker = 'O';
        currentPlayer = 2;
    }else{
        currentMarker = 'X';
        currentPlayer = 1;
    }
    
}
void playGame(){
    cout << "Player 1, Chose your marker(X or O)";
    cin >> currentMarker;
    dispLayboard();
    int winner = 0;
    for (int  i = 0; i < 9; i++){}
    {
        cout << "player" << currentPlayer << "s turn. Enter your position (1-9)";
        int position;
        cin >> position;
        if (position <1 || position > 9)
        {
            cout << "invalid position";
            i--;
            continue;
        }
        if (placeMarker(position))
        {
            cout << "position already taken";
            i--;
            continue;
        }
        winner = cheakWinner();
        if (winner != 0)
        {
            cout << "player " <<winner <<"wins";
            break;
        }
        swapPlayerAndMarker();
        
        
        
    }
    
    
}
int main(){
    
}