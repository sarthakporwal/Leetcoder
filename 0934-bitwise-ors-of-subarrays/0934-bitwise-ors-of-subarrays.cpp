class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> ans;

        for(int i = 0; i < n; i++){

            for(auto& it : prev){
                curr.insert(arr[i] | it);
                ans.insert(arr[i] | it);
            }
            curr.insert(arr[i]);
            ans.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return ans.size();
    }
};