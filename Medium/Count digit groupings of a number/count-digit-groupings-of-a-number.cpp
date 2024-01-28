//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int i , int sum , string &s , vector<vector<int>> &dp){
	    if(i==s.length())
	    return 1;
	    if(dp[i][sum]!=-1)
	    return dp[i][sum];
	    int x = 0 ,ans = 0;
	    for(int j = i ; j<s.length() ; j++){
	        x += (s[j] - '0');
	        if(x >= sum){
	            ans += solve(j+1 , x , s,dp);
	        }
	    }
	    return dp[i][sum] = ans;
	}
	int TotalCount(string str){
	    int n = str.length() ; 
	    vector<vector<int>> dp(n , vector<int>(901 , -1));
	    return solve(0 , 0 , str , dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends