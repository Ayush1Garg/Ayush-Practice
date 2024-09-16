//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string str) {
        // code here
        int n = str.size();
        stack<int> s;
        s.push(-1);
        for(int i=0; i<n; i++){
            if(str[i]=='(') s.push(i);
            if(str[i]==')'){
                if(s.top()==-1 || str[s.top()]!='(') s.push(i);
                else s.pop();
            }
        }
        int top = n, ans = 0;
        while(!s.empty()){
            ans = max(ans,top-s.top()-1);
            top = s.top();
            s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends