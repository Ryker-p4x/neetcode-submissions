class Solution {
public:
    void sort(vector<int>& arr, int length) {
        if (length <= 1) return;

        int middle = length / 2;
        int left_size = middle;
        int right_size = length - middle;

        vector<int>left_array(arr.begin(), arr.begin() + left_size); 
        vector<int>right_array(arr.begin() + left_size, arr.end());

        sort(left_array, left_size);
        sort(right_array, right_size);

        int left_idx = 0, right_idx = 0, current_idx = 0;

        while (left_idx < left_size && right_idx < right_size) {
            if (left_array[left_idx] < right_array[right_idx]) {
                arr[current_idx++] = left_array[left_idx++];
            } else {
                arr[current_idx++] = right_array[right_idx++];
            }
        }

        while (left_idx < left_size) {
            arr[current_idx++] = left_array[left_idx++];
        }
        while (right_idx < right_size) {
            arr[current_idx++] = right_array[right_idx++];
        }
    }

    bool hasDuplicate(vector<int>& nums) {
        int length = nums.size();
        sort(nums, length);
        bool result = false;

        for (int i = 0; i < length - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                result = true;
                return result;
            }
        }
        return result;
    }
};