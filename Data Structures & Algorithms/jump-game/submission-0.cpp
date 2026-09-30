class Solution {
public:
    bool canJump(vector<int>& nums) {

        //I don't care which exact jump I take. I only care about reaching as far as possible.

        //farthest : what's the furthest index I can reach so far

        int farthest = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i > farthest) //Wait. I'm at index i, but I can't even reach i!
                return false;

            farthest = max(farthest, i + nums[i]);
        }

        return true;
        
    }
};
