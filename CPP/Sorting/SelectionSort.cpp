// The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. 
// The algorithm maintains two subarrays in a given array.

// 1) The subarray which is already sorted.
// 2) Remaining subarray which is unsorted.

// In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

vector<int> selectionSort(vector<int> arr, int n) {

    int least, comparisons=0;

    for(int i = 0;i < n-1;i++) {
        for(int j = i+1;j < n;j++) {
            comparisons++;
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    cout<<"Number of comparison = "<<comparisons<<endl;
    return arr;
}

vector<int> selectionSortFlag(vector<int> arr, int n) {

    int least, comparisons=0;
    bool flag = false;

    for(int i = 0;i < n-1;i++) {
        flag = true;
        for(int j = i+1;j < n;j++) {
            comparisons++;
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                flag = false;
            }
        }
        if(flag)
            break;
    }

    cout<<"Number of comparison = "<<comparisons<<endl;
    return arr;
}

int main(int argc, char const* argv[]) {

    int n;
    vector<int> res, arr;
    if(argc == 1){
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

    cout<<endl;
    cout<<"Selection sort without flag:\n";
    double start = clock();
    res = selectionSort(arr, n);
    double stop = clock();
    double duration = ((double)(stop - start))/CLOCKS_PER_SEC;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(res, n);

    cout<<endl;

    cout<<"Selection sort with flag:\n";
    start = clock();
    res = selectionSortFlag(arr, n);
    stop = clock();
    duration = ((double)(stop - start))/CLOCKS_PER_SEC;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(res, n);

    cout<<endl;

    return 0;
}