#include<bits/stdc++.h>
using namespace std;

int cutRods(int rod, int n, vector<int> length, vector<int> price) {
    vector<vector<int>> dp(n+1, vector<int>(rod+1, 0));

    for(int i = 1; i <= n;i++) {
        for(int j = 1;j <= rod;j++) {            
                dp[i][j] = max(j - length[i-1] < 0 ? 0 : price[i-1]+dp[i][j-length[i-1]], dp[i-1][j]);
        }
    }

    return dp[n][rod];
}

int main() {
    int W, n;
    vector<int>weight, value;
    cout<<"Enter length of rods:";
    cin>>W;
    cout<<"Enter number of pieces:";
    cin>>n;
    cout<<"Enter length of "<<n<<" pieces:\n";
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        weight.push_back(x);
    }
    cout<<"Enter price of "<<n<<" pieces:\n";
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        value.push_back(x);
    }

    cout<<"Solution = "<<cutRods(W, n, weight, value)<<endl;
    return 0;

}