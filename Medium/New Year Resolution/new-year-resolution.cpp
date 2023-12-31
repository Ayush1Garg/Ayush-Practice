//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    bool helper(int n, int coins[], int i, int sum, vector<vector<int>> &dp){
        if(sum==2024 || ( sum && (sum%20==0 || sum%24==0) ) ) return true;
        if(i>=n || sum > 2024) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = helper(n,coins,i+1,sum + coins[i],dp) || helper(n,coins,i+1,sum,dp);
    }
    
    int isPossible(int n , int coins[]) 
    {
        int sum = 0;
        for(int i=0; i<n; i++) sum += coins[i];
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
        return helper(n,coins,0,0,dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends