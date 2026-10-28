class Solution {
public:
    int rob(vector<int>& nums) {
        //2 cases - include first house (so do it from first house till n-1) .. 2nd case exclude first house (do from 2nd house till n)
        
        int n = nums.size();

        //case 1: include first house -> m[n-1]
        vector<int> m(n + 1);
        m[0] = 0;
        m[1] = nums[0];
        for (int i = 2; i < n; i++) {
            m[i] = max(m[i - 1], m[i - 2] + nums[i - 1]);
        }

        //case 2: exclude first house 
        vector<int> s(n);
        s[0]=0;
        //edge case: if only 1 house we cant calls nums[1]
        if(n==1) return nums[0];
        s[1]=nums[1];
        for (int i = 2; i <n; i++) {
            s[i] = max(s[i - 1], s[i - 2] + nums[i]);
        }

        return max(s[n-1],m[n-1]);

    }
};
