class Solution {
public:
    int maximumBeauty(vector<int>& A, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        sort(A.begin(), A.end());
        int i = 0, j, n = A.size();
        for (j = 0; j < n; ++j)
            if (A[j] - A[i] > k * 2)
                i++;
        return j - i;
    }
};