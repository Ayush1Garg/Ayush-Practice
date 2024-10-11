//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        int n = arr.size();
        // for(int i=0; i<n; i++){
        //     if(arr[i]==-1 || arr[i]== 2*n-1) continue;
        //     int ind = arr[i] % (n*2);
        //     arr[ind] += 2*n;
        // }
        // for(int i=0; i<n; i++){
        //     if(arr[i]<2*n-1) arr[i] = -1;
        //     else arr[i] = i;
        // }
        // return arr;
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++){
            if(arr[i]>=0) ans[arr[i]] = arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends