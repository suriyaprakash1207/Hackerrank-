#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size;
cin>>size;

vector <int> arr(size);

for(int &num : arr){
    cin>>num;
}

sort(arr.begin(),arr.end());

for(int sort : arr){
    cout<<sort<<" ";
}
    return 0;
}
