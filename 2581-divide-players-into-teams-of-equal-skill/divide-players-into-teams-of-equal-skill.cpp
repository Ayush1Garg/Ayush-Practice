class Solution {
public:
    static long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long sum = 0;
        for(auto num : skill) sum += num;
        if(sum%(n/2)>0) return -1;
        long tskill = sum/(n/2), ans = 0;
        sort(skill.begin(),skill.end());
        for(int i = 0, j = n-1; i<j; i++, j--){
            if( (skill[i] + skill[j]) != tskill ) return -1;
            ans += skill[i]*skill[j];
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();