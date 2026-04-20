#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    set<int> drawer;
    int count; cin >> count;
    
    for (int x = 0, query, value; x < count; x++)
    {
        cin >> query >> value;
        switch (query)
        {
            case 1:
            {
                drawer.insert(value);
                break;
            }
            case 2:
            {
                if (drawer.find(value) == drawer.end()) break;
                else drawer.erase(value);
                
                break;
            }
            case 3:
            {
                if (drawer.find(value) != drawer.end()) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
            default: {}
        }
    }
    return 0;
}



