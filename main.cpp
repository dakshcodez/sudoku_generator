#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<ctime>
#include<chrono>
#include "solver.h"

using namespace std;

void shuffleVector(vector<int>& vec){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 g(seed);

    shuffle(vec.begin(), vec.end(), g);
}

bool generateFullSudoku(vector<vector<int>>& board,vector<int> vec){
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            if (board[row][col] == 0){
                for (int i = 0; i < 9; i++){
                    if(isValid(board,row,col,vec[i])){
                        board[row][col] = vec[i];
                        if (generateFullSudoku(board,vec)){
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void removeNumbers(vector<vector<int>>& board, int difficulty){
    int emptyCells = difficulty ;
    while (emptyCells != 0){
        int r = rand() % 9;
        int c = rand() % 9;
        if (board[r][c] != 0){
            int backup = board[r][c];
            board[r][c] = 0;

            vector<vector<int>> tempBoard = board;
            if (solve(tempBoard)){
                emptyCells--;
            } else {
                board[r][c] = backup;
            }
        }
    }
}

int main(){
    srand(time(0));

    vector<vector<int>> board(9,vector<int>(9,0));

    vector<int> num_vec = {1,2,3,4,5,6,7,8,9};
    shuffleVector(num_vec);

    generateFullSudoku(board,num_vec);
    // printBoard(board);
    // cout<<"\n\n\n";
    removeNumbers(board, 40);
    printBoard(board);
    //cout<<"\n\n\n";
    // solve(board);
    // printBoard(board);
    return 0;
}