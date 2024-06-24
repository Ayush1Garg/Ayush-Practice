#include <bits/stdc++.h> 

#define NDEBUG
#define TERRORIST

#ifdef TERRORIST
using namespace std;
using pii = pair<int,int>;
using pil = pair<int,int64_t>;
using pli = pair<int64_t,int>;
using pll = pair<int64_t,int64_t>;
#define M_PI 3.14159265358979323846
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define emp_back emplace_back
#define bitcount(x) __builtin_popcount((x))
#define mbin(val, cap) bitset<64>(val).to_string().substr(64 - cap)
#ifdef NDEBUG
    #define print(x) cout << "[ " << #x << " ]: " << x << "\n";
    #define e_ cout << "\n";
#else
    #define print(x)
    #define e_
#endif

template<typename T> ostream& operator<<(ostream &cout, vector<T> const &v);
template<typename F, typename S> ostream& operator<<(ostream &cout, pair<F, S> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename T> ostream& operator<<(ostream &cout, vector<T> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template <typename K, typename V> ostream& operator<<(ostream& cout, const map<K, V>& omp) {
    for(auto& [k, v] : omp){ cout << "(" << k << ": " << v << ")"; if(&v != &omp.rbegin()->second) cout << ", ";} return cout;
}
template<typename T> ostream& operator<<(ostream& cout, const set<T>& ost){
    cout << "{"; for(auto& v : ost){ cout << v; if(v != *ost.rbegin()) cout << ", "; } cout << "}"; return cout;
}
template<typename T, typename Cmp = less<T>>
optional<vector<T>> get_unique(vector<T>& who, bool in_place = true, Cmp compare = Cmp()){
    if(in_place){ sort(all(who), compare); who.erase(unique(all(who)), who.end()); return nullopt;}
    vector<T> ret = who; sort(all(ret), compare); ret.erase(unique(all(ret)), ret.end()); return ret;
}
mt19937_64 _GEN(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
T mrand(T begin, T end) {
    if constexpr (is_integral<T>::value){ uniform_int_distribution<T> _UNI_DIST(begin, end); return _UNI_DIST(_GEN); } 
    else if constexpr (is_floating_point<T>::value) { uniform_real_distribution<T> _UNI_DIST(begin, end); return _UNI_DIST(_GEN); }
}
int fastIO = []{ ios_base::sync_with_stdio(false); cin.tie(NULL); return 0; }();
//down0, right1, up2, left3, upleft4, downright5, upright6, downleft7, stay8
constexpr int dx[9] = {0, 1, 0, -1, -1, 1, 1, -1, 0};
constexpr int dy[9] = {1, 0, -1, 0, -1, 1, -1, 1, 0};
#endif

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int n = nums.size();

        deque<int> dq;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.front() < i)
                dq.pop_front();

            int flip = dq.size();
            if(1 & flip) nums[i] = !nums[i];
            if(nums[i]) continue;

            int until = i + k - 1;
            if(until >= n) return -1;
            ans++;
            dq.push_back(until);
        }

        return ans;
    }
};

struct Timer {
    chrono::_V2::system_clock::time_point start, end;
    chrono::duration<float> duration;
    Timer(){ start = chrono::high_resolution_clock::now(); }
    ~Timer(){
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        cout << "Time taken: " << duration.count() * 1000.0f << " ms\n"; 
    }
};

// #define MAIN_ACTIVE
#ifdef MAIN_ACTIVE
int main() {

    ifstream in("input.txt");
    ofstream out("output.txt", ios::trunc);
    out.close();
    out.open("output.txt", ios::app);
    Timer timer;

    return EXIT_SUCCESS;
}
#endif   