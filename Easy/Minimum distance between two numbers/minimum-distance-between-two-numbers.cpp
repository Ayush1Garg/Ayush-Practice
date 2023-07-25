//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        // code here
        int first_index=-1,second_index=-1;
        int diff;
        int ans=INT_MAX;
        
        if(x==y) return -1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x) first_index=i;
            if(arr[i]==y) second_index=i;
            if((first_index != -1) && (second_index !=-1))
            {
                if(first_index >= second_index) diff=first_index-second_index;
                else diff=second_index-first_index;
                ans=min(ans,diff);
            }
        }
        if((first_index == -1) || (second_index ==-1))
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends