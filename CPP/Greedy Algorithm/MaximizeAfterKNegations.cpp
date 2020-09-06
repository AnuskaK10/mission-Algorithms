#include<bits/stdc++.h>
using namespace std;

int returnSum(vector<int> arr, int n, int K) {
    int sum = 0;
    for(int i = 0;i < n;i++)
        sum += arr[i];

    while(K--) {
        sort(arr.begin(), arr.end());
        sum -= arr[0];
        arr[0] = -arr[0];
        sum += arr[0];
    }

    return sum;
}

int main(int argc, char* argv[]) {
    vector<int> arr;
    int n, K;

    if(argc == 1) {
        cout<<"Enter the size of the array:";
        cin>>n;
        cout<<"Enter "<<n<<" elements:"<<endl;
        for(int i = 0;i < n;i++) {
            int inp;
            cin>>inp;
            arr.push_back(inp);
        }

        cout<<"Enter the number of negations:";
        cin>>K;
    }

    else {
        ifstream fin(argv[1]);
        string inp;
        fin>>inp;
        n = stoi(inp);

        for(int i = 0;i < n;i++) {
            fin>>inp;
            arr.push_back(stoi(inp));
        }

        fin>>inp;
        K = stoi(inp);
    }

    cout<<"Sum after "<<K<<" negations = "<<returnSum(arr, n, K)<<endl;

    return 0;
}