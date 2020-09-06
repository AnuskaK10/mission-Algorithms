#include<bits/stdc++.h>
using namespace std;

void jumpKnight(int row, int col, int& move, int n, vector<vector<int>>& board) {
    if((row < 0 || row >= n || col < 0 || col >= n) || (board[row][col] >= 0))
        return;

    board[row][col] = move++;

    jumpKnight(row+1, col+2, move, n, board);
    jumpKnight(row-1, col+2, move, n, board);
    jumpKnight(row+2, col+1, move, n, board);
    jumpKnight(row+2, col-1, move, n, board);
    jumpKnight(row-2, col+1, move, n, board);
    jumpKnight(row+1, col-2, move, n, board);
    jumpKnight(row-1, col-2, move, n, board);
    jumpKnight(row-2, col-1, move, n, board);
}

int main() {
    int n, move = 0;
    cout<<"Enter the size of the board:";
    cin>>n;
    vector<vector<int>> board(n, vector<int> (n, -1));
    cout<<"Board:"<<endl;
    jumpKnight(0, 0, move, n, board);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
    return 0;
}