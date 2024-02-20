//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool solve(int i, int n, string A,unordered_map<string,int> &mp, vector<int> &dp){
        if(i>n-1) return true;
        if(dp[i]!=-1) return dp[i];
        for(int in = i; in<n; in++){
            if( mp.find( A.substr(i,in-i+1) )!=mp.end() ){
                if( solve(in+1,n,A,mp,dp) ) return dp[i]=true;
            }
        }
        return dp[i] = false;
    }
    int wordBreak(int n, string A, vector<string> &B) {
        //code here
        unordered_map<string,int> mp;
        for(int i=0; i<n; i++){
            mp[B[i]]++;
        }
        int m = A.length();
        vector<int> dp(m,-1);
        return solve(0,m,A,mp,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends