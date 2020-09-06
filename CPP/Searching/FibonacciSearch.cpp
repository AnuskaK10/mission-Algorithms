#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

int fibonacciSearch(vector<int> arr, int search, int n) {

    int fib2 = 0, fib1 = 1, fib0;
    fib0 = fib1+fib2;
    while(fib0 < n) {
        fib2 = fib1;
        fib1 = fib0;
        fib0 = fib1 + fib2;
    }

    int offset = -1;
    while(fib0 > 1) {
        int i = min(fib2 + offset, n-1);

        if(arr[i] < search) {
            fib0 = fib1;
            fib1 = fib2;
            fib2 = fib0 - fib1;
            offset = i;
        }

        else if(arr[i] > search) {
            fib0 = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib0 - fib1;
        }

        else
            return i;
    }

    if(fib1 && arr[offset+1] == search)
        return offset+1;

    return -1;
}

int main(int argc, char const *argv[]) {

    int n;
    vector<int> res, arr;
    if(argc == 1) {
        cout<<"Enter the size of the array:";
        cin>>n;
        cout<<"Enter "<<n<<" elements:\n";
        for(int i=0;i < n;i++) {
            int inp;
            cin>>inp;
            arr.push_back(inp);
        }
    }

    else {
        ifstream fin(argv[1]);
        string str;
        fin>>str;
        n = stoi(str);

        for(int i = 0;i < n;i++) {
            int inp;
            fin>>str;
            inp = stoi(str);
            arr.push_back(inp);
        }
        fin.close();
    }
    cout<<endl<<endl;
    
    int search;
    cout<<"Enter number to search for = ";
    cin>>search;

    sort(arr.begin(), arr.end());
    float start = clock();
    int result = fibonacciSearch(arr, search, n);
    if(result < 0)
        cout<<"Not found."<<endl;
    else
        cout<<"Found at position "<<result<<endl;

    float stop = clock();
    float duration = ((double)(stop - start))/CLOCKS_PER_SEC;
    // duration *= 1e-6;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;

    cout<<endl;
}