#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<vector<int>>& board, int row, int col, int num){
    //checking row and column
    for (int i = 0; i < 9; i++){
        if (board[row][i] == num || board[i][col] == num){
            return false;
        }
    }
    //checking the box
    int subRow = (row/3)*3, subCol = (col/3)*3;
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (board[subRow + row][subCol + col] == num){
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board){
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            if (board[row][col] == 0){
                for (int num = 1; num <= 9; num++){
                    if (isValid(board, row, col, num)){
                        board[row][col] = num;
                        if (solve(board)){
                            return true;
                        }
                        board[row][col] = 0;    //backtracking
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(vector<vector<int>>& board){
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            cout<<board[row][col]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    solve(board);
    printBoard(board);
    return 0;
}