//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int help(int i, int j, int &n, int &m, string &pattern, string &str, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(i>=n){
            while(j<m && str[j]=='*') j++;
            if(j>=m) return 1;
            return 0;
        }
        if(j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(pattern[i]==str[j] || str[j]=='?'){
            return dp[i][j] = help(i+1,j+1,n,m,pattern,str,dp);
        }
        if(str[j]=='*'){
            int noTake = help(i,j+1,n,m,pattern,str,dp);
            if(noTake==1) return dp[i][j] = 1;
            int cont = help(i+1,j,n,m,pattern,str,dp);
            if(cont==1) return dp[i][j] = 1;
            int end = help(i+1,j+1,n,m,pattern,str,dp);
            return dp[i][j] = end;
        }
        return dp[i][j] = 0;
        
    }
    /*You are required to complete this method*/
    int wildCard(string str, string pattern) {
        // code here
        int n = pattern.size(), m = str.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return help(0,0,n,m,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends