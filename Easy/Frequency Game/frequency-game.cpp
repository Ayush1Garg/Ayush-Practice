//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int a[], int n) {
        // code here
        int maxi = INT_MIN;
        int mini = INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[a[i]]++;
        }
        for(int i=0; i<n; i++){
            mini = min(mini,mp[a[i]]);
        }
        for(int i=0; i<n; i++){
            if(mini == mp[a[i]]){
                maxi = max(maxi,a[i]);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends