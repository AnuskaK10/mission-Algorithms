#include<bits/stdc++.h>
using namespace std;

// * O(n^2) time O(n^2) space

// int coefficient(int n, int k) {
//     vector<vector<int>> coef;
//     coef.push_back({1});
//     for(int i = 1; i <= n;i++) {
//         vector<int> level;
//         for(int j = 0;j <= i;j++) {
//             level.push_back((j == i ? 0 : coef[i-1][j]) + (j-1 >= 0 ? coef[i-1][j-1] : 0));
//         }
//         coef.push_back(level);
//     }

//     return coef[n][k];
// }

// * O(n^2) time O(n) space

int coefficient(int n, int k) {
    vector<int> coef;
    coef.push_back(1);
    for(int i = 1; i <= n;i++) {
        vector<int> level;
        for(int j = 0;j <= i;j++) {
            level.push_back((j == i ? 0 : coef[j]) + (j-1 >= 0 ? coef[j-1] : 0));
        }
        coef = level;
    }

    return coef[k];
}

// * O(n) time O(1) space

// int coefficient(int n, int k) {
//     double res = 1;
//     for(int i = k;i >= 1;i--) {
//         res = res*(n-i+1)/i;
//     }

//     return (int)res;
// }


int main() {
    int n, k;

    cout<<"Enter the value of n:";
    cin>>n;

    cout<<"Enter the value of k:";
    cin>>k;

    double start = clock();
    cout<<"Binomial coefficient = "<<coefficient(n, k)<<endl;
    double stop = clock();
    double duration = ((double)(stop - start))/CLOCKS_PER_SEC;

    cout<<"Time taken = "<<duration<<" seconds"<<endl<<endl;
    return 0;
}