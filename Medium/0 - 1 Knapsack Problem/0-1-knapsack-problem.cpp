//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solver(int ind,int W, int wt[], int val[],vector<vector<int>> &dp){
        
        if(ind==0){
            if(W>=wt[ind]){
                return val[ind];
            }
            return 0;
        }
        
        if(dp[ind][W]!=-1){
            return dp[ind][W];
        }
        
        int take = INT_MIN;
        
        if(W>=wt[ind]){
            take = val[ind] + solver(ind-1,W-wt[ind],wt,val,dp);
        }
        int nottake = solver(ind-1,W,wt,val,dp);
        return dp[ind][W] = max(nottake,take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
       return solver(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends