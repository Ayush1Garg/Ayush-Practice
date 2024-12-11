class Solution {
public:
    static int maximumBeauty(vector<int>& nums, int k) {
        const auto [xMin, xMax]=minmax_element(nums.begin(), nums.end());
        const int a=*xMin, N=*xMax-a;
        vector<int> inc(N+2, 0);
        for(int x: nums){
            const int xL=max(x-k-a, 0), xR=min(N+1, x+k+1-a);
            inc[xL]++;
            inc[xR]--;
        }
        int cnt=0, maxCnt=0;
        for(int y=0; y<=N+1; y++){
            cnt+=inc[y];
            maxCnt=max(maxCnt, cnt);
        }
        return maxCnt;
    }
};