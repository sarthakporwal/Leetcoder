class Solution {
public:
    int numOfUnplacedFruits(vector<int>& frr, vector<int>& brr) {
        int ans = 0;
        vector<bool> v(frr.size(), true);

        for(int i = 0; i < frr.size(); i++){
            for(int j = 0; j < frr.size(); j++){
                if((brr[j] - frr[i]) >= 0 && v[j] == true){
                    v[j] = false;
                    break;
                }
            }
        }

        for(int i = 0; i < frr.size(); i++){
            if(v[i] == true) ans++;
        }

        return ans;
    }
};