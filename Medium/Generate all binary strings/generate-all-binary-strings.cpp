//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateBinaryStrings(int num, int index = 0, string s = ""){
        //Write your code
        if(index==num){
            cout<<s<<" ";
            return;
        }
        s += '0';
        generateBinaryStrings(num,index+1,s);
        // s.pop_back();
        if(index==0 || s[index-1]=='0'){
            s[index] = '1';
            generateBinaryStrings(num,index+1,s);
            // s.pop_back();
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends