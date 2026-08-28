static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_left = height[l];
        int max_right = height[r];

        int res = 0;

        while (l < r) {
            if (max_left <= max_right) {
                l++;
                if (height[l] < max_left) {
                    res = res + max_left - height[l];
                } else {
                    max_left = height[l];
                }
            } else {
                r--;
                if (height[r] < max_right) {
                    res = res + max_right - height[r];
                } else {
                    max_right = height[r];
                }
            }
        }
        return res;
    }
};
