class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int max_counter = 0;
        for (int i = 0; i < nums.size(); i++) {
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
