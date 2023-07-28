//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beauty(int a[],int n){
        int mini = n, maxi = 0;
        for(int i=0; i<26; i++){
            if(a[i]>0){
                mini = min(mini,a[i]);
                maxi = max(maxi,a[i]);
            }
        }
        return (maxi-mini);
    }
    
    int beautySum(string s) {
        // Your code g<oes heres
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++){
            int freq[26] = {0};
            for(int j=i; j<n; j++){
                freq[s[j]-'a']++;
                ans += beauty(freq,n);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends