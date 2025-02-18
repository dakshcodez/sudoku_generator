#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<ctime>
#include<chrono>
#include "solver.h"

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

int main(){
    vector<vector<int>> board(9,vector<int>(9,0));

    vector<int> num_vec = {1,2,3,4,5,6,7,8,9};
    shuffleVector(num_vec);

    generateFullSudoku(board,num_vec);
    printBoard(board);
    return 0;
}