class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //sort all words
        //cat->act

        unordered_map<string, vector<string>> groups;

        for(auto str:strs){
            int arr[26]={0};
            for(auto ch:str){
                arr[ch-'a']++;
            }

            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string(arr[i]) + ",";}

            groups[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& [k, v] : groups){
            result.push_back(v);
        }
        return result;

    }
};
