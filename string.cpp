#include <iostream>
#include <string>
using namespace std;

int main() {
     string a;
  cin >> a;
  
  string b;
  cin >> b;
  
  cout << a.size() << " " << b.size() << endl;
  cout << a + b << endl;
  
  swap(a[0], b[0]);
  cout << a << " " << b << endl;
  
	// Complete the program
  
    return 0;
}
