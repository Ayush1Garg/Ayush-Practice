//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        int res =0;
        double val[n];
        unordered_map<double,int> mp;
        for(int i=0; i<n; i++){
            val[i] = 1.0*numerator[i]/denominator[i];
            mp[val[i]]++;
            // cout<<mp[1-val[i]]<<endl;
        }
       // cout<<endl;
        for(int i=0; i<n; i++){
        double a=double(denominator[i]-numerator[i])/double(denominator[i]);//            cout<<val[i]<<" "<<mp[val[i]]<<" "<<a<<" "<<mp[a]<<endl;
            mp[val[i]]--;
            res += mp[a];
            // cout<<val[i]<<" "<<mp[1-val[i]]<<endl;
        }
        return res;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends