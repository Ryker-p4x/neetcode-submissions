auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);

        output[0] = 1;
        for (int i = 1; i < n; i++) {
            output[i] = output[i - 1] * nums[i - 1];
        }

        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] = output[i] * right_product;
            right_product = right_product * nums[i];
        }

        return output;
    }
};
