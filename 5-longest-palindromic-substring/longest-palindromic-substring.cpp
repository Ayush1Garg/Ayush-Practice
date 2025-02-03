class Solution {
public:
    int start = 0, length = 1;
    void expand(int i, int j, string s) {
        int left = i;
        int right = j;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        if(left<=right && right - left - 1 > length){
            length = right - left - 1;
            start = left+1;
        }
    }
    string longestPalindrome(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        for (int i = 0; i < s.size(); i++) {
            expand(i, i, s);
            expand(i, i + 1, s);
        }
        return s.substr(start,length);
    }
};