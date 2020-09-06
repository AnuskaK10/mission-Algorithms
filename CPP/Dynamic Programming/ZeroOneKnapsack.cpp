// Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
// In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
// Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
// You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, int n, vector<int> weight, vector<int> value) {
    vector<vector<int>> dp(W+1, vector<int>(n+1, 0));

    for(int i = 1;i <= W;i++) {
        for(int j = 1; j <= n;j++) {
            dp[i][j] = max(i-weight[j-1] < 0 ? 0 : (dp[i-weight[j-1]][j-1] + value[j-1]), dp[i][j-1]);
        }   
    }

    return dp[W][n];
}

int main() {
    int W, n;
    vector<int>weight, value;
    cout<<"Enter size of knapsack:";
    cin>>W;
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter weight of "<<n<<" items:\n";
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        weight.push_back(x);
    }
    cout<<"Enter value of "<<n<<" items:\n";
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        value.push_back(x);
    }

    cout<<"Solution = "<<knapsack(W, n, weight, value)<<endl;
    return 0;

}