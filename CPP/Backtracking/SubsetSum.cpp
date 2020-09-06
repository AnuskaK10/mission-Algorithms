#include<bits/stdc++.h>
using namespace std;

void returnSubsets(vector<int> arr, int sum_till_now, int sum, int index, int n, vector<int> subset, vector<vector<int>>& res, map<vector<int>, bool>& m) {
    
    if((sum_till_now == sum) && m.count(subset) == 0) {
        res.push_back(subset);
        m[subset] = true;
    }

    if(index >= n)
        return;

    // Not including the current index

    returnSubsets(arr, sum_till_now, sum, index+1, n, subset, res, m);

    // Including the current index

    subset.push_back(arr[index]);
    sort(subset.begin(), subset.end());
    returnSubsets(arr, sum_till_now+arr[index], sum, index+1, n, subset, res, m);
}


int main(int argc, char* argv[]) {

    vector<vector<int>> res;
    map<vector<int>, bool> m;
    
    int n, sum;
    vector<int>arr;
    if(argc == 1){
        cout<<"Enter the size of the array:";
        cin>>n;
        cout<<"Enter "<<n<<" elements:\n";
        for(int i=0;i < n;i++) {
            int inp;
            cin>>inp;
            arr.push_back(inp);
        }
        cout<<"Enter the sum:";
        cin>>sum;
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

            fin>>str;
            sum = stoi(str);

            fin.close();
        }

    cout<<"Array:"<<endl;
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl<<"Sum: "<<sum<<endl;

    returnSubsets(arr, 0, sum, 0, n, {}, res, m);
    
    cout<<"Subsets with sum of "<<sum<<": "<<res.size()<<endl;
    for(int i = 0;i < res.size();i++) {
        for(int j = 0;j < res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}