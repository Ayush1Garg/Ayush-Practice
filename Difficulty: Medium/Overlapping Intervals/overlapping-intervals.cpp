//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        sort(begin(arr), end(arr), [&](vector<int> a, vector<int> b) {
            return (a[0]==b[0] ? a[1]<b[1] : a[0]<b[0]);
        });
        for(int i=0; i<n;) {
            int first = arr[i][0], second = arr[i][1];
            while(i<n && arr[i][0]<=second) {
                if(arr[i][1]>second)    second = arr[i][1];
                i++;
            }
            arr.push_back({first, second});
        }
        arr.erase(begin(arr), begin(arr)+n);
        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends