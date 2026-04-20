#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
     int q; cin >> q;

map<string,int> m;

while(q--) {
    int y;
    string x;
    cin >> y >> x;

    if (y == 1) {
        int marks;
        cin >> marks;
        m[x] += marks;
    }
    else if (y == 2) {
        m.erase(x);
    }
    else if (y == 3) {
        cout << m[x] << endl;
    }
}  
    return 0;
}



