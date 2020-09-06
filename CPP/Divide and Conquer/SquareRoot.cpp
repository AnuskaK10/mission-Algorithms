#include<bits/stdc++.h>
using namespace std;

int returnRoot(int num) {
    int l = 0, h = (num/2) + 1;

    while (l <= h)
    {
        int m = l + (h-l)/2;

        if(m*m == num)
            return m;

        if(m*m < num)
            l = m+1;
        
        else
            h = m-1;
        // cout<<m;
    }

    return h;
    
}

int main() {
    int n;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"Square root = "<<returnRoot(n)<<endl;
    return 0;
}