class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);

        vector<int> prefix(n);

        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] = prefix[i] * right_product;
            right_product = right_product * nums[i];
        }

        return output;
    }
};
