#include<bits/stdc++.h>
using namespace std;

int countOccurance(vector<int> arr, int i, int j, int search) {
    if(i == j) {
        if(arr[i] == search) 
            return 1;
        else 
            return 0;
    }

    int m = i + (j-i)/2;

    int left = 0, right = 0;
    if(arr[m] >= search)
        left = countOccurance(arr, i, m, search);
    if(arr[m] <= search)
        right = countOccurance(arr, m+1, j, search);

    return left + right;
}

int main(int argc, char* argv[]) {
    int res;
    int n, search;
    vector<int>arr;
    if(argc == 1) {
        cout<<"Enter number of elements in the array:";
        cin>>n;

        cout<<"Enter the elements of the array:\n";
        for(int i = 0;i < n;i++) {
            int x;
            cin>>x;
            arr.push_back(x);
        }

        cout<<"Enter the search element:";
        cin>>search;
    }

    else {
        ifstream fin(argv[1]);
        string inp;
        fin>>inp;
        n = stoi(inp);

        for(int i = 0;i < n;i++) {
            int x;
            fin>>inp;
            x = stoi(inp);
            arr.push_back(x);
        }

        fin>>inp;
        search = stoi(inp);
    }
    
    res = countOccurance(arr, 0, n-1, search);

    cout<<"Count of occurance of "<<search<<" = "<<res<<endl;
    return 0;
}