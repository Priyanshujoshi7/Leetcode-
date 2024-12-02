class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }

        vector<pair<int, int>> v;
        for(auto pairs : mp){
            v.push_back(pairs);
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){ return a.second > b.second; });
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};