//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) 
    {
        string common="";
        int min_len=INT_MAX;
        int min_indx=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i].length()<min_len)
            {
                min_len=arr[i].length();
                min_indx=i;//Finding the Minimum Length of the Strings
            }
        }
        bool found=false;
        string min_length_str=arr[min_indx];
        for(int i=0;i<min_len;i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(min_length_str[i]!=arr[j][i])//Comparring with the Entire
                {                               //First Characters of the Strings
                    found=false;
                    break;
                }
                else
                {
                    found=true;//Should be true for the entire strings
                }
            }
            if(found)
            {
                common+=min_length_str[i];
            }
            else
            {
                break;//No common Characters so we can wind up the Loop
            }
        }
        if(common=="")
        {
            return "-1";
        }
        return common;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends