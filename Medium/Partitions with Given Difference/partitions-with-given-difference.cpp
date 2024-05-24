//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
    int rec(int n, vector<int>&arr, vector<vector<int>>&dp,int s1){
        if(n==0){
            return s1==0;
        }
        if(dp[s1][n]!=-1){
            return dp[s1][n];
        }
        // take
        int take=0;
        if(s1>=arr[n-1]){
            take=rec(n-1,arr,dp,s1-arr[n-1])%mod;
        }
        
        // not take
        int nottake=rec(n-1,arr,dp,s1)%mod;
        
        return dp[s1][n]=(take+nottake)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if((sum+d)%2==1){
            return 0;
        }
        int s1=(sum+d)/2;
        s1%=mod;
        vector<vector<int>>dp(s1+1,vector<int>(n+1,-1));
        return rec(n,arr,dp,s1)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends