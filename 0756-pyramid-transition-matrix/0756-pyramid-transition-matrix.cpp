class Solution {
public:
    unordered_map<string, bool> dp;



    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string above){
        if(curr.length() == 1) return true;

        string key = curr + "_" + to_string(idx) + "_" + above;

        if(dp.count(key)){
            return dp[key];
        }

        if(idx == curr.length() - 1){
            return dp[key] = solve(above, mp, 0, "");
        }

        string pair = curr.substr(idx, 2);
        if(mp.find(pair) == mp.end()){
            return dp[key] = false;
        }

        for(char &it : mp[pair]){
            above.push_back(it);
            if(solve(curr, mp, idx + 1, above) == true){
                return dp[key] = true;
            }
            above.pop_back();
        }
        return dp[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        for(auto& it : allowed){
            mp[it.substr(0, 2)].push_back(it[2]);
        }

        return solve(bottom, mp, 0, "");
    }
}; 