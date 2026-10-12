class Solution {
public:
//at each point j, check all options from j+1, j+2, ... j+nums[j].. now see nums of each of these options and choose the one with highest nums
    int jump(vector<int>& nums) {
            int jumps = 0;
                int currentEnd = 0;
                    int farthest = 0;

                        for(int i = 0; i < nums.size() - 1; i++) {

                                farthest = max(farthest, i + nums[i]);

                                        if(i == currentEnd) {
                                                    jumps++;
                                                                currentEnd = farthest;
                                                                        }
                                                                            }

                                                                                return jumps;
                                                                                }
    
};
