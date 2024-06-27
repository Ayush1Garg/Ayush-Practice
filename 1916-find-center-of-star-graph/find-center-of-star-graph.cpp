class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int v1 = edges[0][0], v2 = edges[0][1];
        if(v1==edges[1][0] || v1==edges[1][1]) return v1;
        return v2; 
    }
};