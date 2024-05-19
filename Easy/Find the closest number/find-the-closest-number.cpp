//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        if(k<=arr[0]) return arr[0];
        if(k>=arr[n-1]) return arr[n-1];
        int i = lower_bound(arr, arr + n, k) - arr;
        if(i==0) return arr[0];
        if(i==n) return arr[n-1];
        if(arr[i]-k <= k-arr[i-1]) return arr[i];
        return arr[i-1];
        
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends