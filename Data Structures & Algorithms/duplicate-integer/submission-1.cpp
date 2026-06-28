class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
            unordered_set <int> hs;
            for(int x:nums){
                hs.insert(x);
            }
            if(hs.size()<nums.size()){
	            return true;}
	            else{
            return false;}
        }
    };