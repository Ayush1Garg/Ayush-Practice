//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        int num = str[n-1] - '0';
        if(num<6){
            str[n-1] = '0';
            return str;
        }
        str[n-1] = '0';
        int carry = 1, i = n-2;
        while(i>=0 && carry>0){
            if(str[i]=='9'){
                str[i] = '0';
                i--;
            }
            else{
                str[i]++;
                carry--;
            }
        }
        if(i==-1 && carry>0){
            str = "1" + str;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends