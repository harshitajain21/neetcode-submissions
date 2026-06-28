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


        for (int i = 0; i < n; i++) {
            int left,right;
            if(i==0){
                left=1;
            }
            else{
             left  =  prefix_ltor[i-1];
            }
            if(i==n-1){
                right=1;
            }
            else{
             right = prefix_rtol[n-2-i]; }
            result.push_back(left * right);
        }
    return result;

    }
};
