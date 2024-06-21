//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        int c=0;
        int a=0,b=0,e=0,d=0;
        for(auto i:str)
        {
            if(i==' '||i=='/'||i==',')
            c++;
            else if(c==0)
            {
                a=a*10+(i-'0');
            }
            else if(c==1)
            {
                b=b*10+(i-'0');
            }
            else if(c==3)
            {
                e=e*10+(i-'0');
            }
            else if(c==4)
            {
                d=d*10+(i-'0');
            }
        }
        // cout<<a<<"/"<<b<<"?"<<d<<"/"<<e<<endl;
        if(a/(b*1.0)==(e*1.0)/d)
        return "equal";
        return a/(b*1.0)>(e*1.0)/d?(""+to_string(a)+"/"+to_string(b)):(""+to_string(e)+"/"+to_string(d));
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends