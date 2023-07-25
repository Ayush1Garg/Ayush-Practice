//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        //Code here
        int ans = -1;
        unordered_map<int,bool> mp;
        for(int i=0; i<n; i++){
            if(mp[arr[i]]==false){
                int j = n-1;
                while(arr[j] != arr[i]){ j--; }
                ans = max(ans,j-i);
                mp[arr[i]]=true;
            }
        }
        return ans;
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
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends