//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        int x = 0;
        for(int i : arr)
            x ^= i;
        if(x != 0)
            return 0;
        
        long long a = pow(2, arr.size()-1) - 1;
        long long mod = pow(10, 9)+7;
        
        return a%mod;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends