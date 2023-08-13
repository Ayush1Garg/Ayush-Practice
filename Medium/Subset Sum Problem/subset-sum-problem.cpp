//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int ind, int target,int n, vector<int> &arr,vector<vector<int>> &dp){
        if(target == 0) return dp[ind][target] =  true;
        if(ind == n-1){
            if(arr[ind] == target) return dp[ind][target] = true;
            else dp[ind][target] = false;
        } 
    
        if(dp[ind][target] != -1) return dp[ind][target];
        if(target >= arr[ind]){
        if(f(ind +1, target-arr[ind],n,arr ,dp)) return dp[ind][target] = true;
        }
        if(f(ind +1,target, n , arr,dp)) return dp[ind][target] = true;
        return dp[ind][target] =false;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
         vector<vector<int>> dp(n , vector<int> (sum+1,-1));
        return f(0,sum,n,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends