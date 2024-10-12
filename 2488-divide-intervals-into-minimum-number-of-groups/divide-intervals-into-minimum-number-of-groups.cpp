vector<int> bucket[128]; 
void radix_sort(vector<int>& nums) {
    // 1st round
    for (int& x : nums) {
        bucket[x & 127].push_back(x);
    }
    int i = 0;
    for (auto& B : bucket) {
        for (auto v : B)
            nums[i++] = v;
        B.clear();
    }
    // 2nd round
    for (int& x : nums)
        bucket[(x >> 7) & 127].push_back(x);
    i = 0;
    for (auto& B : bucket) {
        for (auto v : B)
            nums[i++] = v;
        B.clear();
    }
    // 3rd round
    for (int& x : nums)
        bucket[x >> 14].push_back(x);
    i = 0;
    for (auto& B : bucket) {
        for (auto v : B) 
            nums[i++] = v ;
            B.clear();
    }
}
class Solution {
public:
    static int minGroups(vector<vector<int>>& intervals) {
        const int n=intervals.size();
        vector<int> P;
        P.reserve(n*2);
        for(auto& I: intervals){
            int x=I[0], y=I[1]+1;
            P.push_back((x<<1)+1);
            P.push_back(y<<1);
        }
        radix_sort(P);
        int cnt=0, x=0;
        for(int z: P){
            x+=(z&1)?1:-1;
            cnt=max(cnt, x);
        }
        
        return cnt;    
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();