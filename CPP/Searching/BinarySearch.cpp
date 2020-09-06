#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

int binarySearch(vector<int> arr, int n, int search) {
    
    int l = 0, r = n-1;
    while(l < r) {
        int m = l + (r-l)/2;
        if(arr[m] == search)
            return m;
        
        if(arr[m] < search)
            l = m+1;
        else
            r = m-1;
    }

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
    int result = binarySearch(arr, n, search);
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