//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            int n = price.size();
            vector<int> mx(n, 0);
            int ans = 0;
            for (int k = 0; k < 4; ++k) {
                int last = mx[k];
                mx[k] = (k ? mx[k-1] : 0) + (k&1 ? price[k] : -price[k]);
                for (int i = k+1; i < n; ++i) {
                    int tmp = last + (k&1 ? price[i] : -price[i]);
                    last = mx[i];
                    mx[i] = max(tmp, mx[i-1]); 
                }
                ans = max(mx[n-1], ans);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends