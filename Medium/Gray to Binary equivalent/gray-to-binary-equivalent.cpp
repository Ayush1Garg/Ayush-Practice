//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    vector<int> decToBinary(int n)
    {
        // array to store binary number
        int binaryNum[32];
        // counter for binary array
        int i = 0;
        while (n > 0) {
            // storing remainder in binary array
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        vector<int> ans;
        // printing binary array in reverse order
        for (int j = i - 1; j >= 0; j--)
            ans.push_back(binaryNum[j]);
        return ans;
    }
    int grayToBinary(int n)
    {
        // Your code here
        vector<int> code = decToBinary(n);
        for(int i=1; i<code.size(); i++){
            code[i] = code[i-1]^code[i];
        }
        int ans = 0, mul = 1, i= code.size()-1;
        while(i>=0){
            ans += mul*code[i];
            i--;
            mul = mul*2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends