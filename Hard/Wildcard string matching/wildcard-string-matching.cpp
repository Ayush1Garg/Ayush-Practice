//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool check(string &wild, string &pattern, int i, int j, int n, int m, vector<vector<int>> &dp){
        if( j == m ){
            if(i==n || ( i == n-1 && wild[i]=='*') ) return true;
            return false;
        }
        if(i==n) return dp[i][j] = false;
        if(i > n || j > m) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(wild[i]=='?' || wild[i]==pattern[j]) return dp[i][j] = check(wild,pattern,i+1,j+1,n,m,dp);
        if(wild[i] != '*') return dp[i][j] = false;
        return dp[i][j] = check(wild,pattern,i,j+1,n,m,dp) || check(wild,pattern,i+1,j,n,m,dp);
    }
    
    bool match(string wild, string pattern){
        // code here
        string change = "";
        int i=0;
        while(wild[i] != '\0'){
            if(wild[i]=='*'){
                while(wild[i]=='*') i++;
                change += '*';
                i--;
            }
            else change += wild[i];
            i++;
        }
        int n = change.length(), m = pattern.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return check(change,pattern,0,0,n,m,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends