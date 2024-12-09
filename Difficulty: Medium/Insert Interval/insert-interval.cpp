//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        // add the new interval and sort the array of intervals acc to start.
        intervals.push_back({newInterval[0], newInterval[1]});
        sort(intervals.begin(), intervals.end());
        
        // now apply the logic of merging overlapping intervals
        int n = intervals.size();
        int prev = 0;
        for(int i=1 ; i<n ; i++) {
            if(intervals[i][0] <= intervals[prev][1]) {
                intervals[prev][0] = min(intervals[prev][0], intervals[i][0]);
                intervals[prev][1] = max(intervals[prev][1], intervals[i][1]);
            } else {
                prev++;
                intervals[prev][0] = intervals[i][0];
                intervals[prev][1] = intervals[i][1];
            }
        }
        for(int i=n-1 ; i>prev ; i--) {
            intervals.pop_back();
        }
        return intervals;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends