//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        reverse(s.begin(),s.end());
        int c = 1;
        for(int i=0; i<s.length(); i++){
            if(c==0) break;
            if(s[i]=='1'){
                s[i] = '0';
                c = 1;
            }
            else if(s[i]=='0'){
                s[i] = '1';
                c = 0;
            }
        }
        if(c==1){
            s = s + '1';
        }
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.length() && s[i]=='0') i++;
        return s.substr(i,s.length()-i);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends