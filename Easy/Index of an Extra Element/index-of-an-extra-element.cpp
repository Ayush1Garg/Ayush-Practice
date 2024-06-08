//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    int findExtra(int n, int arr1[], int arr2[]) {
        int l=0,h=n-2;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr1[mid]>=arr2[mid])
            l=mid+1;
            else
            h=mid-1;
        }
        return max(l,h);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends