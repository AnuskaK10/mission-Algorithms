#include<bits/stdc++.h>
#include "DisplayVector.hpp"
using namespace std;

int linearSearch(vector<int> arr, int n, int search) {
    for(int i = 0;i < n;i++) {
        if(arr[i] == search)
            return i;
    }

    return -1;
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
    
    int search;
    cout<<"Enter number to search for = ";
    cin>>search;

    float start = clock();
    int result = linearSearch(arr, n, search);
    if(result < 0)
        cout<<"Not found."<<endl;
    else
        cout<<"Found at position "<<result<<endl;

    float stop = clock();
    float duration = ((double)(stop - start))/CLOCKS_PER_SEC;
    // duration *= 1e-6;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;

    cout<<endl;
}