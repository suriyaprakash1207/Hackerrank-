#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d) 
{ int ans = a;

if (b > ans)
    ans = b;
if (c > ans)
    ans = c;
if (d > ans)
    ans = d;

return ans;

}

int main() { int a, b, c, d; cin >> a >> b >> c >> d;

int ans = max_of_four(a, b, c, d);
cout << ans;

return 0;

}
