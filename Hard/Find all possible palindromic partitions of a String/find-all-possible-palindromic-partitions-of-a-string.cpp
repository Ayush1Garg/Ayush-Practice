//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPal(string s, int i, int j,vector<vector<int>> dp){
        if(i==j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        int low = i, high = j;
        while(i<j){
            if(s[i++]!=s[j--]){
                dp[low][high] = 0;
                return dp[i][j] = false;
            }
        }
        return dp[low][high] = true;
    }
    void solve(int i, int n, string S, vector<string> &ds, vector<vector<string>> &ans, vector<vector<int>> &dp){
            if(i==n){
                ans.push_back(ds);
                return;
            }
            for(int j = i; j<n; j++){
                if(isPal(S,i,j,dp)){
                    ds.push_back(S.substr(i,j-i+1));
                    solve(j+1,n,S,ds,ans,dp);
                    ds.pop_back();
                }
            }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        int n = S.length();
        vector<vector<string>> ans;
        vector<string> ds;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        solve(0,n,S,ds,ans,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends