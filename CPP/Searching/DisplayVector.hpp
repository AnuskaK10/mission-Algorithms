#ifndef _DisplayVector_hpp
#define _DisplayVector_hpp
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

void displayVector(vector<int> arr, int n) {
    ofstream fout;
    fout.open("output.txt");
    for(int i = 0;i < n;i++) {
        fout<<arr[i]<<" ";
    }
    fout<<endl;
    fout.close();
    cout<<"Output stored in output.txt"<<endl;
}


#endif