// Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. 
// The array is virtually split into a sorted and an unsorted part. 
// Values from the unsorted part are picked and placed at the correct position in the sorted part.

#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    for(int i = 0;i < n;i++) {
        int j = i-1;
        while(j >= 0 && arr[j+1] < arr[j]) {
            swap(arr[j], arr[j+1]);
            j--;
        }
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
    cout<<"Insertion Sort:\n";
    double start = clock();
    insertionSort(arr, n);
    double stop = clock();
    double duration = ((double)(stop - start))/CLOCKS_PER_SEC;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(arr, n);

    cout<<endl;

    return 0;
}