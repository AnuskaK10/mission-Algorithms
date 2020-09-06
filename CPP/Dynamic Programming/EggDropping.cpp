#include<bits/stdc++.h>
using namespace std;

int returnMaxTrials(int n, int e) {
    vector<vector<int>> arr(e+1, vector<int> (n+1, 0));

    for(int i = 1;i <= e;i++) {
        arr[i][1] = 1;
        arr[i][0] = 0;
    }

    for(int i = 1;i <= n;i++) {
        arr[1][i] = i;
    }

    for(int i = 2;i <= e;i++) {
        for(int j = 2;j <= n;j++) {
            arr[i][j] = INT_MAX;
            for(int k = 1;k <= j;k++) {
                int res = 1 + max(arr[i-1][k-1], arr[i][j-k]);

                if(res < arr[i][j])
                    arr[i][j] = res;
            }
        }
    }

    return arr[e][n];
}

int main() {
    cout<<returnMaxTrials(36, 2);

    return 0;
}