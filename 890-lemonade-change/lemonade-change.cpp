class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0, c=0;
        for(auto bill : bills){
            if(bill==5){
                a++;
            }
            else if(bill==10){
                b++;
                if(a<1) return false;
                a--;
            }
            else if(bill==20){
                c++;
                if(b>0 && a>0){
                    b--;
                    a--;
                }
                else if(a>2){
                    a -= 3;
                }
                else return false;
            }
            // cout<<a<<" "<<b<<" "<<c<<endl; 
        }
        return true;
    }
};