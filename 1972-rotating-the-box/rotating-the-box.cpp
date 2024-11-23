class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(box[i][j]=='#') count++;
                else if(box[i][j]=='*'){
                    ans[j][n-1-i] = '*';
                    int r = j-1;
                    while(count>0){
                        ans[r][n-1-i] = '#';
                        count--;
                        r--;
                    }
                }
            }
            int j = m-1;
            while(count>0){
                ans[j][n-1-i] = '#';
                count--;
                j--;
            }
        }
        return ans;
    }
};