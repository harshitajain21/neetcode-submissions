class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //prefix sums: 2, -1, 3, 1, 3, 4, 3, 7

        //note: if we take subarray begin to last.. then sum will be prefix[last]-prefix[start-1]
        //now we want to maximize this sum.. so max prefix[last] and min prefix[start -1].. now if prefix[start-1] is always positive.. no  need to take just take start=0.. but if prefix[start -1] is negative then we want the biggest negative on left of last
        

        //another method: kadane's algorithm
        //start a subarray. at each addition - 2 choices: extend or start fresh. so choose whichever gives u larger sum.. i.e currsum=max(currsum + nums[i], currsum )
        //at each point update currsum, and maxsum

        //for example 
        /*
        2 .. [2]
        now we have -1 or -3.. we choose -1 i.e [2,-3]
        now we have 3 or 4 .. we choose 4 so [4]
        now we have 2 or -2.. we choose 2 so [4,2]
        .... we have [4,-2,2,1,-1,4]
        */

        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
