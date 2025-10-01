class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int ne = numExchange;
        int nb = numBottles;
        ans += nb;
        while(nb >= ne){
            int remain = nb % ne;
            int full = nb / ne;
            ans += full;
            nb = full + remain;
        }
        return ans;
    }
};