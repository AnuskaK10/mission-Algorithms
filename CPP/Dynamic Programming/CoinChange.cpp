#include<bits/stdc++.h>
using namespace std;

int coinChange(int change, int n, vector<int> coins) {
    vector<vector<int>> dp(n+1, vector<int>(change+1, 0));

    for(int i = 1; i <= n;i++) {
        for(int j = 0;j <= change;j++) {            
            if(j == 0)
                dp[i][0] = 1;
            else {
                dp[i][j] = ((j - coins[i-1]) < 0? 0 : dp[i][j-coins[i-1]]) +  dp[i-1][j];
            }
        }
    }

    return dp[n][change];
}

int main() {
    int W, n;
    vector<int>weight, value;
    cout<<"Enter change:";
    cin>>W;
    cout<<"Enter number of coins:";
    cin>>n;
    cout<<"Enter value of "<<n<<" coins:\n";
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        weight.push_back(x);
    }

    cout<<"Solution = "<<coinChange(W, n, weight)<<endl;
    return 0;

}