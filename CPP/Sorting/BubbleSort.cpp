// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
// Example:
// First Pass:
// ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
// ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
// ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
// ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

// Second Pass:
// ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
// ( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
// ( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
// Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.

// Third Pass:
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )


#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

vector<int> bubbleSort(vector<int> arr, int n) {
    
    // Performing Bubble Sort
    int comparisons = 0;
    for(int i=0;i < n-1;i++) {
        for(int j=0;j < n-i-1;j++) {
            
            comparisons++;
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout<<"Number of comparisons = "<<comparisons<<endl;
    return arr;
}

vector<int> bubbleSortFlag(vector<int> arr, int n) {
    
    // Performing Bubble Sort
    bool flag = true;
    int comparisons = 0;
    for(int i=0;i < n-1;i++) {
        flag = true;
        for(int j=0;j < n-i-1;j++) {
            comparisons++;
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }

        if(flag)
            break;
    }

    cout<<"Number of comparisons = "<<comparisons<<endl;
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
    cout<<"Bubble sort without flag:\n";
    double start = clock();
    res = bubbleSort(arr, n);
    double stop = clock();
    double duration = ((double)(stop - start))/CLOCKS_PER_SEC;
    // duration *= 1e-6;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(res, n);

    cout<<endl;

    cout<<"Bubble sort with flag:\n";
    start = clock();
    res = bubbleSortFlag(arr, n);
    stop = clock();
    duration = ((double)(stop - start))/CLOCKS_PER_SEC;
    // duration *= 1e-6;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(res, n);

    cout<<endl;

    return 0;
}