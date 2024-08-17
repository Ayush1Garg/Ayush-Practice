class Solution {
public:
    static long long maxPoints(vector<vector<int>>& points) {
        const auto &ptfirst = points.front();
        const uint n = points.size(), m = ptfirst.size();
        uint64_t score[m];
        for (uint j = 0; j < m; j++)
            score[j] = ptfirst[j];
        for (uint i = 1; i < n; i++) {
            uint64_t right[m];
            right[m-1u] = score[m-1u];
            for (uint j = m - 1u; j--; )
                right[j] = max(right[j+1u], score[j] + 1u) - 1u;

            const auto &ptrow = points[i];
            uint64_t left = score[0];
            score[0] = max(left, right[0]) + ptrow[0];
            for (uint j = 1; j < m; j++) {
                left = max(left, score[j] + 1u) - 1u;
                score[j] = max(left, right[j]) + ptrow[j];
            }
        }

        return *max_element(score, score + m);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();