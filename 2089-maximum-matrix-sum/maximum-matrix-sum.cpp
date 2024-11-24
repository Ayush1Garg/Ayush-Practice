class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        long long ans = 0;
        int mini = INT_MAX, count = 0;
        for(auto& row : matrix){
            for(auto& num : row){
                ans += abs(num);
                if(num<0) count++;
                mini = min(mini,abs(num));
            }
        }
        if(count%2==0) return ans;
        return ans - 2*mini;
    }
};