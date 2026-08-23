class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

// Deque stores indices of elements in decreasing value order.
// Front = largest element in current window.
// Remove smaller elements from the back since they can never become the maximum while the current larger element exists.

    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {

        // Remove indices outside window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Maintain decreasing order
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Window formed
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }

    return ans;
    }
};
