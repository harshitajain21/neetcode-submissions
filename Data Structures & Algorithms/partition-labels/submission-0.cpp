class Solution {
public:
    vector<int> partitionLabels(string s) {

        //hashmap
        //we have to grp letters with freq>1 ... until only letters with freq 1 is left
        //ex: xyxxyzbzbbisl.. x: 3 , y: 2, b:3, z: 2, i,s,l:1
        //soo first lets take x .. first occ of x to last occ of x.. make this window.. now check if any other letter here.. yes y also here, again check if freq(y)>1.. yes  so check if last occurence of y in string..
        //now similarly

        //NOTE: freq doesnt matter.. all that matters is LAST OCCURENCE of each char

        unordered_map<char, int> mp;  //char -> last occurence index

        for(int i=0; i<s.size();i++){
            mp[s[i]]=i;
        }

        vector<int> result;
        int curr_start=0;
        int curr_last=0;

        for(int i=0;i<s.size();i++){
            char curr_char=s[i];
            curr_last = max(curr_last, mp[s[i]]);

            if (i == curr_last) {
                result.push_back(curr_last-curr_start+1);
                curr_start=i+1;
            }

        }

        return result;        
    }
};
