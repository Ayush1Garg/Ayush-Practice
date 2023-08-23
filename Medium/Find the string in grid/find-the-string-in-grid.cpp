//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool checker(int i, int j, int n, int m, int k, vector<vector<char>> &grid, string &word, int h, int v, int len){
        if(k+1>=len) return true;
        if(i+v>=n || j+h>=m || i+v<0 || j+h<0 || grid[i+v][j+h]!=word[k+1]) return false;
        if(k+1==(len-1)) return true;
        return checker(i+v,j+h,n,m,k+1,grid,word,h,v,len);
    }

    bool check(int i, int j, int n, int m, int k, vector<vector<char>> &grid, string &word, int len){
        if(checker(i,j,n,m,k,grid,word,1,0,len) || checker(i,j,n,m,k,grid,word,-1,0,len) || checker(i,j,n,m,k,grid,word,0,-1,len) || checker(i,j,n,m,k,grid,word,0,1,len)) return true;
        if(checker(i,j,n,m,k,grid,word,-1,-1,len) || checker(i,j,n,m,k,grid,word,-1,1,len) || checker(i,j,n,m,k,grid,word,1,-1,len) || checker(i,j,n,m,k,grid,word,1,1,len)) return true;
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    int n = grid.size(), m = grid[0].size();
	    int len = word.length();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==word[0]){
	                if(check(i,j,n,m,0,grid,word,len)) ans.push_back({i,j});
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends