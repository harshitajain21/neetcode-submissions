class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result;

        vector<int>prefix_ltor;
        vector<int>prefix_rtol;

        int n=nums.size();

        prefix_ltor.push_back(nums[0]);
        prefix_rtol.push_back(nums[n-1]);

        for(int i=1; i<n;i++){
            prefix_ltor.push_back(nums[i]*prefix_ltor.back());
            prefix_rtol.push_back(nums[n-i-1]*prefix_rtol.back());
        }

//left- 1,2,8,48
//right - 6,24,48,48
//r[i]=right[n-1-i]*left[i-1]


        for (int i = 0; i < n; i++) {
            int left  = (i == 0)   ? 1 : prefix_ltor[i-1];
            int right = (i == n-1) ? 1 : prefix_rtol[n-2-i]; // n-2-i excludes nums[i]
            result.push_back(left * right);
        }
    return result;

    }
};
