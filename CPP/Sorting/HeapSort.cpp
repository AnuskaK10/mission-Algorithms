// Heap sort is a comparison based sorting technique based on Binary Heap data structure. 
// It is similar to selection sort where we first find the maximum element and place the maximum element at the end. 
// We repeat the same process for the remaining elements.

#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int l = 2*i;
    int r = 2*i + 1;

    if(l < n && arr[l] > arr[r] && arr[l] > arr[i]) {
        swap(arr[i], arr[l]);
        heapify(arr, n, l);
    }

    else if(r < n && arr[r] >= arr[l] && arr[r] > arr[i]) {
        swap(arr[i], arr[r]);
        heapify(arr, n, r);
    }

    else
        return;
}

void heapSort(vector<int>& arr, int n) {
    for(int i = n-1;i >= 0;i--) {
        heapify(arr, n, i);
    }

    for(int i = 0;i < n;i++) {
        swap(arr[0], arr[n-i-1]);
        heapify(arr, n-i-1, 0);
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
    cout<<"Heap Sort:\n";
    double start = clock();
    heapSort(arr, n);
    double stop = clock();
    double duration = ((double)(stop - start))/CLOCKS_PER_SEC;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(arr, n);

    cout<<endl;

    return 0;
}