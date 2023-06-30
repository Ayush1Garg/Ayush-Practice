//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int dp[25][200];
    int rec(int i, int x, int k, vector<int> a, int n){
        if(i==n){
            if(x==k){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][x]!=-1){
            return dp[i][x];
        }
        int ans = 0;
        int a1 = rec(i+1,x,k,a,n);
        int a2 = rec(i+1,x^a[i],k,a,n);
        ans = a1 + a2;
        dp[i][x] = ans;
        return ans;
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        memset(dp,-1,sizeof(dp));
        return rec(0,0,K,arr,N);
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends