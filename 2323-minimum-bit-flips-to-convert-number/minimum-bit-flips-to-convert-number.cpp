class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int x = start ^ goal;
        return __builtin_popcount(x);
    }
};