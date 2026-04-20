#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
     int n =0;
    int x =0;
    vector<int>vek;
    cin>>n;
    while (n > 0) {
        cin>>x;
        vek.push_back(x);
        n--;
    }
    int q=0;
    cin>>q;
    while (q > 0) {
        int y =0;
        vector<int>::iterator it;
        cin>>y;
        it = lower_bound(vek.begin(),vek.end(), y);
        if (*it!=y) {
            cout<<"No "<<(it-vek.begin()+1)<<'\n';
        }else
        {cout<<"Yes "<<(it-vek.begin()+1)<<'\n';}
        q--;
    }
    return 0;
}
