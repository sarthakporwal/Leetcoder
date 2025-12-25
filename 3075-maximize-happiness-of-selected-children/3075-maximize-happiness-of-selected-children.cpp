class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        long long ans = 0;
        int cnt = 0, minus = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = (n - 1); i >= 0; i--){
            arr[i] -= minus;
            if(arr[i] < 0) ans += 0;
            else ans += arr[i];
            minus++;
            cnt++;
            if(cnt == k) break;
        }
        return ans;
    }
};