//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int s) {
	    // code here
	    vector<int> p;
	    vector<int> n;
	    for(int i=0; i<s; i++){
	        if(arr[i]<0){
	            n.push_back(arr[i]);
	        }
	        else{
	            p.push_back(arr[i]);
	        }
	    }
	    int i=0, j=0;
	    while(i<p.size() && j<n.size()){
	        if(i>j){
	            arr[i+j] = n[j];
	            j++;
	        }
	        else{
	            arr[i+j] = p[i];
	            i++;
	        }
	    }
	    while(i<p.size()){
	        arr[i+j] = p[i];
	        i++;
	    }
	    while(j<n.size()){
	        arr[i+j] = n[j];
	        j++;
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends