//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        int n = arr.size();
        unordered_map<int,int> freq;
        for(int i=0; i<k; i++){
            freq[arr[i]]++;
        }
        for(int i=0; i<n; i++){
            if(i+k<n){
                freq[arr[i+k]]++;
            }
            // if(i-k>=0){
            //     freq[arr[i-k]]--;
            // }
            if(freq[arr[i]]>1) return true;
            freq[arr[i]]--;
        }
        return false;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends