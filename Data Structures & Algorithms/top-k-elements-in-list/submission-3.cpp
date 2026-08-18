class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> hash_map;
        int size = nums.size();
        int diff_nums = 0;
        
        for (int i = 0; i < size; i++) {
            hash_map[nums[i]]++;
        }

        std::vector<int> sortedKeys;
        for (const auto& [key, value] : hash_map) {
            sortedKeys.push_back(key);
        }

        std::sort(sortedKeys.begin(), sortedKeys.end(), [&](int a, int b) {
            return hash_map[a] > hash_map[b];
        });

        int idx = 0;
        for (int key : sortedKeys) {
            if (idx >= k) {
                break;
            }
            res.push_back(key);
            idx++;
        }

        return res;
    }
};
