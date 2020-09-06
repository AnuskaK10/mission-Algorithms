// Counting sort is a sorting technique based on keys between a specific range. 
// It works by counting the number of objects having distinct key values (kind of hashing). 
// Then doing some arithmetic to calculate the position of each object in the output sequence.

#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

vector<int> countingSort(vector<int> arr, int n) {
    int largest = INT_MIN;

    for(int i : arr)
        if(largest < i)
            largest = i;

    vector<int> positions(largest+1, 0);
    for(int i : arr)
        positions[i]++;
    for(int i = 1;i <= largest;i++)
        positions[i] += positions[i-1];
    
    vector<int> res = arr;

    for(int i = n-1;i >= 0;i--) {
        res[positions[arr[i]]-1] = arr[i];
        positions[arr[i]]--;
    }
    return res;
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
    cout<<"Counting Sort:\n";
    double start = clock();
    res = countingSort(arr, n);
    double stop = clock();
    double duration = ((double)(stop - start))/CLOCKS_PER_SEC;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    displayVector(res, n);

    cout<<endl;
}