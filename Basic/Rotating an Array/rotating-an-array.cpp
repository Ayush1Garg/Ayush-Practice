//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void leftRotate(int arr[], int n, int k) {
        // code here
	   int a[k];
	   for(int i=0; i<k; i++){
	       a[i] = arr[i]; 
	   }
	   int i;
	   for(i=k; i<n; i++){
	       arr[i-k] = arr[i];
	   }
	   i = n-k;
	   while(i<n){
	       arr[i] = a[i-n+k];
	       i++;
	   }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends