//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int mod = 1000000007;
    int helper(int x, int y, vector<vector<int>> &dp ){
        if(x<0 || y<0) return 0;
        if(x==0 || y==0) return dp[x][y] = 1;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = ( helper(x,y-1,dp)%mod + helper(x-1,y,dp)%mod )%mod;
    }
    int ways(int x, int y)
    {
        //code here.
        if(x==0 && y==0) return 0;
        vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        dp[0][0] = 0;
        return helper(x,y,dp);
    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends