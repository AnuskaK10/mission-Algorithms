#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> moveRat(int row, int col, int n, vector<vector<int>> board, vector<vector<int>> path) {
    if(row >= n || col >= n || board[row][col] == 1)
        return {};

    path[row][col] = 1;

    if(row == n-1 && col == n-1)
        return path;
    
    vector<vector<int>> res = moveRat(row+1, col, n, board, path);
    if(res.empty()) {
        return moveRat(row, col+1, n, board, path);
    }

    return res;
}

int main(int argc, char* argv[]) {
    int n = 4;
    vector<vector<int>> arr(
    {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 0, 1, 1},
        {0, 0, 0, 0}
    });

    if(argc > 1) {
        arr.clear();
        ifstream fin(argv[1]);
        string str;
        fin>>str;
        n = stoi(str);

        for(int i = 0;i < n;i++) {
            vector<int> temp;
            for(int j = 0;j < n;j++) {
                int inp;
                fin>>str;
                inp = stoi(str);
                temp.push_back(inp);
            }
            arr.push_back(temp);
        }
        fin.close();
        // for(int i = 0;i < n;i++) {
        //     for(int j = 0;j < n;j++) {
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    vector<vector<int>> res = moveRat(0, 0, n, arr, vector<vector<int>>(n, vector<int>(n, 0)));

    if(res.empty())
        cout<<"Path not possible";
    else
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}