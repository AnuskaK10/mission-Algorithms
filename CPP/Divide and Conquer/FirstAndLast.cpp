#include<bits/stdc++.h>
using namespace std;

vector<int> findFirstLast(vector<int> arr, int i, int j, int search) {
    if(i == j) {
        if(arr[i] == search) 
            return {i, i};
        else 
            return {-1, -1};
    }

    int m = i + (j-i)/2;

    vector<int> left = findFirstLast(arr, i, m, search);
    vector<int> right = findFirstLast(arr, m+1, j, search);
    int min_index = min(left[0] < 0 ? INT_MAX : left[0], right[0] < 0 ? INT_MAX : right[0]);
    int max_index = max(left[1] < 0 ? INT_MIN : left[1], right[1] < 0 ? INT_MIN : right[1]);

    return {min_index, max_index};
}

int main(int argc, char* argv[]) {
    vector<int> res;
    int n, search;
    vector<int>arr;
    if(argc == 1) {
        cout<<"Enter number of elements in the array:";
        cin>>n;

        cout<<"Enter the elements of the array:\n";
        for(int i = 0;i < n;i++) {
            int x;
            cin>>x;
            arr.push_back(x);
        }

        cout<<"Enter the search element:";
        cin>>search;
    }

    else {
        ifstream fin(argv[1]);
        string inp;
        fin>>inp;
        n = stoi(inp);

        for(int i = 0;i < n;i++) {
            int x;
            fin>>inp;
            x = stoi(inp);
            arr.push_back(x);
        }

        fin>>inp;
        search = stoi(inp);
    }

    res = findFirstLast(arr, 0, n-1, search);

    cout<<"First occurance at index: "<<res[0]<<endl<<"Last occurance at index: "<<res[1]<<endl;
    return 0;
}