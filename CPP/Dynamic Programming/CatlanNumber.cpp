#include<bits/stdc++.h>
using namespace std;

int nthCatlanNumber(int n) {
    int ans = 1;
    for(int i = 1; i <= n;i++) {
        ans = ans*(n+i)/i;
    }
    ans /= (n+1);

    return ans;
}

int main() {
    int n, choice;

    cout<<"Enter the value of n:";
    cin>>n;

    cout<<n<<"th Catlan Number = "<<nthCatlanNumber(n)<<endl;
    return 0;
}