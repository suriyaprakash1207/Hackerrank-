#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    int max = 0;
    int pos = 0;
    
    for (int i = 0; i < k; i++) {
        if (arr[i] > max) {
            pos = i;
            max = arr[pos];
        }
    }
    
    cout << max;
                
    for (int j = k; j < n; j++) {
        if (j - k < pos) {
            if (arr[j] > max) {
                max = arr[j];
                pos = j;
            }
        } else {
            max = 0;
            for (int i = 1; i <= k; i++) {
                if (arr[j - k + i] > max) {
                    pos = j - k + i;
                    max = arr[pos];
                }
            }
        }

        cout << " " << max;
    }
    
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
