//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            if(mp[arr[i]]==0){
                mp[arr[i]]=-1;
                continue;
            }
            if(mp[arr[i]]>n/k){
                cnt++;
                mp[arr[i]]=-1;
            }
        }
        return cnt;
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

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends