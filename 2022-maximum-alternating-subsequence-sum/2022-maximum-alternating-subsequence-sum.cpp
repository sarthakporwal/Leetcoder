class Solution {
public:
    long long solve(int idx, bool flag, vector<int>& arr, vector<vector<long long>>& dp){
        if(idx >= arr.size()) return 0;
        if(dp[idx][flag] != -1) return dp[idx][flag]; 

        long long nPick = solve(idx + 1, flag, arr, dp);
        long long val = arr[idx];
        if(flag == false) val = (-1 * val);

        long long pick = solve(idx + 1, !flag, arr, dp) + val;

        return dp[idx][flag] = max(pick, nPick);
    }

    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));
        return solve(0, 1, arr, dp);
    }
};