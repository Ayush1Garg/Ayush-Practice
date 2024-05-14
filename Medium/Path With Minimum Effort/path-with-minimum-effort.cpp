//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool isvalid(int r,int c,int n,int m){
        return (r >=0 and r< n and c >=0 and c< m);
    }
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        if(rows == 1 and columns == 1){
            return 0;
        }
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        // queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> val(rows,vector<int>(columns,1e9));
        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int cost = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i =0;i< 4;i++){
                int x = r + dx[i];
                int y = c + dy[i];
                if(isvalid(x,y,rows,columns)){
                    int newcost = max(cost,abs(heights[x][y] - heights[r][c]));
                    if(newcost < val[x][y]){
                        val[x][y] =newcost;
                        pq.push({newcost,{x,y}});
                    }
                }
            }
        }
        return val[rows -1][columns -1];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends