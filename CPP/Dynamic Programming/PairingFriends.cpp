#include<bits/stdc++.h>
using namespace std;

int pairFriends(int n) {
    vector<int>dp(n+1, 1);

    for(int i = 2;i <= n;i++) {
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    cout<<"Enter friends:";
    cin>>n;
    cout<<"Solution = "<<pairFriends(n)<<endl;
    return 0;

}