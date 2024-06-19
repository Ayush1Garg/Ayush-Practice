class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long max = *max_element(bloomDay.begin(), bloomDay.end());
        long long low = 0;
        int answer = -1;
        while (low <= max) {
            long long day = low + (max - low) / 2;
            int noOfBouquete = 0;
            int count = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= day) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= k) {
                    noOfBouquete++;
                    count = 0;
                }
            }
            if (noOfBouquete >= m) {
                answer = day;
                max = day - 1;
            } else if (noOfBouquete < m)
                low = day + 1;
        }
        return answer;
    }
};