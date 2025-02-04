class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==1 || m==1) return 1;
        vector<unsigned long int> prev(n,0);
        prev[0] = 1;
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                prev[j] = prev[j-1] + prev[j];
            }
        }
        return prev[n-1];
    }
};