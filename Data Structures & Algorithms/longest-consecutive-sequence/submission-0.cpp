class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int highest_sequence = 0;
        unordered_map<int, vector<int>> hash;

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                continue;
            }

            hash[nums[i]] = {nums[i]};
            
            if (hash.find(nums[i] - 1) != hash.end()) {
                vector<int> left_sequence = hash[nums[i] - 1];
                
                hash[nums[i]].insert(hash[nums[i]].begin(), left_sequence.begin(), left_sequence.end());
            }

            if (hash.find(nums[i] + 1) != hash.end()) {
                vector<int> right_sequence = hash[nums[i] + 1];

                hash[nums[i]].insert(hash[nums[i]].end(), right_sequence.begin(), right_sequence.end());
            }

            hash[hash[nums[i]].front()] = hash[nums[i]];
            hash[hash[nums[i]].back()] = hash[nums[i]];

            if (hash[nums[i]].size() > highest_sequence) {
                highest_sequence = hash[nums[i]].size();
            }
        }

        return highest_sequence;
    }
};
