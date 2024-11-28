//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long ll;

class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        ll  digit  = 0 ;
        int i =0 ;
        int sign = 1;
        while( s[i] ==' '){
            i++;
        }
        if( s[i]=='-'|| s[i]=='+'){
            sign = (s[i]=='-')? -1 : 1;
            i++;
        }
        while( s[i]>='0'&&s[i]<='9'){
            int num = s[i]-'0';
            digit = digit*10+num ;
            if( sign >0 && digit >= INT_MAX ) return INT_MAX;
            if( sign<0 && -digit <= INT_MIN ) return INT_MIN;
            i++ ;
        }
        return  sign*digit;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends