class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        //we will calculate all areas, using each element as height of rectangle, i.e smallest height. so what we need to do is look left for smaller height and look right for smaller height and thats how we get our width

        int n = heights.size();

        // left[i] = index of the first bar smaller than heights[i] on the LEFT side.
        // Example:
        // heights = [2, 1, 5, 6, 2, 3]
        // For 5 (index 2), the first smaller bar on the left is 1 (index 1)
        // so left[2] = 1.
        

        // right[i] = index of the first bar smaller than heights[i] on the RIGHT side.

        // For 5 (index 2), the first smaller bar on the right is 2 (index 4)
        // so right[2] = 4.

        vector<int> right(n);
        vector<int> left(n);

        stack<int> st;


        // ============================================================
        // STEP 1: Find the first smaller bar on the LEFT
        // ============================================================

        for (int i = 0; i < n; i++) {

            // Remove bars that are >= current bar.
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) { 
                left[i] = -1;
            }
            else {
                left[i] = st.top();
            }

            // Put current bar into the stack.
            st.push(i); 
            // Stack stores indices of bars that are waiting to find a smaller bar.
// The top gives us the nearest previous bar that could be the boundary
        }


        // Empty the stack before doing the right side.
        while (!st.empty()) {
            st.pop();
        }


        // ============================================================
        // STEP 2: Find the first smaller bar on the RIGHT
        // ============================================================

        for (int i = n - 1; i >= 0; i--) {

            // Remove bars that are >= current bar.
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, there is no smaller bar on the right.
            // We use n to represent "outside the array".
            if (st.empty()) {
                right[i] = n;
            }
            else {
                // Top of stack = nearest smaller bar on the right.
                right[i] = st.top();
            }

            // Put current bar into the stack.
            st.push(i);
        }


        // ============================================================
        // STEP 3: Calculate the maximum rectangle
        // ============================================================

        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            // left[i]  = where the rectangle is blocked on the left
            // right[i] = where the rectangle is blocked on the right
            //
            // Therefore, the bars BETWEEN them are available.
            //
            // Example:
            // left = 1
            // right = 4
            //
            // indices available = 2, 3
            //
            // width = 4 - 1 - 1 = 2
            int width = right[i] - left[i] - 1;

            // Rectangle height = heights[i]
            // Rectangle width  = width
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};