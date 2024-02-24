//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int solve(int n, vector<int> &dp){
            if(n==0) return 0;
            if(dp[n]!=-1) return dp[n];
            int a = max(n/2,solve(n/2,dp));
            int b = max(n/3,solve(n/3,dp));
            int c = max(n/4,solve(n/4,dp));
            return dp[n] = max(n,a+b+c);
        }
        int maxSum(int n)
        {
            //code here.
            vector<int> dp(n+1,-1);
            return solve(n,dp);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends