class Solution {
public:
    int rob(vector<int>& nums) {
        //m[i] = max money robbed till i houses
        //so we want m[n]
        //m[i]=max(m[i-1], m[i-2]+nums[i-1])
        //m[0]=0
        //m[1]=nums[0]

        int n = nums.size();

        vector<int> m(n + 1);

        m[0] = 0;
        m[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            m[i] = max(m[i - 1], m[i - 2] + nums[i - 1]);
        }

        return m[n];
    }

};
