class Solution {
   public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        for (int t = 0; t < nums.size() - k + 1; t++) {
            unordered_map<int, int> mp;
            for (int i = t ; i<k +t && i<nums.size(); i++) {
                mp[nums[i]]++;
            }
            vector<pair<int, int>> freq;
            for (auto& [key, value] : mp) {
                freq.push_back({value, key});
            }
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());

            int x_sum = 0;
            for (int i = 0; i < freq.size() && i < x; ++i) {
                x_sum += freq[i].first * freq[i].second;
            }

            res.push_back(x_sum);
        }
        return res;
    }
};