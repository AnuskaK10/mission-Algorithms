// Merge Sort is a Divide and Conquer algorithm. 
// It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. 
// The merge() function is used for merging two halves. 
// The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {

    vector<int>left, right;
    for(int i=l;i <= m;i++) 
        left.push_back(arr[i]);
    for(int i=m+1;i <= r;i++) 
        right.push_back(arr[i]);
    
    int i = 0, j = 0;
    
    for(int x=l;x <= r;x++) {
        if(i < left.size() && (j >= right.size() || (left[i] < right[j])))
            arr[x] = left[i++];
        else    
            arr[x] = right[j++];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
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
    cout<<"Merge Sort:\n";
    double start = clock();
    mergeSort(arr, 0, n-1);
    double stop = clock();
    double duration = ((double)(stop - start))/CLOCKS_PER_SEC;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(arr, n);

    cout<<endl;

    return 0;
}