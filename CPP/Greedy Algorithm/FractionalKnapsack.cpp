#include<bits/stdc++.h>
using namespace std;

void pairSort(vector<int>& weight, vector<int>& value, vector<double>& value_per_unit, int n) {
    pair<int, int> pair_weight[n], pair_value[n];

    for(int i = 0;i < n;i++) {
        pair_weight[i].first = value_per_unit[i];
        pair_value[i].first = value_per_unit[i];

        pair_weight[i].second = weight[i];
        pair_value[i].second = value[i];
    }

    sort(pair_weight, pair_weight+n);
    sort(pair_value, pair_value+n);

    reverse(pair_weight, pair_weight+n);
    reverse(pair_value, pair_value+n);

    for(int i = 0;i < n;i++) {
        weight[i] = pair_weight[i].second;
        value[i] = pair_value[i].second;
        value_per_unit[i] = pair_value[i].first;
    }
}

int returnMaxProfit(vector<int> weight, vector<int> value, int n, int W) {
    vector<double> value_per_unit;
    for(int i = 0;i < n;i++) {
        value_per_unit.push_back(value[i]/weight[i]);
    }

    pairSort(weight, value, value_per_unit, n);

    int i = 0;
    double profit = 0;
    while(W > 0) {
        if(W <= weight[i]) {
            profit += (W*value_per_unit[i]);
            W = 0;
            break;
        }
        else {
            profit += (value[i]);
            W -= weight[i];
        }
        i++;
    }
    return profit;
}

int main() {
    int W, n;
    vector<int>weight, value;
    cout<<"Enter size of knapsack:";
    cin>>W;
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter weight of "<<n<<" items:\n";
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        weight.push_back(x);
    }
    cout<<"Enter value of "<<n<<" items:\n";
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        value.push_back(x);
    }

    cout<<"Solution = "<<returnMaxProfit(weight, value, n, W)<<endl;
    return 0;

}