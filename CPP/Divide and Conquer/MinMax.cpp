// Find the minimum and the maximum in an array by doing minimum comparisons

#include<bits/stdc++.h>
using namespace std;

vector<int> returnMax(vector<int> arr, int& max_num, int& min_num, int l, int h, int& comparisons) {

    if(l == h)
        return {arr[l], arr[l]};

    if(h-l == 1) {
        if(arr[l] > arr[h])
            return {arr[l], arr[h]};
        else
            return {arr[h], arr[l]};
        comparisons++;
    }
    if(l < h) {
        int m = l + (h-l)/2;
        max_num = max(max(returnMax(arr, max_num, min_num, l, m, comparisons)[0], returnMax(arr, max_num, min_num, m+1, h, comparisons)[0]), max_num);
        min_num = min(min(returnMax(arr, max_num, min_num, l, m, comparisons)[1], returnMax(arr, max_num, min_num, m+1, h, comparisons)[1]), min_num);
        comparisons += 2;
    }

    return {max_num, min_num};
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
    int max_num = INT_MIN, min_num = INT_MAX, comparisons = 0;
    vector<int> result = returnMax(arr, max_num, min_num, 0, n-1, comparisons);
    
    cout<<"Maximum in the list = "<<result[0]<<endl;
    cout<<"Minumum in the list = "<<result[1]<<endl;
    cout<<"Comparisons = "<<comparisons<<endl;
    float stop = clock();
    float duration = ((double)(stop - start))/CLOCKS_PER_SEC;
    // duration *= 1e-6;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;

    cout<<endl;
}