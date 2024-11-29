//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int i = 0, n = s1.size();
        while(i<n && s1[i]=='0') i++;
        s1 = s1.substr(i,n-i);
        n = s2.size(); i = 0;
        while(i<n && s2[i]=='0') i++;
        s2 = s2.substr(i, n-i);
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int carry = 0, m = s2.size(); n = s1.size(); i = 0;
        string ans = "";
        while(i<n && i<m){
            ans += ( (s1[i] + s2[i] - 2*'0' + carry)%2  + '0');
            carry = (s1[i] + s2[i] - 2*'0' + carry)/2;
            i++;
        }
        while(i<n){
            ans += ( (s1[i] - '0' + carry)%2  + '0');
            carry = (s1[i] - '0' + carry)/2;
            i++;
        }
        while(i<m){
            ans += ( (s2[i] - '0' + carry)%2  + '0');
            carry = (s2[i] - '0' + carry)/2;
            i++;
        }
        if(carry){
            ans += '1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends