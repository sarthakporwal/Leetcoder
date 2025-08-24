class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0;
        int zeroc = 0, res = -1;
        while(j < n){
            if(arr[j] == 0) zeroc++;
            while(zeroc > 1){
                if(arr[i] == 0) zeroc--;
                i++;
            }
            res = max(res, j - i);
            j++;
        }
        return res;
    }
};