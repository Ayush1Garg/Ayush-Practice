//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101] ; 
    int dfs(int ind, int m, int n,int prev) {
        if(ind==n) return 1;
        if(dp[ind][prev]!=-1) return dp[ind][prev]; 
        int i=max(1,2*prev) ;
        int ans=0; 
        for(int j=i; j<=m; j++) {
            ans=(ans+dfs(ind+1,m,n, j)) ;
        }
        return dp[ind][prev]= ans; 
     }
    int numberSequence(int m, int n){
        memset(dp,-1,sizeof(dp)); 
        return dfs(0,m,n,0) ; 
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends