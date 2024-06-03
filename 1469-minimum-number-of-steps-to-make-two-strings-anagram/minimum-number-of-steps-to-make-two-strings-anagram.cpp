class Solution {
public:
    int minSteps(std::string s, std::string t) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int count[26] = {0};
        for (char ch : s) {
            count[ch - 'a']++;
        }
        for (char ch : t) {
            count[ch - 'a']--;
        }
        int steps = 0;
        for (int i = 0; i < 26; i++) {
            steps += abs(count[i]);
        }

        return steps / 2;  
    }
};