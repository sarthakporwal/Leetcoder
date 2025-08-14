class Solution {
public:
    string largestGoodInteger(string arr) {
        int n = arr.size();
        if(n < 3) return "";
        int st = 0, end = 2;
        int maxi = -1;
        string ans = "";

        while(end < n){
            if (arr[st] == arr[st + 1] && arr[st + 1] == arr[st + 2]){
                int digit = arr[st] - '0';
                maxi = max(maxi, digit);
            }
            end++;
            st++;
        }
        if(maxi == -1) return "";
        else{
            int k = 3;
            while(k--){
                ans += to_string(maxi);
            }
        }
        return ans;
    }
};