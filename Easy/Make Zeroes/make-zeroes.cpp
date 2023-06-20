//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        vector<int> temp;
        vector<vector<int>> t;
        for(int i=0; i<matrix[0].size()+2; i++){
            temp.push_back(0);
        }
        t.push_back(temp);
        temp.clear();
        for(int i=0; i<matrix.size(); i++){
            temp.push_back(0);
            for(int j=0; j<matrix[i].size(); j++){
                temp.push_back(matrix[i][j]);
            }
            temp.push_back(0);
            t.push_back(temp);
            temp.clear();
        }
        for(int i=0; i<matrix[0].size()+2; i++){
            temp.push_back(0);
        }
        t.push_back(temp);
        temp.clear();
        vector<vector<int>> t1 = t;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]==0){
                    t[i+1][j+1] = t1[i][j+1] + t1[i+1][j] + t1[i+2][j+1] + t1[i+1][j+2];
                    t[i][j+1] = 0;
                    t[i+1][j] = 0;
                    t[i+2][j+1] = 0;
                    t[i+1][j+2] = 0;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                matrix[i][j] = t[i+1][j+1];
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends