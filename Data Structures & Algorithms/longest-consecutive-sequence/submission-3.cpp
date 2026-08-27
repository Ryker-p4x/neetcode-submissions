class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int highest_sequence = 0;
        // Key: the number | Value: the length of its sequence
        unordered_map<int, int> hash; 

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                continue;
            }

            // Start assuming this number has a sequence length of 1
            int current_length = 1;
            
            // 1. If there's a sequence to the left, get its length
            if (hash.find(nums[i] - 1) != hash.end()) {
                current_length += hash[nums[i] - 1];
            }

            // 2. If there's a sequence to the right, add its length
            if (hash.find(nums[i] + 1) != hash.end()) {
                current_length += hash[nums[i] + 1];
            }

            // Save the length for the current number
            hash[nums[i]] = current_length;

            // 3. Update the boundaries safely using simple math
            // instead of calling .front() and .back() on a vector
            hash[nums[i] - (hash.find(nums[i] - 1) != hash.end() ? hash[nums[i] - 1] : 0)] = current_length;
            hash[nums[i] + (hash.find(nums[i] + 1) != hash.end() ? hash[nums[i] + 1] : 0)] = current_length;

            if (current_length > highest_sequence) {
                highest_sequence = current_length;
            }
        }

        return highest_sequence;
    }
};
