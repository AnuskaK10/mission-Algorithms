// We can’t use counting sort because counting sort will take O(n2) which is worse than comparison based sorting algorithms. 
// Can we sort such an array in linear time?
// Radix Sort is the answer. 
// The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. 
// Radix sort uses counting sort as a subroutine to sort.

#include<bits/stdc++.h>
# include "DisplayVector.hpp"
using namespace std;

vector<int> countingSort(vector<int> arr, vector<int> digits, vector<int>& temp_arr, int n) {

    vector<int> positions(10, 0);
    for(int i : digits)
        positions[i]++;
    for(int i = 1;i <= 9;i++)
        positions[i] += positions[i-1];
    
    vector<int> res1 = arr, res2 = temp_arr;

    for(int i = n-1;i >= 0;i--) {
        arr[positions[digits[i]]-1] = res1[i];
        temp_arr[positions[digits[i]]-1] = res2[i];
        positions[digits[i]]--;
    }
    return arr;
}


vector<int> radixSort(vector<int>arr,int n) {

    int val;
    vector<int> temp_arr = arr;
    do {
        val = 0;
        vector<int> digits;
        for(int i = 0;i < n;i++) {
            digits.push_back(temp_arr[i]%10);
            val += (temp_arr[i]%10);
            temp_arr[i] /= 10;
        }

        if(val == 0)
            break;

        arr = countingSort(arr, digits, temp_arr, n);
    }while(val != 0);

    return arr;
}

int main(int argc, char const *argv[]) {

    int n;
    vector<int> res, arr;
    if(argc == 1) {
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
    cout<<endl<<endl;
    
    float start = clock();
    res = radixSort(arr, n);
    float stop = clock();
    float duration = ((double)(stop - start))/CLOCKS_PER_SEC;
    // duration *= 1e-6;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;

    cout<<"Radix Sort:\n";
    displayVector(res, n);

    cout<<endl;
}