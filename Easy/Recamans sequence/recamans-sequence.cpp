//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(vector<int>& v, int n, unordered_map<int,int>& mp, int i){
        if(i>=n){
            return;
        }
        int c = (i+1);
        if( (v[i]-c)>0 && mp.find(v[i]-c)==mp.end()){
            v.push_back(v[i]-c);
            mp[v[i]-c]++;
        }
        else{
            v.push_back(v[i]+c);
            mp[v[i]+c]++;
        }
        solve(v,n,mp,i+1);
    }

    vector<int> recamanSequence(int n){
        // code here
        vector<int> v;
        v.push_back(0);
        unordered_map<int,int> mp;
        mp[0]++;
        solve(v,n,mp,0);
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends