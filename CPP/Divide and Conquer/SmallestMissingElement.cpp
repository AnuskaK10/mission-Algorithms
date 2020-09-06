#include<bits/stdc++.h>
using namespace std;

int returnSmallestMissingNumber(vector<int> arr, int l, int h) {
    if(arr[l] > l)
        return l;

    if(l < h) {
        int m = l + (h-l)/2;
        if(m < arr[m])
            return returnSmallestMissingNumber(arr, l, m);
        
        else
            return returnSmallestMissingNumber(arr, m+1, h);
    }

    return -1;
}

int main() {
    
    int n;
    vector<int> arr;

    cout<<"Enter the number of elements in the array:";
    cin>>n;

    cout<<"Enter the array:\n";
    for(int i = 0;i < n;i++) {
        int inp;
        cin>>inp;
        arr.push_back(inp);
    }

    cout<<"Smallest missing element element = "<<returnSmallestMissingNumber(arr, 0, n-1)<<endl;
    return 0;
}