//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &arr) {
        // code here
        int n = arr.size();
        int l =0,r = 0;
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]] = 0;
        }
        int maxlen = 0;
        while(r<n){
            if(mpp[arr[r]]>0){
                mpp[arr[l]]--;
                l++;
            }
            else{
                mpp[arr[r]]++;
                maxlen = max(r-l+1,maxlen);
                r++;
            }
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends