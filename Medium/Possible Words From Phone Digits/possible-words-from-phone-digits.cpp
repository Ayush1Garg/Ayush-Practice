//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int i, int n, int a[], string s, vector<string> &ans, unordered_map<int,string> mp){
        if(i==n){
            ans.push_back(s);
            return;
        }
        for(int ind=0; ind<mp[a[i]].length(); ind++){
            solve(i+1,n,a,s + mp[a[i]][ind],ans,mp);
        }
    }
    
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        vector<string> ans;
        string s = "";
        unordered_map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        solve(0,n,a,s,ans,mp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends