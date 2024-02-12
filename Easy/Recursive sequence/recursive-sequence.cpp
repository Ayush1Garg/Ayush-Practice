//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long mod = 1e9 + 7;
    long long sequence(int n){
        // code here
        // unsigned long long ans = 0, x;
        // for(int i=1; i<=n; i++){
        //     x = sum(1,i-1,1) + 1;
        //     ans += prod(x,n);
        //     // cout<<x<<" ";
        //     ans%mod;
        // }
        // return ans;
        
        unsigned long long val = 0, num = 1, step = 1;
        while(step<=n){
            unsigned long long temp = 1;
            for(int i=0; i<step; i++){
                temp = temp*num;
                temp = temp%mod;
                num++;
            }
            val += temp;
            val = val%mod;
            step++;
        }
        return val;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends