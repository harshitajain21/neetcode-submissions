class Solution {
public:
    string minWindow(string s, string t) {

        /* answer should be min valid substring containing all letter in t and more
        so f[st]>=f[t]
        now we want min f[st] so the moment f[st]>=f[t], we stop we update
        min_length then check other windows, so to check other window, we should
        move left until window remains valid
        
        valid window:
        fst[c] >= ft[c] for every character c in t

        ---

        instead of comparing the entire frequency array every time,
        keep:
        required = number of distinct characters in t
        formed = number of distinct character requirements currently satisfied
        - so what you do is only add freq st of those char which are in t (i.e if ft[c]>=fst[c]])
          so formed ->  fst[c] == ft[c] for that character

        window is valid when:
        formed == required
        
        so lets say t="AABC" so formed=3
        check "AAAYBC" so check first A -> add in freq st, check formed- no... second A -> add in fst  check formed-yes so add 1, ... third A -> now dont add--> Y :dont add -->B add in fst, check formed - yes so add 1 --> C add in fst, check formed - yes so add 1

        */
        int ft[128] = {0};
        int required = 0;

        for(char c : t) {
            if(ft[c-'A'] == 0) {
                required++;
            }
            ft[c-'A']++;
        }

        int fst[128] = {0};

        int l = 0, r = 0;
        int formed = 0;

        int minLength = INT_MAX;
        int start = 0;

        while(r < s.size()) {

            // Add s[r]
            char c = s[r];
            fst[c-'A']++;

            if(ft[c-'A'] > 0 && ft[c-'A'] == fst[c-'A']) {
                formed++;
            }

            if(formed != required) {
                r++;
            }
            else {

                while(formed == required) {

                    // Check if current window is smaller
                    if(r-l+1 < minLength) {
                        minLength = r-l+1;
                        start = l;
                    }

                    // Remove s[l]
                    fst[s[l]-'A']--;

                    if(ft[s[l]-'A'] > 0 &&
                       fst[s[l]-'A'] < ft[s[l]-'A']) {
                        formed--;
                    }

                    l++;
                }

                r++;
            }
        }

        if(minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};