//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long  f(int left, int right , int n , int arr[] , vector<vector<int>> &dp){
        if(left>right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        long long takeLeft = arr[left] + min(f(left+2,right,n,arr,dp),f(left+1,right-1,n,arr,dp));
        long long takeRight = arr[right] + min(f(left,right-2,n,arr,dp),f(left+1,right-1,n,arr,dp));
        return dp[left][right] =  max(takeLeft,takeRight);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,n,arr , dp);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends