class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long int>> charge(26,vector<long long int>(26,1e9));
        for(int i=0; i<26; i++){
            charge[i][i] = 0;
        }
        for(int i=0; i<original.size(); i++){
            int from = original[i]-'a', to = changed[i]-'a';
            charge[from][to] = min(charge[from][to],(long long)cost[i]);
        }
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    if(charge[i][k]!=1e9 && charge[k][j]!=1e9){
                        charge[i][j] = min(charge[i][j], (long long)(charge[i][k] + charge[k][j]) );
                    }
                }
            }
        }
        int n = source.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(charge[source[i]-'a'][target[i]-'a']==1e9) return -1;
            ans += charge[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};