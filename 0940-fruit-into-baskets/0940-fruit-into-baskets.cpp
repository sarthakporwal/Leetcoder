class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        // Continuous manner -> Subarray + maxi/mini -> Variable size sliding window
        if(n == 1) return 1;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int maxLen = 0;
        while(j < n){
            mp[fruits[j]]++;
            if(mp.size() < 2){
                if(j == (n - 1)){
                    maxLen = max(maxLen, j - i + 1);
                }
                j++;
            }
            else if(mp.size() == 2){
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
            else if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return maxLen;
    }
};