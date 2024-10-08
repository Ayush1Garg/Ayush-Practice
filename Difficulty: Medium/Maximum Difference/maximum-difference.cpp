//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        stack<int> s;
        vector<int> left(n,0);
        s.push(arr[0]);
        for(int i=1; i<n; i++){
            while(!s.empty() && s.top() >= arr[i]) s.pop();
            if(s.empty()) left[i] = 0;
            else left[i] = s.top();
            s.push(arr[i]);
        }
        while(!s.empty()) s.pop();
        int ans = left[n-1];
        s.push(arr[n-1]);
        for(int i = n-2; i>=0; i--){
            while(!s.empty() && s.top() >= arr[i]) s.pop();
            if(s.empty()) ans = max(ans,left[i]);
            else ans = max(ans,abs(left[i]-s.top()));
            s.push(arr[i]);
        }
        while(!s.empty()) s.pop();
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
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends