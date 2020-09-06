#include<bits/stdc++.h>
using namespace std;

long returnPower(int x, int n) {
    if(n == 0 || n == 1)
        return x*n;
    
    long res = returnPower(x, n/2);
    if(n % 2 == 0)
        res *= res;
    else
        res *= res*x;
    
    return res;
}

int main() {
    int x, n;
    cout<<"Enter the base:";
    cin>>x;
    cout<<"Enter the exponent:";
    cin>>n;

    cout<<"Power("<<x<<", "<<n<<") = "<<returnPower(x, n)<<endl;

    return 0;
}