class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = seats.size();
        if(n==1) return abs(seats[0]-students[0]);
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans = 0;
        for(int i=0; i<n; i++) ans += abs(seats[i]-students[i]);
        return ans;
    }
};