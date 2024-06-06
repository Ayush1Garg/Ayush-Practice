#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0, j = people.size()-1, count = 0;
        while(i<=j){
            if(people[i] + people[j] <= limit)i++;
            count++;
            j--;
        }
        return count;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();