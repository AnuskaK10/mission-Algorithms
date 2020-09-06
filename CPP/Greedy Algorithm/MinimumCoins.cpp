#include<bits/stdc++.h>
using namespace std;

int numberOfCoins(vector<int> coins, int n, int change) {
    sort(coins.begin(), coins.end(), greater<int>());

    int count = 0;
    
    cout<<"Coins required:"<<endl;
    while(change > 0) {
        int i = 0;
        while(i < n && (change - coins[i++] < 0));
        cout<<coins[i-1]<<" ";
        change -= coins[i-1];
        count++;
    }
    cout<<endl;

    return count;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; 

    cout<<"Enter the change:";
    int change;
    cin>>change;

    int res = numberOfCoins(coins, coins.size(), change);
    cout<<"Number of coins required:"<<res<<endl;

    return 0;
}