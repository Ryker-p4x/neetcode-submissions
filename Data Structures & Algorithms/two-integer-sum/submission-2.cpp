class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_set;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash_set.find(complement) != hash_set.end()) {
                return {hash_set[complement], i};
            }
            hash_set.insert(make_pair(nums[i], i));
        }
    return {};
   }
};
