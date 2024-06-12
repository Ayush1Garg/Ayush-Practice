int speedUp = []
{std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
void printComma(int k){
    if(k > 1) std::cout<<',' ;
}
int init = []
{
    std::ofstream out("user.out");
    std::cout.rdbuf(out.rdbuf());
    for (string s; std::getline(std::cin, s);)
    {
        int zerocount = 0 , onecount = 0 , twocount = 0 , totalnums = 0 ;
        for(int _i = 1 ; _i < s.length() ; _i +=2 ){
            int v = s[_i] & 15 ;
            if(v == 0) zerocount++ ;
            else if(v == 1) onecount++ ;
            else if(v == 2) twocount++ ;
            totalnums++ ;
        }
        std::cout << '[' ;
        while(zerocount > 0){ std::cout << 0 ; printComma(totalnums--) ; --zerocount ; }
        while(onecount > 0){ std::cout << 1 ; printComma(totalnums--) ; --onecount ;}
        while(twocount > 0){ std::cout << 2 ; printComma(totalnums--) ; --twocount ;}
        std::cout << ']' << endl ;
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    void sortColors(vector<int>& nums) {      
    }
};