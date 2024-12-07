#include <iostream>
using namespace std;
void drawBoard(char board[3][3]){
    cout << "___________________\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for(int j =0; j <3 ; j++){
            cout << board[i][j]<<" | ";
        }
        cout <<"\n_____________\n";
    }
    
}
bool checkWin(char board[3][3], char player){
    for (int i = 0; i < 3; i++)
    {
        if(board[i][0] == player && board[i][1] == player &&board[i][2] == player)
        return true;
        if(board[0][i] == player && board[1][i] == player &&board[2][1] == player)
        return true;
    }
    if(board[0][0] == player && board[1][1] == player &&board[2][2] == player)
        return true;
        if(board[2][0] == player && board[1][1] == player &&board[2][0] == player)
        return true;

        return false;
    
    
}
int main(){
    char board[3][3] = {{ ' ' , ' ' , ' ' },
    
                        { ' ' , ' ' , ' ' },
                        
                        { ' ' , ' ' , ' ' }};

    char player = 'X';
    int row, col;
    int turn;
    for (turn = 0; turn < 9; turn++){
        drawBoard(board);
        while (true)
        {
            cout << "Player" <<player << ", enter row (0-2) and coulum (0-2)";
            cin >> row >> col;
            if(board[row][col] != ' ' || row <0 || row >2 || col <0 || col >2){
                cout << "invalid input . Try again";
            }else{
                break;
            }
        }
        board[row][col] = player;
        if(checkWin(board,player)){
            drawBoard(board);
            cout <<"player"<<player <<"wins";
            break;
        }
        player = (player =='X')? 'O':'X';
        
    }

    // cout <<"Welcome to tic tac toe";
    drawBoard(board);
    if(turn == 9 && !checkWin(board, 'X') && !checkWin(board, '0')){
        cout << "Its a draw";
    }
}