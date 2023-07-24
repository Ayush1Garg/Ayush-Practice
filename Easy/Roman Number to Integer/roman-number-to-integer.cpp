//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

int rtiv(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        return -1;
    }
}

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int i=0, ans=0;
        while(i<str.length()){
            if( i<str.length()-1 && rtiv(str[i])<rtiv(str[i+1])){
                ans += rtiv(str[i+1]) - rtiv(str[i]);
                i += 2;
            }
            else{
                ans += rtiv(str[i]);
                i++;
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
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends