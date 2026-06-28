class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //make a hashset of seen
        //now choose any element ok.. so if(element-- is not in set) then take it as start and while element++ is seen count++
        //now choose another element and check
        //update max count

        unordered_set <int> hs;

        for(int x: nums){
            hs.insert(x);
        }

        int max_count=0;

        for(int x:nums){
            int count=0;
            if(hs.count(x-1)==0){
                while(hs.count(x++)){
                    count++;
                }
                if(count>max_count){
                    max_count=count;
                }
            }
        }

        return max_count;
        

    }
};
