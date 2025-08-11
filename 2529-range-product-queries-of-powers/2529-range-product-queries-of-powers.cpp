class Solution {
public:
    
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        
        vector<int> ans, powers;
        int mod = 1000000007;

        for(int i = 0; i < 32; i++){
            if((n & (1 << i)) != 0){
                powers.push_back(1 << i);// 2^i
            }
        }
        sort(powers.begin(), powers.end());

        for(auto &it : q){
            int st = it[0], end = it[1];
            int pr = 1;
            for(int i = st; i <= end; i++){
                pr = (1LL *pr * powers[i]) % mod;
            }
            ans.push_back(pr % mod);
        }
        return ans;
    }
};