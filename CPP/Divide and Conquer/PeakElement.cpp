#include<bits/stdc++.h>
using namespace std;

int returnPeak(vector<int> arr, int l, int h, int n) {
    if(l <= h) {
        int m = l+(h-l)/2;
        int left, right;
        
        left = m-1 >= 0 ? arr[m-1] : INT_MIN;
        right = m+1 < n ? arr[m+1] : INT_MIN;
        
        if(left > arr[m])
            return returnPeak(arr, l, m-1, n);
        else if(right > arr[m])
            return returnPeak(arr, m+1, h, n);
        else
            return m;
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

    cout<<"Index of peak element = "<<returnPeak(arr, 0, n-1, n)<<endl;
    return 0;
}