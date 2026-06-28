class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> freq_s;
        unordered_map <char,int> freq_t;
        for(auto c:s){
            freq_s[c]++;
        }
        for(auto c:t){
            freq_t[c]++;
        }
        if(freq_s==freq_t){
            return true;
        }
        else{
            return false;
        }
    }
};
