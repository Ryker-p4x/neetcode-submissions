auto init = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= heights.size(); i++) {
            int currentHeight = 0;
            if (i < heights.size()) {
                currentHeight = heights[i];
            }
            
            while(!st.empty() && currentHeight < heights[st.top()]) {
                int top = st.top();
                st.pop();
                int height = heights[top];
                int width = 0;

                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                int area = width * height;

                if (maxArea < area) {
                    maxArea = area;
                }
            }

            if (i < heights.size()) {
                st.push(i);
            }
        }

        return maxArea;
    }
};
