class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> freq;
        int max_fr = 0;

        for(int x: nums){
            freq[x]++;
            max_fr=max(max_fr, freq[x]);
        }

        // bucket[i] = numbers with frequency i
        // that means bucket[2] will have all numbers which appear 2 times
        vector<vector<int>> bucket(max_fr + 1);

        for (auto p : freq){
            bucket[p.second].push_back(p.first);} 
            //p.first-> number and p.second -> frequency
        
        vector<int> ans;
        // Traverse from highest frequency
        for (int f = max_fr; f >= 1 && k > 0; f--) {
            for (int x : bucket[f]) {
                ans.push_back(x);
                k--;
                if (k == 0) break;
            }
        }

        return ans;
    }
};
