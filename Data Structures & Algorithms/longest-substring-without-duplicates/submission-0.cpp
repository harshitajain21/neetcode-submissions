class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //window is unique char

        //left=0, right =0.. now increase left until you find duplicate (mantain hashset)..when you find duplicate, move left until you get window of unique characters. keep updating length.

        int l=0;
        int r=0;

        unordered_set <char> seen;

        //"xyzyy"

        int max_length=0;
        int length=0;

        for(auto c:s){
            if(seen.count(c)==0){
                seen.insert(c);
                r++;
            }
            else{
                while(seen.count(c)!=0){
                    seen.erase(s[l]);
                    l++;
                }
                seen.insert(c);
                r++;
            }
            length=r-l;
            if(length>max_length){
                max_length=length;
            }
        }
        return max_length;
    }
};
