#include<bits/stdc++.h>
using namespace std;

int nthBellNumber(int n) {
    vector<vector<int>> bell(n+1, vector<int>(n+1, 0));
    bell[0][0] = 1;
    for(int i = 1;i <= n;i++) {        
        bell[i][0] = bell[i-1][i-1];
        for(int k = 1;k <= i;k++) {
            bell[i][k] = bell[i-1][k-1] + bell[i][k-1];
        }
    }

    return bell[n][0];
}

int main() {
    int n, choice;

    cout<<"Enter the value of n:";
    cin>>n;

    cout<<n<<"th Bell Number = "<<nthBellNumber(n)<<endl;
    return 0;
}