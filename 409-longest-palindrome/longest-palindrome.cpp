class Solution {
public:
    int longestPalindrome(const string& s) {
        int lower = 0, upper = 0;
        for (auto ch : s) {
            lower ^= ch >= 'a' ? 1 << ch - 'a' : 0;
            upper ^= ch < 'a' ? 1 << ch - 'A' : 0;
        }
        int c = __builtin_popcount(lower) + __builtin_popcount(upper);
        return s.length() - c + (c != 0);
    }
};