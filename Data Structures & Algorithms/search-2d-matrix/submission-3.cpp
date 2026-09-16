class Solution {
public:
    bool binary_search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (nums[middle] == target) {
                return true;
            }

            else if (nums[middle] < target) {
                low = middle + 1;
            }

            else {
                high = middle - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;

        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (binary_search(matrix[middle], target) == true) {
                return true;
            }

            else if (target > matrix[middle][matrix[middle].size() - 1]) {
                low = middle + 1;
            }

            else {
                high = middle - 1;
            }
        }

        return false;
    }
};
