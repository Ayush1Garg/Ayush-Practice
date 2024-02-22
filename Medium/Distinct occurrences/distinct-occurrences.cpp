//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/
#define mod 1000000007
class Solution
{
    public:
    int solve(string &s, string &t, int i, int j, int n, int m, vector<vector<int>> &dp){
        if(j==m) return dp[i][j]=1;
        if(i==n) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0, noTake = 0;
        if(s[i]==t[j]){
            take = solve(s,t,i+1,j+1,n,m,dp)%mod;
        }
        noTake = solve(s,t,i+1,j,n,m,dp)%mod;
        return dp[i][j] = (take + noTake)%mod;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,0,0,n,m,dp);
      
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends