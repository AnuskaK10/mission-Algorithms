#include<bits/stdc++.h>
using namespace std;

int returnMinIndex(vector<int>arr, int l, int h) {
    int min_val = INT_MAX, min_index = -1;
    for(int i = l;i <= h;i++)
        if(arr[i] < min_val) {
            min_val = arr[i];
            min_index = i;
        }

    return min_index;
}

int returnMaxArea(vector<int>arr, int l, int h) {
    if(l == h)
        return arr[l];

    int min_index = returnMinIndex(arr, l, h);

    int left = -1, right = -1;
    if(min_index > 0)
        left = returnMaxArea(arr, l, min_index-1);

    if(min_index < arr.size()-1)
        right = returnMaxArea(arr, min_index+1, h);
    return max((h-l+1)*arr[min_index], max(left, right));
}

int main(int argc, char* argv[]) {
    int n = 7;
    vector<int>arr = {6, 4, 5, 4, 5, 1, 6};
    if(argc > 1) {
        arr.clear();
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
    cout<<"Array:"<<endl;
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl<<"Maximum area = "<<returnMaxArea(arr, 0, n-1)<<endl;
    return 0;
}