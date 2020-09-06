#include<bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {
    int i2 = 0, i3 = 0, i5 = 0;
    int factor2 = 2, factor3 = 3, factor5 = 5;

    vector<int> ugly(n, 1);

    for(int i = 1;i < n;i++) {
        int next_ugly = min(min(factor2, factor3), factor5);
        ugly[i] = next_ugly;

        if(next_ugly == factor2) {
            i2++;
            factor2 = ugly[i2]*2;
        }
        if(next_ugly == factor3) {
            i3++;
            factor3 = ugly[i3]*3;
        }
        if(next_ugly == factor5) {
            i5++;
            factor5 = ugly[i5]*5;
        }
    }

    return ugly[n-1];
}

bool isUgly(int num) {
    while(num > 1) {
        if(num%2 == 0)
            num /= 2;
        else if(num%3 == 0)
            num /= 3;
        else if(num%5 == 0)
            num /= 5;
        else
            return false;
    }
    if(num == 1)
        return true;
    return false;
}


int main() {
    int n, choice;

    cout<<"1. nth Ugly Number"<<endl<<"2. Check if n is Ugly Number"<<endl<<"Enter your option:";
    cin>>choice;

    cout<<"Enter the value of n:";
    cin>>n;

    switch (choice)
    {
    case 1:
        cout<<"nth Ugly Number = "<<nthUglyNumber(n)<<endl;
        break;
    case 2:
        if(isUgly(n))
            cout<<"It is an ugly number"<<endl;
        else
            cout<<"It is not an ugly numebr"<<endl;
        break;
    default:
        cout<<"Invalid choice"<<endl;
        break;
    }
    return 0;
}