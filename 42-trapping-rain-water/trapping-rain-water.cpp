class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==1) return 0;
        vector<int> left(n,0), right(n,0);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1],height[i]);
            right[n-1-i] = max(right[n-i],height[n-1-i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += (min(left[i],right[i]) - height[i]);
        }
        return ans;
    }
};

static const bool Init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();