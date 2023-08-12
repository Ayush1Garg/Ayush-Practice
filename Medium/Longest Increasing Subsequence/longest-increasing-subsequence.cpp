//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int maxi = 1;
        vector<int> dp;
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), a[i]);
            if (it == dp.end())
            {
                dp.emplace_back(a[i]);
            }
            else
            {
                int ind = it - dp.begin();
                dp.at(ind) = a[i];
            }
            maxi = max(maxi, (int)dp.size());
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends