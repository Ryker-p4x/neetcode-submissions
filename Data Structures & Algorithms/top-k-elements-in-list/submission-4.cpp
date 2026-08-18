class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        
        for (int n : nums) {
            hash_map[n]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, freq] : hash_map) {
            buckets[freq].push_back(num);
        }
        vector<int> res;

        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
    }
};
