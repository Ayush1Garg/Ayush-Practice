class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = arr.size();
        int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            sortedPrefixSum += i;
            if (prefixSum == sortedPrefixSum) {
                chunks++;
            }
        }
        return chunks;
    }
};