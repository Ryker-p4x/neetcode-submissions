class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int max_counter = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                counter++;
            } else {
                counter = 0;
            }
            if (counter > max_counter) {
                max_counter = counter;
            }
        }

        return max_counter;
    }
};
