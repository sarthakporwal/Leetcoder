class Solution {
public:
    bool check(unordered_map<char, int> &mp, string s){
            for(auto &it : mp){
            if(it.second > 1){
                return false; 
            }
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int ans = 0;
        int maxi = 0;
        
        
        while(j < n){
            mp[s[j]]++;
            if(check(mp, s) == true){
                cout << "check1" << endl;
                ans = j - i + 1;
                maxi = max(ans, maxi);
                j++;
            }else{
                while(check(mp, s) == false){
                    cout << "notGood" << endl;
                    mp[s[i]]--;
                    i++; 
                }
                if(check(mp, s) == true){
                    cout << "check2" << endl;
                 ans = j - i + 1;
                    maxi = max(ans, maxi);
                    j++;
                }
            }
            // j++;
        }
        
        return maxi;
    }
};