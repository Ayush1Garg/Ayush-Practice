class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26, INT_MAX);
        vector<string> res;
        for (const auto& w : words) {
            vector<int> counts(26, 0);
            for (const auto& c : w) {
                counts[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                count[i] = min(count[i], counts[i]);
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i]; j++) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};