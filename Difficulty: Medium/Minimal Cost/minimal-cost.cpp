//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> cost(n,INT_MAX);
        cost[0] = 0;
        // cout<<cost[0]<<" ";
        for(int i=1; i<n; i++){
            int j = i-1;
            while(j>=0 && j>=i-k){ 
                cost[i] = min(cost[i], cost[j] + abs(arr[i]-arr[j]));
                j--;
            }
            // cout<<cost[i]<<" ";
        }
        // cout<<endl;
        return cost[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends