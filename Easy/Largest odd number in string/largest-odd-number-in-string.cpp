//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        string temp = "";
        int ind = -1;
        for(int i=0; i<s.size(); i++){
            if((s[i]-'0')%2 !=0){
                ind = i;
            }
        }
        if(ind != -1){
            temp = temp + s.substr(0,ind+1);
        }
        return temp;
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

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends