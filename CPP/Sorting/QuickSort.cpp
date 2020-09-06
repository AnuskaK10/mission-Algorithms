// Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

// Always pick first element as pivot.
// Always pick last element as pivot (implemented below)
// Pick a random element as pivot.
// Pick median as pivot.
// The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.

#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

int partition(vector<int>& arr, int l, int h) {
    
    int pivot = arr[h];
    int i = l, j = l;

    while(j < h) {
        if(arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    swap(arr[h], arr[i]);

    return i;
}

void quickSort(vector<int>& arr, int l, int h) {
    if(l < h) {
        int p = partition(arr, l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
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
    cout<<"Quick Sort:\n";
    double start = clock();
    quickSort(arr, 0, n-1);
    double stop = clock();
    double duration = ((double)(stop - start))/CLOCKS_PER_SEC;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(arr, n);

    cout<<endl;

    return 0;
}