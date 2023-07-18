//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string res = "";
        int p =0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                p++;
                if(p!=1){
                    res = res + s[i];
                }
            }
            else{
                p--;
                if(p!=0){
                    res = res + s[i];
                }
            }
        }
        return res;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends