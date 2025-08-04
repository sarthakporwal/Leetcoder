class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, ans = 0;

        while(j < arr.size()){
            mp[arr[j]]++;
            if(mp.size() < 3){
                ans = max(ans, j - i + 1);
            }else{
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            j++;
        }

        return ans; 
    }
};