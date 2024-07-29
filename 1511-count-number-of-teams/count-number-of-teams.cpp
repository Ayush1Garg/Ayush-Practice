struct FenwickTree{
    vector<int> BIT;
    int n;
    FenwickTree(int n): n(n), BIT(n){}

    void add(int idx, int x){
        for (; idx<n; idx=idx|(idx+1))
            BIT[idx] += x;
    }

    int sum(int idx){// prefix sum
        int ans = 0;
        for (; idx>= 0; idx=(idx&(idx+1))-1)
            ans+=BIT[idx];
        return ans;
    }

    int sum(int l, int r){
        return sum(r)-sum(l-1);
    }
};

class Solution {
public:
    static int  numTeams(vector<int>& rating) {
        const int n=rating.size();
        const int m=*max_element(rating.begin(), rating.end());

        FenwickTree L(m+1), R(m+1);

        for(int x: rating) R.add(x, 1);

        int cnt=0;
        for(int x: rating){
            R.add(x, -1);// remove x from L

            int LLess=L.sum(x-1);
            int RLess=R.sum(x-1);
            int LBigger=L.sum(x+1, m);
            int RBigger=R.sum(x+1, m);

            cnt+=LLess*RBigger+LBigger*RLess;

            L.add(x, 1);// add x to L
        }
        return cnt;
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();