#include<bits/stdc++.h>
using namespace std;

int nthFibonacci(int n) {
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);

    for(int i = 2;i <= n;i++)
        fib.push_back(fib[i-1] + fib[i-2]);

    return fib[n];
}

void displayVector(vector<int> fib) {
    cout<<fib.size()<<" Fibonacci numbers:"<<endl;
    fib.erase(fib.begin());
    for(int i : fib)
        cout<<i<<" ";
    cout<<endl;
}

void displayNFibonacci(int n) {
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);

    for(int i = 2;i <= n;i++)
        fib.push_back(fib[i-1] + fib[i-2]);

    displayVector(fib);
}

int main() {
    int n, choice;

    cout<<"1. nth Fibonacci Number"<<endl<<"2. Print n Fibonacci Numbers"<<endl<<"Enter your option:";
    cin>>choice;

    cout<<"Enter the value of n:";
    cin>>n;

    switch (choice)
    {
    case 1:
        cout<<"nth Fibonacci Number = "<<nthFibonacci(n)<<endl;
        break;
    case 2:
        displayNFibonacci(n);
        break;
    default:
        cout<<"Invalid choice"<<endl;
        break;
    }
    return 0;
}