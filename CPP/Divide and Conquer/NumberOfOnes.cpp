#include<bits/stdc++.h>
using namespace std;

int returnCount(vector<int> arr, int l, int h) {
    if(l < h) {

        int count = 0;

        int m = l + (h-l)/2;

        if(arr[m] == 1)
            count = (h-m+1) + returnCount(arr, l, m-1);

        else
            count = returnCount(arr, m+1, h);

        return count;
    }

    return 0;
}

int main() {

    int n;
    vector<int> arr;

    cout<<"Enter the number of elements in the array:";
    cin>>n;

    cout<<"Enter the sorted binary array:\n";
    for(int i = 0;i < n;i++) {
        int inp;
        cin>>inp;
        arr.push_back(inp);
    }

    cout<<"Number of ones in the array = "<<returnCount(arr, 0, n-1)<<endl;
    return 0;
}