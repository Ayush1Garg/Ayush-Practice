//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int bs(int arr[], int low, int high, int x){
	    if(x<arr[low] || x>arr[high]) return 0;
	    int cnt = 0;
	    if(low>high) return 0;
	    if(low==high){
	        if(arr[low]==x) return 1;
	        return 0;
	    }
	    int mid = (high + low)/2;
	    if(arr[mid]==x){
	        return cnt = 1 + bs(arr,low,mid-1,x) + bs(arr,mid+1,high,x);
	    }
	    if(arr[mid]<x) 
	        return bs(arr,mid+1,high,x);
	    return bs(arr,low,mid-1,x);
	}
	int count(int arr[], int n, int x) {
	    // code here
	    if(n==0) return 0;
	    if(x<arr[0] || x>arr[n-1]) return 0;
	    return bs(arr,0,n-1,x);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends