#include<bits/stdc++.h>
using namespace std;

bool checkDanger(int row, int col, int n, vector<vector<int>> board) {
    for(int i = row-1;i >= 0;i--)
        if(board[i][col] == 1)
            return false;

    for(int i = row+1;i < n;i++)
        if(board[i][col] == 1)
            return false;

    for(int i = col+1;i < n;i++)
        if(board[row][i] == 1)
            return false;

    for(int i = col-1;i >= 0;i--)
        if(board[row][i] == 1)
            return false;

    for(int i = row+1, j = col+1;i < n && j < n;i++, j++)
        if(board[i][j] == 1)
            return false;

    for(int i = row+1, j = col-1;i < n && j >= 0;i++, j--)
        if(board[i][j] == 1)
            return false;
    
    for(int i = row-1, j = col+1;i >= 0 && j < n;i--, j++)
        if(board[i][j] == 1)
            return false;

    for(int i = row-1, j = col-1;i >= 0 && j >= 0;i--, j--)
        if(board[i][j] == 1)
            return false;

    return true;
}

bool queens(int row,int n,vector<vector<int>>& board) {

    if(row >= n)
        return true;

    bool flag;

    for(int j = 0;j < n;j++) {
        board[row][j] = 1;
        if(checkDanger(row, j, n, board))
            flag = queens(row+1, n, board);

        if(flag)
            return true;
        else
            board[row][j] = 0;
    }

    return false;
}

int main() {
    int n;
    cout<<"Enter the size of the board:";
    cin>>n;
    vector<vector<int>> board(n, vector<int> (n, 0));
    cout<<"Board:"<<endl;
    queens(0, n, board);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}